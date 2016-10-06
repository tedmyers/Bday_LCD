// include library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// make custom characters:
byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

void setup() {
  // initialize LCD and set up the number of columns and rows: 
  lcd.begin(16, 2);
  
  // creat new characters
  lcd.createChar(0, heart);
  lcd.createChar(1, smiley);
  lcd.createChar(2, frownie);
  lcd.createChar(3, armsDown);
  lcd.createChar(4, armsUp);
}

void walking_men(void);
void scrolling_text(void);
void final_screen(void);

void loop() 
{

  walking_men();
  lcd.clear();

  scrolling_text();

  delay(500);
  
  final_screen();

}

// Functions

void final_screen(void)
{
  uint16_t delayTime = 500;
  
  lcd.setCursor(1,0);
  lcd.print("Happy Birthday");
  lcd.setCursor(4,1);
  lcd.print("Amanda!!");

  // draw hearts
  lcd.setCursor(2,1);
  lcd.write(byte(0));
  lcd.setCursor(13,1);
  lcd.write(byte(0));

  while (1)
  {
    lcd.setCursor(0, 1);
    // draw the little man, arms down:
    lcd.write(3);
    lcd.setCursor(15, 1);
    // draw the little man, arms up:
    lcd.write(4);
    delay(delayTime);
    lcd.setCursor(0, 1);
    // draw him arms up:
    lcd.write(4);
    lcd.setCursor(15, 1);
    // draw him arms down:
    lcd.write(3);
    delay(delayTime);
  }

}

// places man in location (x_pos, y_pos) with moving arms; moves for loops times with delay delayTime;

void walking_men(void)
{
  
  uint8_t iii;
  for (iii=0; iii<16; iii++)
  {   
    // man walking right on row 0
    lcd.setCursor(iii,0);
    if (iii%2)
      lcd.write(4);
    else
      lcd.write(3);

    if (iii>2)
    {
      lcd.setCursor(iii-3, 0);
      lcd.write(byte(0));
    }

    // man walking left on row 1
    lcd.setCursor(15-iii,1);
    if (iii%2)
      lcd.write(3);
    else
      lcd.write(4);

    if (iii>2)
    {
      lcd.setCursor(18-iii, 1);
      lcd.write(byte(0));
    }

    uint8_t reverse = 15-iii;
    if (reverse > 250)
      reverse = 15;

    // remove men
    if (iii>0)
      { lcd.setCursor(iii-1, 0); }
    lcd.print(" ");  
    if (iii<16)
      { lcd.setCursor(reverse+1, 1); }
    lcd.print(" ");

    delay(400); 
  }
}

void scrolling_text(void)
{
  uint16_t delayTime = 200;
  lcd.setCursor(1,0);
  lcd.print("H");
  delay(delayTime);
  lcd.print("A");
  delay(delayTime);
  lcd.print("P");
  delay(delayTime);
  lcd.print("P");
  delay(delayTime);
  lcd.print("Y");
  delay(delayTime);
  lcd.print(" ");
  delay(delayTime);
  
  lcd.print("B");
  delay(delayTime);
  lcd.print("I");
  delay(delayTime);
  lcd.print("R");
  delay(delayTime);
  lcd.print("T");
  delay(delayTime);
  lcd.print("H");
  delay(delayTime);
  lcd.print("D");
  delay(delayTime);
  lcd.print("A");
  delay(delayTime);
  lcd.print("Y");
  delay(delayTime);

  lcd.setCursor(4,1);
  lcd.print("A");
  delay(delayTime);
  lcd.print("M");
  delay(delayTime);
  lcd.print("A");
  delay(delayTime);
  lcd.print("N");
  delay(delayTime);
  lcd.print("D");
  delay(delayTime);
  lcd.print("A");
  delay(delayTime);
  lcd.print("!");
  delay(delayTime);
  lcd.print("!");
  delay(delayTime);
}
