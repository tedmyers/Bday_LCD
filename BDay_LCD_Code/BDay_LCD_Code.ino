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

void moving_man(uint8_t x_pos, uint8_t y_pos, uint16_t delayTime, uint8_t loops, bool start_state)
{
  lcd.setCursor(x_pos, y_pos);

  uint8_t iii;
  for (iii=0; iii<loops; iii++)
  { 
    lcd.setCursor(x_pos, y_pos);
    if (start_state)
      lcd.write(3); // arms down
    else
      lcd.write(4); // arms up
    
    delay(delayTime);
    lcd.setCursor(x_pos, y_pos);
    
    if (start_state)
      lcd.write(4); // arms up
    else
      lcd.write(3); // arms down
      
    delay(delayTime);
  }
}

void loop() 
{
  uint8_t y_pos = 0;
  uint8_t x_pos = 0;
  uint8_t iii;
  for (iii=0; iii<16; iii++)
  {   
    moving_man(iii,0,200,1, true);
    //moving_man(16-iii,1,200,1,true);

    lcd.setCursor(iii, 0);
    lcd.print(" ");
//    
//    lcd.setCursor(16-iii,1);
//    lcd.print(" ");

    
  }

  //moving_man(0,0,500, 10);

  delay(10000);
  final_screen();

  

}
