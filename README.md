# Creation of custom characters for an LCD display

Code examples for creating custom icons with an LCD and Arduino using parallel or I2C communication. The icons are created with an Excel file that allows you to create them with a size of 1 to 6 characters.

## I2C_communication

--> Examples using serial communication with the `<LiquidCrystal_I2C.h>` and `<Wire.h>` libraries. 

**CONECTIONS**

| Arduino Uno | LCD display |
|:-----------:|:-----------:|
|      5V     |     VCC     |
|     GND     |     GND     |
|  SDA or A4  |     SDA     |
|  SCL or A5  |     SCL     |

## Parallel_Communication

--> Examples using parallel communication with the `<LiquidCrystal.h>` library. 

**CONECTIONS**

| Arduino Uno | LCD display |
|:-----------:|:-----------:|
|    Pin 12   |      RS     |
|    Pin 11   |    Enable   |
|    Pin 5    |      D4     |
|    Pin 4    |      D5     |
|    Pin 3    |      D6     |
|    Pin 2    |      D7     |
|     GND     |     R/W     |

Aditional you have to conect a 10k potentiometer as follows:

**1.** Ends pins to +5V and GND
**2.** Wiper pin to the LCD VO pin (pin 3)
