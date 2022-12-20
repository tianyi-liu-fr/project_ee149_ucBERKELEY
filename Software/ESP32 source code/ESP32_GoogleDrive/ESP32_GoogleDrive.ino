// Wifi libraries
#include <WiFi.h>
#include <WiFiClientSecure.h>
// Header to disable brownout detector (restrictions due to low power supply). SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD. License: https://github.com/espressif/esp-idf/blob/master/components/soc/esp32/include/soc/soc.h 
#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"
// Header to encode binary into base64 strings. Copyright (c) 2013 Adam Rudd. License: https://github.com/adamvr/arduino-base64 
#include "Base64.h"
// Header for ESP32 camera driver. Copyright (c) 2015-2016 Espressif Systems (Shanghai) PTE LTD. License: https://github.com/espressif/esp32-camera 
#include "esp_camera.h"

// Phone's wifi connection
const char* ssid     = "Enrique's iPhone";   // Network SSID
const char* password = "12345678";           // Network password

// Button pins and initial state of button
int button = 13;
int state = LOW;

// Link to Google Apps Script that uploads the image taken to Google Drive
String myScript = "/macros/s/AKfycbxXYiwpzA570zGmZNNPbPZcG9V3fTSWX42qMTpsU6ZHQJ7r4cylNIBdsOFfoQG_rEws/exec";
// Name of folder to save the images taken
String myFoldername = "&myFoldername=Visionplusplus photos";
// The image's file name
String myFilename = "&myFilename=vision_photo.jpg";
// Variable to store the image URL
String myImage = "&myFile=";

// CAMERA_MODEL_AI_THINKER pins. 
// ESP32 board with PSRAM is required to use these pins, such as the ESP32 Wrover Module.
#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27

#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

void setup()
{
  // Set GPIO pin for button as input
  pinMode(button, INPUT);
  // Disable brownout detector to 
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);
  
  Serial.begin(115200);
  delay(10);
  
  WiFi.mode(WIFI_STA);

  // Start trying to establish connection to selected wifi network
  Serial.println("");
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);  
  
  // Attempt to connect to wifi for 10 seconds
  long int StartTime=millis();
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    if ((StartTime+10000) < millis()) break;
  } 

  Serial.println("");
  Serial.println("STAIP address: ");
  Serial.println(WiFi.localIP());
    
  Serial.println("");

  // Blink led once if the connection failed
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Reset");
    
    ledcAttachPin(4, 3);
    ledcSetup(3, 5000, 8);
    ledcWrite(3,10);
    delay(200);
    ledcWrite(3,0);
    delay(200);    
    ledcDetachPin(3);
  
    // Restart and retry to connect
    delay(1000);
    ESP.restart();
  }
  else {
  // Blink led five times if the connection succeeded
    ledcAttachPin(4, 3);
    ledcSetup(3, 5000, 8);
    for (int i=0;i<5;i++) {
      ledcWrite(3,10);
      delay(200);
      ledcWrite(3,0);
      delay(200);    
    }
    ledcDetachPin(3);      
  }

  // Configure all the ESP32 chip pins that correspond to the camera and led
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;

  // Set format to JPEG
  config.pixel_format = PIXFORMAT_JPEG;

  // Initialize with high specs to pre-allocate larger buffers
  if(psramFound()){
    // Frame size for modules with PSRAM (1600 x 1200 px)
    config.frame_size = FRAMESIZE_UXGA;
    // Image quality from 0-63. Lower number means higher quality
    config.jpeg_quality = 6; 
    // Only allocate one image in the buffer
    config.fb_count = 1;
  } else {
    // Frame size for modules with PSRAM (800 x 600 px)
    config.frame_size = FRAMESIZE_SVGA;
    // Image quality from 0-63. Lower number means higher quality
    config.jpeg_quality = 6;
    // Only allocate one image in the buffer
    config.fb_count = 1;
  }
  
  // Initialize communication with camera
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    delay(1000);
    ESP.restart();
  }

  // Drop down frame size for higher initial frame rate
  sensor_t * s = esp_camera_sensor_get();
  s->set_framesize(s, FRAMESIZE_VGA);  
}

