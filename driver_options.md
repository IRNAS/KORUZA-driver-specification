# Koruza driver - options

Koruza driver is an additional board to [Koruza router][link1]. Its main task is to handle real-time parts of [Koruza system][link2], like stepper motors for laser beam positioning, infrared communication between two Koruza units, encoders for stepper motors, etc. 

Koruza move driver is now the separate part (PCB) which contains magnetic encoders, stepper drivers and small ATmega328p MCU for controlling the motors and reading the encoder position. It will be connected with UART communication with Koruza driver and have one additional RST signal for firmware upgrade.

Koruza driver now has to be in control of:
* IR link - slow optical link used for communication between Koruza units
* current measurement of the driver part
* communicating with Koruza router board
* communicating with Koruza move driver
* Connecting the camera to the Koruza router board (optional, only if driver has CPU)

Posibile solutions for koruza driver:
#### 1. [MCU (STM32) driver][link3]
* STM32F411RE, ARM Cortex M4
* cannot connect camera to it, camera conect to Koruza router USB2.0
* enough for everthing else
* camera cost: ? USD
* cost: ? USD

#### 2. [MCU (Arduino Zero/Uno) driver][link4]
* ATSAMD21G18, ARM Cortex M0+/8-bit AVR RISC
* cannot connect camera to it, camera conect to Koruza router USB2.0
* enough for everthing else
* camera cost: ? USD
* cost: ? USD

#### 3. [CPU (RPi zero/A+) driver][link5]
* ARM 700Mhz CPU
* has RPi camera connector
* camera cost: 20 USD
* RPi A+ cost: 20 USD

#### 4. [CPU (Allwiner - Friendly ARM) driver][link6]
* Allwinner H3, Quad-core Cortex-A7 Up to 1.2GHz
* has camera connector
* [camera][link7] cost: 20 USD
* NEO Air cost: 16 USD


The choice between **MCU + USB camera** and **CPU + module camera**.

### Options number 3. is chosen because Koruza driver will do all the Koruza necessary software, so the router board will do just the routing part.


 [link1]: https://github.com/IRNAS/KORUZA-router
 [link2]: http://koruza.net/
 [link3]: https://github.com/IRNAS/Universal-Stepper-Driver-Rpi
 [link4]: https://www.arduino.cc/en/Main/ArduinoBoardZero
 [link5]: https://www.raspberrypi.org/blog/raspberry-pi-model-a-plus-on-sale/
 [link6]: http://www.friendlyarm.com/index.php?route=product/product&path=69&product_id=151
 [link7]: http://www.friendlyarm.com/index.php?route=product/product&product_id=155

 
 
