# EECS149/249 Vision++ project
[Logo](Logo - Black.png)
Project developed by Enrique Flores Medina and Tianyi Liu, as conceptualized by PhD Prabal Dutta.

Vision++ is a glove designed to empower low vision people, by turning any readable text into speech. By pressing a button, the glove captures an image. If it contains any text, it is automatically turned into speech through a smartphone app.

# Hardware
The hardware folder contains the files used to design a PCB and an enclosure. The ESP32-CAM development board was used, and a PCB and enclosure were designed to adjust to its capabilities.

# Software
The software folder contains the source code for the ESP32-CAM, which allows it to capture and upload images to a cloud server with the press of a button. It also contains two python scripts: one downloads the images uploaded by the ESP32-CAM to the cloud server, and another one extracts the text detected in those images. Finally, the Smartphone App folder contains the file used to develop the app that turns the text into speech.

# Documentation
The documentation folder includes the project proposal and two milestones, showing how the project started, how it progressed, and how it 
