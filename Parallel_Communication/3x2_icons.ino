// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Delay time when showing the icons
#define time_ms 5000

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

void setup() {
  // initialize LCD and set up the number of columns and rows:
  lcd.begin(16, 2);

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
  lcd.setCursor(4, 0);
  lcd.print("    Like    ");
  lcd.setCursor(4, 1);
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
  lcd.setCursor(4, 0);
  lcd.print("12V Battery ");
  lcd.setCursor(4, 1);
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
  lcd.setCursor(4, 0);
  lcd.print("AlejandroZZ ");
  lcd.setCursor(4, 1);
  lcd.print(" Character  ");

}

void loop() {
}

// Display the 6 characters to create the icon
void printIcon(){
  
  // set the cursor to the top left
  lcd.setCursor(0, 0);
  
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));

  lcd.setCursor(0,1);

  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.write(byte(5));
}
