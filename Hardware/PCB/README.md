# What is in the PCB?
The PCB allows for the connection of pin 13 in the ESP32-CAM board to GND through a push button, which serves as the trigger to capture images. It also allows for the use of power supplies from 5VDC up to 35VDC, by using an L7805 5V voltage regulator and two capacitors for noise filtering. Finally, the PCB is equipped with a voltage divisor that is connected to an ADC pin in the board. If a 9VDC battery is used as the power supply, two 10kOhm resistors can be used to measure its voltage level. This last part, however, is not yet implemented in the source code. 

The images show a CAD of the PCB and of the real assembled PCB. The real assembled PCB shown in outdated.

# Libraries
Footprint for the ESP32-CAM development board as ESP32-CAM.lbr, and footprint for the L7805 voltage regulator as L7805.lbr

# Board, Schematic, and Gerbers
Files for the PCB design are shown as PCB.brd, PCB.sch, and Gerbers.zip. The pinout for the ESP32-CAM development board can be found in: https://randomnerdtutorials.com/esp32-cam-ai-thinker-pinout/ 
