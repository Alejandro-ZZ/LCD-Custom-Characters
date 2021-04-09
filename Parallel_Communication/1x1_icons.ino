// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int col = 0;

// make some custom characters:
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

void setup() {
  // initialize LCD and set up the number of columns and rows:
  lcd.begin(16, 2);

  // Create custom characters map (8 characters max)
  for (int i = 0; i < sizeof(icons) / 8; i++) {
    lcd.createChar(i, icons[i]);
  }

  // set the cursor to the top left
  lcd.setCursor(0, 0);

  // Print a message to the lcd.
  lcd.print("LCD Custom icons");
  lcd.setCursor(0, 1);   // (col, row)

  // Print LCD custom characters
  for (int i = 0; i < 8; i++) {
    lcd.setCursor(col, 1);
    lcd.write(byte(i)); // when calling lcd.write() '0' must be cast as a byte
    col += 2;
  }
}

void loop() {
}
