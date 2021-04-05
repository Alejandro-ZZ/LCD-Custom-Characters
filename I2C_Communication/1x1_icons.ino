#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*
 * The following lines are needed because early versions (pre 1.0) 
 * had a Serial method "print" which allowed binary when used
 * with the qualifier BYTE, but this has now been superseded
 * by the "write" method.
 */
#if defined(ARDUINO) && ARDUINO >= 100
  #define printByte(args)  write(args);
#else
  #define printByte(args)  print(args,BYTE);
#endif

// Column position to display
int col = 0;

// Code array for the 8 custom icons
uint8_t icons[8][8] = { 
  {0xE, 0x1B, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F},  // Battery
  {0x1, 0x3, 0x7, 0x1F, 0x1F, 0x7, 0x3, 0x1},       // Speaker
  {0x1, 0x3, 0x5, 0x9, 0xB, 0xB, 0x18, 0x18},       // Music note
  {0xA, 0xA, 0x1F, 0x11, 0x11, 0xE, 0x4, 0x4},      // Plug
  {0x4, 0xE, 0xE, 0xE, 0x1F, 0x0, 0x4, 0x0},        // Bell
  {0x0, 0xA, 0x1F, 0x1F, 0xE, 0x4, 0x0, 0x0},       // Heart
  {0xE, 0x11, 0x11, 0x1F, 0x1B, 0x1B, 0x1F, 0x0},   // Padlock
  {0x0, 0xE, 0x15, 0x1B, 0xE, 0xE, 0x0, 0x0},       // Skull
};                           

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();

  // Create custom characters (8 characters max)
  for (int i = 0; i < sizeof(icons) / 8; i++) {
    lcd.createChar(i, icons[i]);
  }

  lcd.home();
  lcd.print("LCD Custom icons");
  lcd.setCursor(0,1);   // (col, row)
  
  // Print LCD custom characters
  for (int i = 0; i < 8; i++) {
    lcd.setCursor(col,1);
    lcd.printByte(i);
    col += 2;
  }

}

void loop()
{

}
