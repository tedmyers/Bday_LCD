# Birthday LCD Code

## What is this?
This is code written for an animated "birthday card" I made for my sister. It used the HD44780 LCD and the LiquidCrystal library for Arduino. Feel free to use this to make your own birthday animation, just replace the name with your person of interest.

## Wiring
  * LCD RS pin to pin 12
  * LCD Enable pin to digital pin 11
  * LCD D4 pin 5
  * LCD D5 pin 4
  * LCD D6 pin 3
  * LCD D7 pin 2
  * LCD R/W to ground
  * 10K potentiometer:
    * ends to +5V and ground
    * wiper to LCD VO (pin 3)
    * 10K poterntiometer on A0

## Credits
This code is modified from the examples from the LiquidCrystal library; I've only slightly modified the code for my own use. Thanks to the creators of that library for making this little gift I made possible (or at least a lot easier).