void loop() {
  // Poll the button
  state = digitalRead(button);
    // If the button is pressed, capture and upload the image
    if (state == LOW){
      SendCapturedImage();
      delay(1000);
  }
}

String SendCapturedImage() {
  // Google Apps Script will be used to upload the image to Google Drive
  const char* myDomain = "script.google.com";
  String getAll="", getBody = "";

  // Counter of number of frames in the buffer
  int count = 0;
  
  // Set variable to store image
  camera_fb_t * fb = NULL;
  // Capture image
  fb = esp_camera_fb_get();  

  // Detect if the image was taken, by checking if it has any content
  if(!fb) {
    Serial.println("Camera capture failed");
    delay(1000);
    // Restart ESP32 if the camera did not capture the image
    ESP.restart();
    return "Camera capture failed";
  }  
  
  // Connect to Google Apps Script to upload captured image to Google Drive
  Serial.println("Connect to " + String(myDomain));
  WiFiClientSecure client_tcp;
  client_tcp.setInsecure();   
  
  // Check if the connection was succesful
  if (client_tcp.connect(myDomain, 443)) {
    Serial.println("Connection successful");

    // Set the format to jpeg for the images in the buffer
    while(count <= 2){
      char *input = (char *)fb->buf;
      char output[base64_enc_len(3)];
      String imageFile = "data:image/jpeg;base64,";
      for (int i=0;i<fb->len;i++) {
        base64_encode(output, (input++), 3);
        if (i%3==0) imageFile += urlencode(String(output));
      }

      // Input to Google Apps Script, specifying where to store the image in Google Drive
      String Data = myFoldername+myFilename+myImage;

      // Only upload the first image in the buffer, which is the first image taken
      if(count == 0) {
        client_tcp.println("POST " + myScript + " HTTP/1.1");
        client_tcp.println("Host: " + String(myDomain));
        client_tcp.println("Content-Length: " + String(Data.length()+imageFile.length()));
        client_tcp.println("Content-Type: application/x-www-form-urlencoded");
        client_tcp.println("Connection: keep-alive");
        client_tcp.println();
      }
      
      // Provide inputs to Google Apps Script
      client_tcp.print(Data);
      int Index;
      for (Index = 0; Index < imageFile.length(); Index = Index+1000) {
        client_tcp.print(imageFile.substring(Index, Index+1000));
      }

      // Increase counter
      count = count + 1;
      esp_camera_fb_return(fb);
    }
    
    // Define a 10 second timeout to upload the image
    int waitTime = 10000;   
    long startTime = millis();
    bool state = false;
    
    while ((startTime + waitTime) > millis())
    {
      // Print continuous ... in serial bus while the image is uploaded
      Serial.print(".");
      delay(100);      
      while (client_tcp.available()) 
      {
          char c = client_tcp.read();
          if (state==true) getBody += String(c);        
          if (c == '\n') 
          {
            if (getAll.length()==0) state=true; 
            getAll = "";
          } 
          else if (c != '\r')
            getAll += String(c);
          startTime = millis();
       }
       // Stop when the image is sent
       if (getBody.length()>0) break;
    }
    client_tcp.stop();
    Serial.println(getBody);
  }
  else {
    // Print in serial bus if the connection with the Google Apps Script fails or is timed out
    getBody="Connected to " + String(myDomain) + " failed.";
    Serial.println("Connected to " + String(myDomain) + " failed.");
  }
  
  return getBody;
}

// Function to encode the image URL
String urlencode(String str)
{
    String encodedString="";
    char c;
    char code0;
    char code1;
    char code2;
    for (int i =0; i < str.length(); i++){
      c=str.charAt(i);
      if (c == ' '){
        encodedString+= '+';
      } else if (isalnum(c)){
        encodedString+=c;
      } else{
        code1=(c & 0xf)+'0';
        if ((c & 0xf) >9){
            code1=(c & 0xf) - 10 + 'A';
        }
        c=(c>>4)&0xf;
        code0=c+'0';
        if (c > 9){
            code0=c - 10 + 'A';
        }
        code2='\0';
        encodedString+='%';
        encodedString+=code0;
        encodedString+=code1;
      }
      yield();
    }
    return encodedString;
}
