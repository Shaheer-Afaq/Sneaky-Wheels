# Sneaky-Wheels
This is a remote controlled mini spy car designed in Onshape. I decided to build this because ive always wanted to drive an RC car with the car's POV. I like to watch and record remotely controlled terrain exploration. I finally got the chance to build this due to [Forge's](https://forge.hackclub.com.) funding program.

The 3d model of the casings is designed in Onshape:

[Onshape Document
](https://cad.onshape.com/documents/f87c3accc4a240ed7dab0743/w/c73ea29120acd2fcd4fea41f/e/9db8dd83f8640be167385dda?renderMode=0&uiState=6a2569f5615ba25f815471c3)

The wiring diagram (screenshot in the assembly section below) is made in EasyEDA. This is a hand-wired project.


## Bill of Materials:
| Component                                | Quantity | Price (USD) | Source                                                                                                                                      |
|------------------------------------------|----------|-------------|---------------------------------------------------------------------------------------------------------------------------------------------|
| ESP32 NodeMCU                            | 2        | 8.3         | https://epro.pk/product/esp32-nodemcu-wifi-based-development-board/                                        |
| ESP32 Cam                                | 1        | 5.4         | https://epro.pk/product/esp32-cam-ov2640-board-in-pakistan/                                                                                 |
| Esp32 Cam Mb Micro Usb Programmer Ch340g | 1        | 1.6         | https://epro.pk/product/esp32-cam-mb-micro-usb-programmer-ch340g-usb-to-serial-port-board/                                                  |
| DC 12V N20 Metal Gear Motor              | 4        | 2.5         | https://epro.pk/product/dc-12v-n20-metal-gear-motor-mini-for-smart-car-projects/                                                            |
| Potentiometer Knob                       | 2        | 0.1         | https://epro.pk/product/potentiometer-knob-rotary-swirch-cap-ac120-in-pakistan/                                                             |
| LED 5mm - White                          | 4        | 0.03        | https://epro.pk/product/led-5mm-super-bright-in-pakistan/?attribute_colors=White                                                            |
| 12V 2Amp Power Supply Adapter            | 1        | 0.9         | https://epro.pk/product/12v-2amp-high-quality-power-supply-adapter/                                                                         |
| 10A 12V 3S BMS                           | 1        | 0.8         | https://epro.pk/product/10a-12v-lithium-battery-charger-module-bms-18650-in-pakistan/                                                       |
| Type C TP4056 Li Charging Module 1A      | 1        | 0.2         | https://epro.pk/product/tp4056-lithium-battery-charging-board-1a-type-c-in-pakistan/                                                        |
| 18650 Battery Holder 1 Cell              | 1        | 0.14        | https://epro.pk/product/18650-battery-holder-1-cell-in-pakistan/                                                                            |
| Potentiometer 10K                        | 2        | 0.22        | https://epro.pk/product/variable-resistor-potentiometer-volume-5k-10k-50k-100k/?attribute_value=10k                                         |
| 3 Pin DC Power Jack                      | 1        | 0.054       | https://epro.pk/product/3-pin-dc-power-jack-pcb-mount-female-connector-in-pakistan/                                                         |
| LM2596 Step Down Buck Converter          | 1        | 0.65        | https://epro.pk/product/lm2596-dc-dc-adjustable-step-down-buck-converter/                                                                   |
| XL6009 DC to DC Boost Converter          | 1        | 0.8         | https://epro.pk/product/https-epro-pk-product-xl6009-step-up-power-module-dc-dc-boost-converter-in-pakistan/                                |
| Female Header 40 Pins                    | 3        | 0.5         | https://epro.pk/product/female-header-40-pins/                                                                                              |
| 2 pin C3 Connector Male Header           | 10       | 0.2         | https://epro.pk/product/2-pin-c3-connector-male-header-in-pakistan-per-piece/                                                               |
| 2 Pin Molex Connector                    | 10       | 0.9         | https://epro.pk/product/2-pin-molex-connector-in-pakistan/                                                                                  |
| 3 Pin Molex Connector                    | 2        | 0.22        | https://epro.pk/product/3-pin-molex-connector-in-pakistan/                                                                                  |
| 6x8 Double Sided FR4 Veroboard           | 2        | 1.8         | https://epro.pk/product/6x8-double-sided-fr4-veroboard-pcb-in-pakistan/                                                                     |
| Vero Board Jumper Wires                  | 1        | 1.4         | https://epro.pk/product/vero-board-breadboard-jumper-wires-red-black-color/                                                                 |
| Dual-axis XY Joystick Module KY-023      | 2        | 1           | https://epro.pk/product/dual-axis-xy-joystick-control-module-ky-023/                                                                        |
| TB6612 Dual Motor Driver Module          | 1        | 2           | https://epro.pk/product/tb6612-drv8833-dual-motor-driver-module-1a-h-bridge-for-arduino-robotics/                                           |
| MPU6050 Analog Gyroscope Sensor 3 Axis   | 1        | 1.8         | https://epro.pk/product/mpu6050-gy-521-3-axis-analog-gyroscope-sensor-in-pakistan/                                                          |
| 0.8mm 2.5ft Soldering Wire               | 2        | 0.22        | https://epro.pk/product/0-8mm-2-5ft-soldering-wire-in-pakistan/                                                                             |
| 18650 Li-ion Battery Cell                | 4        | 4.3         | https://epro.pk/product/inr18650-li-ion-lithium-battery-cell-3-7v-high-capacity-power-cell/                                                 |
| Push Button Switch SMD                   | 4        | 0.2         | https://epro.pk/product/push-button-switch-smd/                                                                                             |
| Female to Female Jumper Wires 20cm       | 1        | 0.7         | https://epro.pk/product/female-to-female-jumper-wires-30cm-40-pin-in-pakistan/                                                              |
| 2.5mm Male Header Pins - 40 Pins         | 1        | 0.07        | https://epro.pk/product/male-header-pins-40-pins/                                                                                           |
| 25v 1000 uF Electrolytic Capacitor       | 2        | 0.18        | https://epro.pk/product/radial-electrolytic-1000uf-capacitor-in-pakistan/?attribute_voltage=25V                                             |
| C1815 Transistor NPN                     | 2        | 0.0036      | https://epro.pk/product/c1815-transistor-npn-transistor-price-in-pakistan/                                                                  |
| 3mm Heat Shrink Tube                     | 1        | 0.1         | https://epro.pk/product/16mm-to-20mm-heat-shrink-tube-shrinkable-tubing-cable-sleeve-wrap-wire-meter-in-pakistan/?attribute_size=3mm        |
| 7mm Heat Shrink Tube                     | 1        | 0.13        | https://epro.pk/product/16mm-to-20mm-heat-shrink-tube-shrinkable-tubing-cable-sleeve-wrap-wire-meter-in-pakistan/?attribute_size=7mm        |
| 20pcs 1/4W 1k ohm resistor               | 1        | 0.81        | https://www.daraz.pk//products/i286672446-s1545954955.html?spm=a2o42.cart.0.0.35ca7d68pdk6Xv&urlFlag=true&tradePath=%2CcartPriceDrop%2Ccart |
| 20pcs 1/4W 100 ohm resistor              | 1        | 0.83        | https://www.daraz.pk//products/i102804008-s1248682627.html?spm=a2o42.cart.0.0.35ca7d68Ioxqfz&urlFlag=true&tradePath=%2CcartPriceDrop%2Ccart |
| Car Wheel 43mm for N20 DC Gear Motor     | 4        | 4.5         | https://www.daraz.pk//products/i17559537-s329887429.html?spm=a2o42.cart.0.0.35ca7d68Ioxqfz&urlFlag=true&tradePath=%2CcartPriceDrop%2Ccart   |
| Soldering Tip                            | 1        | 1.26        | https://epro.pk/product/tni-u-soldering-iron-k-type-bit-60w/                                                                                |
| M2 screws                                | 18       | 0.25        | https://www.daraz.pk/products/m2-m25-m3-250500pcs-i1954210452.html?spm=a2a0e.searchlist.list.1.593733c5KpRiYM or any local hardware store   |
| 3D Prints                                | -        | 10          | https://printlegion.hackclub.com/                                                                                                           |
|                                          | Total    | 56          |                                                                                                                                             |
                                                                                  |

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
<img width="1101" height="603" alt="image" src="https://github.com/user-attachments/assets/d06d3082-5b07-4ed1-9c77-3b72e3bf763a" />

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

2. Solder wires on tp4056 and cellholder. Stick cellholder with double-sided tape.

3. Solder the output of tp4056 to the input of XL6009 and a 2pin connector to the output of XL6009.

3. Cut out a protoboard and solder female pin headers for esp32 and mpu6050, as shown in the top-view below.

4. Put female-female jumper wires on the joysticks and use M2 screws to secure them into place.

5. Fix the potentiometers, push buttons and tp-4506 in their respective slots and glue them as needed.

6. Solder other parts of connector pairs (male holder for each) on the protoboard, optimizing the position according to the schematic.

7. Secure the protoboard with a M2 screw and plugin the esp32 and mpu6050.

8. Secure the lid with 4 M2 screws, then put the joystick heads and potentiometer knobs (cut the knobs short).

---
<img width="633" height="520" alt="image" src="https://github.com/user-attachments/assets/826218d4-21a6-4c68-8c4c-aabb98389eed" />

---

<img height="300" alt="image" src="https://github.com/user-attachments/assets/0d03a5f9-ebdb-4440-a4e6-454d448a9ef9" />
<img height="300" alt="image" src="https://github.com/user-attachments/assets/f34acff1-4bc2-426d-97e5-337b48683d54" />

### Top
<img height="300" alt="image" src="https://github.com/user-attachments/assets/1004be86-d16d-4d78-98f6-943b8ed8b6f1" />

### Sides 

<img width="500" alt="image" src="https://github.com/user-attachments/assets/40c26539-8ef2-4742-9bcf-388cb372dcc2" />
<br>
<img width="500" alt="image" src="https://github.com/user-attachments/assets/30190723-5c1d-4c1e-af5f-6d3bc1792a2b" />

---