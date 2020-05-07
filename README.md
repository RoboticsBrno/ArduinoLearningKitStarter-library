# ArduinoLearningKitStarter-library [![Build Status](https://travis-ci.com/RoboticsBrno/ArduinoLearningKitStarter-library.svg?branch=master)](https://travis-ci.com/RoboticsBrno/ArduinoLearningKitStarter-library)

Library for the [ArduinoLearningKitStarter (ALKS) board](https://github.com/RoboticsBrno/ArduinoLearningKitStarter/) by RoboticsBrno with definition of pins and initialization of peripheries ([wiki](https://github.com/RoboticsBrno/ArduinoLearningKitStarter/wiki)).

## Available in library managers

### Arduino Library Manager

Available at the Arduino Library Manager in Arduino IDE. To access it type `CTRL` + `SHIFT` + `I` or `Sketch` -> `Include Library` -> `Manage Libraries..` and type `ALSK` or `ArduinoLearningKitStarter`. If you find the library, click on install button.

### [PlatformIO Library Manager](https://platformio.org/lib/show/1745/ArduinoLearningKitStarter/)

Available with PlatformIO - [instalation steps](https://platformio.org/lib/show/1745/ArduinoLearningKitStarter/installation). 

## Available methods

- `void setupLeds()` - sets the pins for LEDs to output
- `void setupRgbLeds()` - sets the pins for RGB LEDs to output
- `void setupButtons()` - sets the pins for buttons to input with pull-up
- `void setupPiezo()` - sets the pins for piezo to output
- `void setupAll()` - calls all previous functions

[Source code for the methods](https://github.com/RoboticsBrno/ArduinoLearningKitStarter-library/blob/master/src/ALKS.cpp)

## Available pins
Definition of pins, which are possible to use on board ALKS ([PDF with pinout on board](https://github.com/RoboticsBrno/ArduinoLearningKitStarter/blob/master/docs/pinout.pdf)).

### LEDs
- `L_R` or `LED_RED`   
- `L_G` or `LED_GREEN`   
- `L_Y` or `LED_YELLOW` 
- `L_B` or `LED_BLUE` 
- `L_RGB_R` or `LED_RGB_RED`
- `L_RGB_G` or `LED_RGB_GREEN`
- `L_RGB_B` or `LED_RGB_BLUE`

### Servos
- `S1` or `SERVO1`
- `S2` or `SERVO2`
- `S3` or `SERVO3`
- `S4` or `SERVO4`
- `S5` or `SERVO5`

### Switches/Buttons
- `SW1`
- `SW2`
- `SW3`

### Potentiometers
- `POT1`
- `POT2`

### Piezo
- `PIEZO1`
- `PIEZO2`

### Photoresistor
- `PHOTO`

### DHT11 pin 
- `DHT_PIN`

[Source code for the pins definition](https://github.com/RoboticsBrno/ArduinoLearningKitStarter-library/blob/master/src/ALKS.h)
