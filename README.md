# EECS149/249 VISION++ Project
Project developed by Enrique Flores Medina and Tianyi Liu, as conceptualized by PhD Prabal Dutta.

<img
  src="https://drive.google.com/uc?id=1Qfyw6MvRbeuS-uRAa79rVbIbS1rKRoyt"
  alt="Logo"
  title="Logo"
  style="display: centered; margin: 0 auto; max-width: 300px">
<img
  src="https://drive.google.com/uc?id=1jnsUqaHwwDnRdzSVFaa2yaIbEZksRf5S"
  alt="Device and app"
  title="Device and app"
  style="display: centered; margin: 0 auto; max-width: 500px">

Vision++ is a glove designed to empower low vision people, by turning any readable text into speech. By pressing a button, the glove captures an image. If it contains any text, it is automatically turned into speech through a smartphone app. Demonstration video: https://youtu.be/q09WU-yeQec

# Hardware
The hardware folder contains the files used to design a PCB and an enclosure. The ESP32-CAM development board was used, and a PCB and enclosure were designed to adjust to its capabilities.

# Software
The software folder contains the source code for the ESP32-CAM, which allows it to capture and upload images to a cloud server with the press of a button. It also contains two python scripts: one downloads the images uploaded by the ESP32-CAM to the cloud server, and another one extracts the text detected in those images. Finally, the Smartphone App folder contains the file used to develop the app that turns the text into speech. Additionally, there is a Finite State Machine (FSM) diagram showing the behavior of each piece of software.

# Documentation
The documentation folder includes the project proposal and two milestones, showing how the project started, how it progressed, and how it turned out in the end.
