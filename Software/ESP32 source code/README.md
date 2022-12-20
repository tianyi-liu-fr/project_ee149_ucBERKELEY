# Code to capture and upload images to Google Drive
A template source code to upload images to Google Drive using the ESP32-CAM board, found in the folder ESP32_GoogleDrive, was extracted from https://www.electroniclinic.com/esp32-cam-send-images-to-google-drive-iot-security-camera/. Copyright (c) 2022 Engr Fahad.

Three external libraries are used in the source code:
1. "esp_camera.h", which is the ESP32 camera driver. Copyright (c) 2015-2016 Espressif Systems (Shanghai) PTE LTD. License: https://github.com/espressif/esp32-camera
2. "Base64.h", used to encode binary into base64 strings. Copyright (c) 2013 Adam Rudd. License: https://github.com/adamvr/arduino-base64 
3. "soc.h", used to disable the brownout detector, which creates restrictions due to low power supply. Copyright (c) 2010-2022 SPDX-FileCopyrightText Espressif Systems (Shanghai) CO LTD. License: https://github.com/espressif/esp-idf/blob/master/components/soc/esp32/include/soc/soc.h

Furthermore, Arduino core for ESP32 was installed in the Arduino IDE, from https://github.com/espressif/arduino-esp32. The following URL https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json was added as a board manager to do so. Copyright (C) 1991, 1999 Free Software Foundation, Inc.

# Modifications to the original code
The original template source code sends a notification when the image is uploaded using Line Notify. This part was removed, since it was not necessary for the purposes of the project. Comments on the relevance of each line of code were added. The original code sends an image to Google Drive periodically using a delay in the main loop function. A GPIO pin set as an input was added to use a button as the trigger to send images. Furthermore, the number of frames that can be stored in the camera's buffer was reduced from 2 to 1, preventing the uploading of images that were not sent in previous triggerings of the button.

# Google Apps Script
A javascript Google Apps Script, which helps to provide credential authentication and upload images to specific Google Drive folders, was deployed. The deployment ID is used in the source code for the ESP32-CAM board. The template for the Google Apps Script was also extracted from https://www.electroniclinic.com/esp32-cam-send-images-to-google-drive-iot-security-camera/. Copyright (c) 2022 Engr Fahad. The notification with Line Notify was eliminated from the script.
