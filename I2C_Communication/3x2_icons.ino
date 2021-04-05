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

// Delay time when showing the icons
#define time_ms 3000

// Code map for the like icon
uint8_t hand[6][8] = { 
  {0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x2, 0xC}, 
  {0x0, 0x6, 0x9, 0x9, 0x11, 0x2, 0xF, 0x0}, 
  {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x18}, 
  {0x8, 0x8, 0x8, 0x8, 0x8, 0xE, 0x1, 0x0}, 
  {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0xF}, 
  {0x4, 0x18, 0x4, 0x18, 0x4, 0x18, 0x8, 0x10}, 
};

// Code map for the battery icon
uint8_t bat[6][8] = { 
  {0x0, 0x3, 0x4, 0x4, 0xF, 0x10, 0x10, 0x10}, 
  {0x0, 0x11, 0xA, 0xA, 0x1F, 0x0, 0x0, 0x0}, 
  {0x0, 0x8, 0x4, 0x4, 0xE, 0x1, 0x1, 0x1}, 
  {0x10, 0x13, 0x10, 0x10, 0x10, 0xF, 0x0, 0x0}, 
  {0x0, 0x11, 0x0, 0x0, 0x0, 0x1F, 0x0, 0x0}, 
  {0x11, 0x19, 0x11, 0x1, 0x1, 0xE, 0x0, 0x0}, 
};

// Code map for the AZ icon
uint8_t AZ_icon[6][8] = { 
  {0x0, 0x0, 0xF, 0x1F, 0x1F, 0x1C, 0x1B, 0x1B}, 
  {0x0, 0x0, 0x1F, 0x1F, 0x1F, 0xC, 0x17, 0x17}, 
  {0x0, 0x0, 0x1E, 0x1F, 0x1F, 0x3, 0x1B, 0x17}, 
  {0x1B, 0x18, 0x1B, 0x1B, 0x1F, 0x1F, 0xF, 0x0}, 
  {0x17, 0x6, 0x15, 0x14, 0x1F, 0x1F, 0x1D, 0x0}, 
  {0xF, 0x1F, 0x1F, 0x3, 0x1F, 0x1F, 0x1E, 0x0}, 
};                                                                            

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();

  //+---------------------------------------------------------------+
  //|                                                               |
  //|                         LIKE CHARACTER                        |
  //|                                                               |
  //+---------------------------------------------------------------+
  
  // Create hand custom character map (8 characters max)
  for (int i = 0; i < sizeof(hand) / 8; i++) {
    lcd.createChar(i, hand[i]);
  }

  // Display Icon
  printIcon();
  lcd.setCursor(4,0);
  lcd.print("    Like    ");
  lcd.setCursor(4,1);
  lcd.print(" Character  ");

  delay(time_ms);

  //+---------------------------------------------------------------+
  //|                                                               |
  //|                     12V BATTERY CHARACTER                     |
  //|                                                               |
  //+---------------------------------------------------------------+

  // Create hand custom character map (8 characters max)
  for (int i = 0; i < sizeof(bat) / 8; i++) {
    lcd.createChar(i, bat[i]);
  }

  // Display Icon
  printIcon();
  lcd.setCursor(4,0);
  lcd.print("12V Battery ");
  lcd.setCursor(4,1);
  lcd.print(" Character  ");

  delay(time_ms);

  //+---------------------------------------------------------------+
  //|                                                               |
  //|                        AZ LOGO CHARACTER                      |
  //|                                                               |
  //+---------------------------------------------------------------+

  // Create hand custom character map (max 8 characters)
  for (int i = 0; i < sizeof(AZ_icon) / 8; i++) {
    lcd.createChar(i, AZ_icon[i]);
  }

  // Display Icon
  printIcon();
  lcd.setCursor(4,0);
  lcd.print("AlejandroZZ ");
  lcd.setCursor(4,1);
  lcd.print(" Character  ");
}

// Display the 6 characters to create the icon
void printIcon(){
  
  lcd.home();
  
  lcd.printByte(0);
  lcd.printByte(1);
  lcd.printByte(2);

  lcd.setCursor(0,1);

  lcd.printByte(3);
  lcd.printByte(4);
  lcd.printByte(5); 
}


void loop()
{

}
