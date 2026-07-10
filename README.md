# Sneaky-Wheels
This is a remote controlled mini spy car designed in Onshape. I decided to build this because ive always wanted to drive an RC car with the car's POV. I like to watch and record remotely controlled terrain exploration. I finally got the chance to build this due to [Macondo's](https://macondo.hackclub.com.) funding program.

The 3d model of the casings is designed in Onshape:

[Onshape Document
](https://cad.onshape.com/documents/f87c3accc4a240ed7dab0743/w/c73ea29120acd2fcd4fea41f/e/9db8dd83f8640be167385dda?renderMode=0&uiState=6a2569f5615ba25f815471c3)

The wiring diagram (screenshot in the assembly section below) is made in EasyEDA. This is a hand-wired project.


## Bill of Materials:
| Component                                |  Quantity |  Price (PKR) |  Source                                                                                                                                      |
| ---------------------------------------- | --------- | ------------ | -------------------------------------------------------------------------------------------------------------------------------------------- |
| ESP32 NodeMCU                            |  2        |         2300 |  https://epro.pk/product/esp32-cam-mb-micro-usb-programmer-ch340g-usb-to-serial-port-board/                                                  |
| ESP32 Cam                                |  1        |         1490 |  https://epro.pk/product/esp32-cam-ov2640-board-in-pakistan/                                                                                 |
| Esp32 Cam Mb Micro Usb Programmer Ch340g |  1        |          450 |  https://epro.pk/product/esp32-cam-mb-micro-usb-programmer-ch340g-usb-to-serial-port-board/                                                  |
| DC 12V N20 Metal Gear Motor              |  4        |          680 |  https://epro.pk/product/dc-12v-n20-metal-gear-motor-mini-for-smart-car-projects/                                                            |
| Potentiometer Knob                       |  2        |           26 |  https://epro.pk/product/potentiometer-knob-rotary-swirch-cap-ac120-in-pakistan/                                                             |
| LED 5mm - White                          |  4        |            8 |  https://epro.pk/product/led-5mm-super-bright-in-pakistan/?attribute_colors=White                                                            |
| 12V 2Amp Power Supply Adapter            |  1        |          250 |  https://epro.pk/product/12v-2amp-high-quality-power-supply-adapter/                                                                         |
| 10A 12V 3S BMS                           |  1        |          230 |  https://epro.pk/product/10a-12v-lithium-battery-charger-module-bms-18650-in-pakistan/                                                       |
| Type C TP4056 Li Charging Module 1A      |  1        |           50 |  https://epro.pk/product/tp4056-lithium-battery-charging-board-1a-type-c-in-pakistan/                                                        |
| 18650 Battery Holder 1 Cell              |  1        |           40 |  https://epro.pk/product/18650-battery-holder-1-cell-in-pakistan/                                                                            |
| Potentiometer 10K                        |  2        |           60 |  https://epro.pk/product/variable-resistor-potentiometer-volume-5k-10k-50k-100k/?attribute_value=10k                                         |
| 3 Pin DC Power Jack                      |  1        |           15 |  https://epro.pk/product/3-pin-dc-power-jack-pcb-mount-female-connector-in-pakistan/                                                         |
| LM2596 Step Down Buck Converter          |  1        |          180 |  https://epro.pk/product/lm2596-dc-dc-adjustable-step-down-buck-converter/                                                                   |
| XL6009 DC to DC Boost Converter          |  1        |          220 |  https://epro.pk/product/https-epro-pk-product-xl6009-step-up-power-module-dc-dc-boost-converter-in-pakistan/                                |
| Female Header 40 Pins                    |  3        |          135 |  https://epro.pk/product/female-header-40-pins/                                                                                              |
| 2 pin C3 Connector Male Header           |  10       |           50 |  https://epro.pk/product/2-pin-c3-connector-male-header-in-pakistan-per-piece/                                                               |
| 2 Pin Molex Connector                    |  10       |          250 |  https://epro.pk/product/2-pin-molex-connector-in-pakistan/                                                                                  |
| 3 Pin Molex Connector                    |  2        |           60 |  https://epro.pk/product/3-pin-molex-connector-in-pakistan/                                                                                  |
| 6x8 Double Sided FR4 Veroboard           |  2        |          500 |  https://epro.pk/product/6x8-double-sided-fr4-veroboard-pcb-in-pakistan/                                                                     |
| Vero Board Jumper Wires                  |  1        |          380 |  https://epro.pk/product/vero-board-breadboard-jumper-wires-red-black-color/                                                                 |
| Dual-axis XY Joystick Module KY-023      |  2        |          280 |  https://epro.pk/product/dual-axis-xy-joystick-control-module-ky-023/                                                                        |
| TB6612 Dual Motor Driver Module          |  1        |          550 |  https://epro.pk/product/tb6612-drv8833-dual-motor-driver-module-1a-h-bridge-for-arduino-robotics/                                           |
| MPU6050 Analog Gyroscope Sensor 3 Axis   |  1        |          490 |  https://epro.pk/product/mpu6050-gy-521-3-axis-analog-gyroscope-sensor-in-pakistan/                                                          |
| 0.8mm 2.5ft Soldering Wire               |  2        |           60 |  https://epro.pk/product/0-8mm-2-5ft-soldering-wire-in-pakistan/                                                                             |
| 18650 Li-ion Battery Cell                |  4        |         1200 |  https://epro.pk/product/inr18650-li-ion-lithium-battery-cell-3-7v-high-capacity-power-cell/                                                 |
| Push Button Switch SMD                   |  4        |           60 |  https://epro.pk/product/push-button-switch-smd/                                                                                             |
| Female to Female Jumper Wires 20cm       |  1        |          190 |  https://epro.pk/product/female-to-female-jumper-wires-30cm-40-pin-in-pakistan/                                                              |
| 2.5mm Male Header Pins - 40 Pins         |  1        |           20 |  https://epro.pk/product/male-header-pins-40-pins/                                                                                           |
| 25v 1000 uF Electrolytic Capacitor       |  2        |           50 |  https://epro.pk/product/radial-electrolytic-1000uf-capacitor-in-pakistan/?attribute_voltage=25V                                             |
| C1815 Transistor NPN                     |  2        |           10 |  https://epro.pk/product/c1815-transistor-npn-transistor-price-in-pakistan/                                                                  |
| 3mm Heat Shrink Tube                     |  1        |           28 |  https://epro.pk/product/16mm-to-20mm-heat-shrink-tube-shrinkable-tubing-cable-sleeve-wrap-wire-meter-in-pakistan/?attribute_size=3mm        |
| 7mm Heat Shrink Tube                     |  1        |           36 |  https://epro.pk/product/16mm-to-20mm-heat-shrink-tube-shrinkable-tubing-cable-sleeve-wrap-wire-meter-in-pakistan/?attribute_size=7mm        |
| 20pcs 1/4W 1k ohm resistor               |  1        |          225 |  https://www.daraz.pk//products/i286672446-s1545954955.html?spm=a2o42.cart.0.0.35ca7d68pdk6Xv&urlFlag=true&tradePath=%2CcartPriceDrop%2Ccart |
| 20pcs 1/4W 100 ohm resistor              |  1        |          230 |  https://www.daraz.pk//products/i102804008-s1248682627.html?spm=a2o42.cart.0.0.35ca7d68Ioxqfz&urlFlag=true&tradePath=%2CcartPriceDrop%2Ccart |
| Car Wheel 43mm for N20 DC Gear Motor     |  4        |         1240 |  https://www.daraz.pk//products/i17559537-s329887429.html?spm=a2o42.cart.0.0.35ca7d68Ioxqfz&urlFlag=true&tradePath=%2CcartPriceDrop%2Ccart   |
| M2 screws                                |  18       |           70 |  Any local hardware store                                                                                                                    |
|                                          |  Total    |        12050 |                                                                                                                                              |

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

---
