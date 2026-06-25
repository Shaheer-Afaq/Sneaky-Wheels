# Sneaky-Wheels
This is a remote controlled mini spy car designed in Onshape. I decided to build this because ive always wanted to drive an RC car with the car's POV. I like to watch and record remotely controlled terrain exploration. I finally got the chance to build this due to [Macondo's](https://macondo.hackclub.com.) funding program.

I designed the 3d model of the casings in Onshape:

[Onshape Document
](https://cad.onshape.com/documents/f87c3accc4a240ed7dab0743/w/c73ea29120acd2fcd4fea41f/e/9db8dd83f8640be167385dda?renderMode=0&uiState=6a2569f5615ba25f815471c3)


## Components to be used:
- 2x Esp32 Node MCU as micro-controllers
- ESP-CAM for live video streaming
- 4x N20 Gear Motors for driving with 43mm rubber wheels
- TB6612 dual motor driver
- 18650 cells for power (1 Cell for remote, 3 Cell Battery for the car)
- LM2596 step-down buck converter for 12V -> 5V
- XL6009 Voltage booster to convert the 3.7v from the cell to 5v for the remote
- 10A 3S BMS for the car battery
- 12v 10A adapter for charging along with a dc power jack
- TP4056 module for remote cell
- 2x KY-023 Joystick modules
- MPU-6050 module for gyro controlling
- 2x 10KΩ Potentiometers with knobs
- 4x Push buttons (toggle)
- 2x 5mm bright white LEDs as headlights
- 2x C1815 Transistor
- 1x 1KΩ resistor, 2x 100Ω resistor
- 1000 uF capacitor - 25v
- 10x 2-pin connector pairs for motors, buck converter, LEDs and buttons
- 2x 3-pin connectors pairs for potentiometers
- 6x8 Veroboard/Protoboard
- Veroboard jumperwires
- Female-Female jumper wires for joysticks and ESP-CAM
- Female header pins for Esp32, motor driver and mpu6050
- Male header pins for potentiometers, joysticks and ESP-CAM
- 3mm and 7mm heat shrink tubes, 1 meter each (optional)
- 18x M2 screws

## Car Assembly

1. Solder wires to motors with 2-pin molex connectors.

2. Build a 3S battery by soldering the wires on the bms, (circuit shown in the schematic below)

3. Solder wires to the bms, power jack, buck converter and push button according to the schematic.Solder wires on the output of the buck converter with a 2-pin female connector

4. Fix the motors in their slots in the corners and use super glue to fix them if they are loose.

5. Solder wires to the second push button, LEDs and GND and 5V of ESP-CAM with 2pin connectors on the end

6. Fix the push buttons, power jack, LEDs and ESP-CAM in their respective slots as shown in the model.

7. Use double-sided tape to stick the battery on the bottom and the bms on the side of the battery as shown.

8. Cut a protoboard according to the dimensions shown in the top view of the car model.

9. Solder female header pins for esp32 and motor driver as shown in the top-view.

10. Solder male molex connectors on the protoboard for the motors, LEDs and one push button, anywhere on the empty space (make sure to optimize the positions according to the schematic)

11. Use screws to fix the protoboard. Plugin the esp32 and motor driver, and stick the buck converter with double sided tape.

13. Slide in the lid and screw-in M2 screws from the holes in the sides.

14. Put the wheels on each motor.

---
<img width="1113" height="639" alt="image" src="https://github.com/user-attachments/assets/cb12e507-b7dc-4f9a-a4fb-f80e8dce1dfe" />

---

<img height="300" alt="image" src="https://github.com/user-attachments/assets/5680441c-d097-4086-9e8e-fc497fe35733" />

<img height="300" alt="image" src="https://github.com/user-attachments/assets/d77bdd45-3862-47f5-ae3a-bcd84f291b28" />

### Top
<img height="300" alt="image" src="https://github.com/user-attachments/assets/3e4908ed-3768-4940-9acc-668c7fb9f240" />

### Rear
<img height="300" alt="image" src="https://github.com/user-attachments/assets/cfccaf69-ab21-4008-900c-e784760321b8" />

### Side
<img height="300" alt="image" src="https://github.com/user-attachments/assets/2ac2b6d0-b804-47ce-921b-f25d3064d59d" />

### Front
<img height="300" alt="image" src="https://github.com/user-attachments/assets/077a7de5-1445-4220-885a-76e3170051e0" />

## Remote Assembly

1. Solder wires on potentiometers with 3pin connectors and push buttons with 2pin connectors on the ends.

2. Solder wires on tp4056 and cellholder and a 2pin connector in parallel. Stick cellholder with double-sided tape.

3. Cut out a protoboard and solder female pin headers for esp32 and mpu6050, as shown in the top-view below.

4. Put female-female jumper wires on the joysticks and use M2 screws to secure them into place.

5. Fix the potentiometers, push buttons and tp-4506 in their respective slots and glue them as needed.

6. Solder other parts of connector pairs (male holder for each) on the protoboard, optimizing the position according to the schematic.

7. Secure the protoboard with a M2 screw and plugin the esp32 and mpu6050.

8. Secure the lid with 4 M2 screws, then put the joystick heads and potentiometer knobs (cut the knobs short).

---
<img width="853" height="706" alt="image" src="https://github.com/user-attachments/assets/dd32a48f-2b62-4d39-ad66-337a579c8898" />

---

<img height="300" alt="image" src="https://github.com/user-attachments/assets/86304ddb-9377-4275-8345-26b131e75946" />
<img height="300" alt="image" src="https://github.com/user-attachments/assets/62c73b5d-d189-4f2e-bd1e-75345a0e3c98" />

### Top
<img height="300" alt="image" src="https://github.com/user-attachments/assets/57eeaed4-c33a-40d9-b4af-b095293210f3" />

### Sides 
<img height="300" alt="image" src="https://github.com/user-attachments/assets/695187b9-c881-44e1-80e0-e0f9f0dda3d1" />
<img height="300" alt="image" src="https://github.com/user-attachments/assets/7478d2ce-500a-46f5-8948-0f06cc4bc357" />

