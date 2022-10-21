# Project_ee149_ucBERKELEY
Project Title: Smart Reading Gloves
Team: Enrique Flores Medina, Tianyi Liu
EECS 149/249A Project Charter, Fall, 2022

#Project Goal
This project will develop a glove that will enable blind people to read, by turning (almost) any text they encounter into speech they can easily hear whenever they desire.

#Project Approach
The project will  turn any text into speech in a manner described by a deterministic state machine that receives multiple sensor inputs. One of those inputs will trigger a camera, which will take a photograph and send it wirelessly to a computer. Then, the computer will read the text in the received image, and convert it into speech that can be heard with headphones or a speaker.

#Resources
  Our plan is to use a microcontroller (website) as the main “distributor” between the embedded camera and the laptop. The picture taken by the embedded camera will be transferred via wireless(BLE) or serial bus to a computer. By using matlab functions, we read out the texts from the picture and turn into a speech that can be heard with speaker or headphone. The first step in the project will be identifying the suitable microcontroller and the embedded camera. One candidate for the microcontroller would be ESP32 Thing (https://www.sparkfun.com/products/13907). And for the camera, we would like to choose(https://vetco.net/products/esp32-cam-wifi-bluetooth-camera-module-development-board-with-camera-d111?gclid=Cj0KCQjwhsmaBhCvARIsAIbEbH74VsWX-Z6Xjfaer3dCZK9n-ZYLJnd-PrxLwZsPHceClwgUQ2JZIj4aAvSCEALw_wcB). The first goal will be to link the embedded camera to the microcontroller via wifi/bluetooth. By pushing the button, the microcontroller should receive the picture taken by the camera and send it to the computer. And the computer speak out the text read by the camera. The state machine would take as the input the button. By pushing the button, it should trigger the camera and the microcontroller should send the picture taken to the computer. 
  Here is the github source: 


#Schedule
October 21: Project Proposal (this document) + creation of github
October 31: Finish the architecture drawing (state machine), upload Github, finalize the harware-list (approved by GSI)
November 6: Milestone 1 
November 14: Push the button => take a picture and turn on the light to illuminate the text. To be familiar with the matlab function to transfer a picture into a text. Fix the protocol to send the picture from camera to computer. (BLE or serial bus)
November 21: Midterm 2 
November 22: Prepare Milestone 2 and start coding wireless or the serial bus transmission of the image from the microcontroller to the computer. And turn the text into speech in computer. 
November 23: Milestone 2 
November 28 - December 2: Milestone 2 Meetings 
December 7: Finalize details, add some features if we have time. 
Add an ultrasonic sensor to determine how far the user has to be from the text to take the image properly. 
Create an app to hear the speech from the phone
December 15 : Project Poster/Demo Expo 
December 16: Peer Evaluations, Project report

#Risk and Feasibility
There are many unknowns. By sending the image from the microcontroller to the computer, we send packets. And we could lost some packets during the transmission with BLE or serial bus. The matlab function to detect the text from a picture could lead to some significant errors in the text detection, which could translate into incorrect speech. We don’t know the latency from the trigger of the camera to the end point: the speech, which make the user uncomfortable.The system could be energivore and not ergonomic for the user.  

