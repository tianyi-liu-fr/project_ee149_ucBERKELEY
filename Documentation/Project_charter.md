# Vision++
Team: Enrique Flores Medina, Tianyi Liu.

EECS 149/249A Project Charter, Fall, 2022

# Project Goal
This project will develop a glove that enables blind people to read, by turning (almost) any text they
encounter into speech.

# Project Approach
The project will convert any text into speech as described by a deterministic state machine that receives
multiple sensor inputs. One of these inputs will trigger a camera, which will take a picture and send it to a
computer. Then, the computer will read the text in the received image, and convert it into speech that can
be heard with either headphones or a speaker.

# Resources
Our plan is to use a microcontroller (SparkFun ESP32 Thing - DEV-13907) as the main distributor
between the embedded camera and the computer. The picture taken by the embedded camera will be
transferred wirelessly with BLE or WIFI. Then, using MATLAB’s OCR function, the text will be
extracted from the picture. Finally, the text will be turned into speech using MATLAB’s audio toolbox.
With regards to the embedded camera that will be used for the project, the first option would be the
ESP32-CAM WiFi Bluetooth Camera Module Development Board With Camera (D111), since it is the
most hardware friendly for the ESP32 board.

The first goal is the transferring of images from the microcontroller via WIFI/BLE. By pushing a button
(from the hardware inventory), the microcontroller should instruct the camera to take a picture, and send
it. The second goal is to use MATLAB to read and speak out all the text from the picture (from the
hardware inventory). Finally, the third goal would be the addition of an ultrasonic sensor (from the
hardware inventory) to instruct the user on a proper distance to take the picture from, but this is not the
main focus. The state machine would take, then, the ultrasonic sensor measurements and the button as
inputs.


# Schedule
● October 21: Project Proposal (this document) and creation of Github repository

● October 31: Architecture drawing (state machine), finalize the hardware list with GSI approval

● November 6: Milestone 1

● November 14: Reliable MATLAB script to read text from images taken with the embedded
camera and turn it into speech. Add a light source to illuminate the text every time the photo is
taken. Decide on the protocol to send the picture from the ESP32 to the computer.

● November 21: Midterm 2

● November 22: Prepare Milestone 2 and code to send the image from the microcontroller to the
computer.

● November 23: Milestone 2

● November 28 - December 2: Milestone 2 Meetings

● December 7: Finalize details, if there is extra time:
  1. Add ultrasonic sensor measurements to determine how far the user has to be from the text
to take the image properly.
  2. Create an app to hear the speech on the phone

● December 15: Project Poster/Demo Expo

● December 16: Peer Evaluations, Project report

# Risk and Feasibility
There are many unknowns. First, by sending the image from the microcontroller to the computer, some
packets could be lost. Therefore, the image could lose quality which would significantly reduce our ability
to detect the text in it. To deal with this, a comparison between the reliability of the image transmission
between BLE and serial bus could be taken. Another potential issue could be the latency from the trigger
of the camera to the speech, which could make the functionality of the product inefficient. If the system
consumes a lot of power, and the hardware components are not ergonomic for the user, the experience
would also be worsened.
