# Creation of custom characters for an LCD display

Code examples for creating custom icons with an LCD and Arduino using parallel or I2C communication. The icons are created with an Excel file that allows you to create them with a size of 1 to 6 characters.

## I2C_communication

--> Examples using serial communication with the `<LiquidCrystal_I2C.h>` and `<Wire.h>` libraries. Conections:

| Arduino Uno | LCD display |
|:-----------:|:-----------:|
|      5V     |     VCC     |
|     GND     |     GND     |
|  SDA or A4  |     SDA     |
|  SCL or A5  |     SCL     |
