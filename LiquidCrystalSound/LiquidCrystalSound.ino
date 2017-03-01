// LiquidCristal Display used as VU meter or SVI, see Readme section for details.
// 1 audio analog input

// LCD connection are made as Arduino is using: https://www.arduino.cc/en/Tutorial/HelloWorld
// Full project can be found in:
// https://github.com/Jorghe/LCD-VU-meter/

#include  <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define input sonido as Analog
long salida;
int sonido=A0;


void setup() 
{
  // Initialize lcd col and row
  lcd.begin(20,4);
}

void loop() 
{
  // Map every analog sound input and scale it to 16 segments, from 0 to 15
  salida=map(analogRead(sonido),0,700,0,15);

  // Call function from the previous mapped value 
  vumetro(salida);
  
  // For Testing purposes, the following command is used to generate a random value
  // vumetro(random(0,15));

  // Repeat this function every 500 miliseconds
  delay(500);
}




void vumetro(int salida)
{
  // Creating every character according to the corresponding byte
byte clearChar[8]= {0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000};
byte  Char0[8] = {0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b11111};
byte  Char1[8] = {0b00000,0b00000,0b00000,0b00000,0b00000,0b00000,0b11111,0b11111};
byte  Char2[8] = {0b00000,0b00000,0b00000,0b00000,0b00000,0b11111,0b11111,0b11111};
byte  Char3[8] = {0b00000,0b00000,0b00000,0b00000,0b11111,0b11111,0b11111,0b11111};
byte  Char4[8] = {0b00000,0b00000,0b00000,0b11111,0b11111,0b11111,0b11111,0b11111};
byte  Char5[8] = {0b00000,0b00000,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111};
byte  Char6[8] = {0b00000,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111};
byte  Char7[8] = {0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111,0b11111};


  // Load character to the LCD
 lcd.createChar(0, Char0);
 lcd.createChar(1, Char1);
 lcd.createChar(2, Char2);
 lcd.createChar(3, Char3);
 lcd.createChar(4, Char4);
 lcd.createChar(5, Char5);
 lcd.createChar(6, Char6);
 lcd.createChar(7, Char7);
 lcd.createChar(8, clearChar);
  
  // This tests the mapped value of salida and according to that value, the output will be 
   switch ( salida )  
   {
   case 0 : 
   {
     lcd.setCursor(4,0);
     lcd.write(8);
     lcd.setCursor(4,1);
     lcd.write((byte)0);
  }  
  break;
  case 1: 
  {
     lcd.setCursor(4,0);
     lcd.write(8);
     lcd.setCursor(4,1);
     lcd.write(1);
   }
   break;
   case 2: 
   {
     lcd.setCursor(4,0);
     lcd.write(8);
     lcd.setCursor(4,1);
     lcd.write(2);
   }
   break;
   case 3: 
   {
     lcd.setCursor(4,0);
     lcd.write(8);
     lcd.setCursor(4,1);
     lcd.write(3);
   }
   break;
   case 4:
   {
     lcd.setCursor(4,0);
     lcd.write(8);
     lcd.setCursor(4,1);
     lcd.write(4);
   }
   break;
   case 5:
   {
     lcd.setCursor(4,0);
     lcd.write(8);
     lcd.setCursor(4,1);
     lcd.write(5);
   }
   break;
   case 6:
   {
    lcd.setCursor(4,0);
     lcd.write(8);
     lcd.setCursor(4,1);
     lcd.write(6);
   }
   break;
   case 7:
   {
    lcd.setCursor(4,0);
     lcd.write(char(8));
     lcd.setCursor(4,1);
     lcd.write(7);
   }
   break;
   case 8:
  {
    lcd.setCursor(4,0);
     lcd.write((byte)0);
     lcd.setCursor(4,1);
     lcd.write(8);
   }
   break;
   case 9:
   {
    lcd.setCursor(4,0);
     lcd.write(1);
     lcd.setCursor(4,1);
     lcd.write(8);
   }
   break;
   case 10:
   {
    lcd.setCursor(4,0);
     lcd.write(2);
     lcd.setCursor(4,1);
     lcd.write(8);
   }
   break;
   case 11:
   {
    lcd.setCursor(4,0);
     lcd.write(3);
     lcd.setCursor(4,1);
     lcd.write(8);
   }
   break;
   case 12:
   {
    lcd.setCursor(4,0);
     lcd.write(4);
     lcd.setCursor(4,1);
     lcd.write(8);
   }
   break;
   case 13:
   {
    lcd.setCursor(4,0);
     lcd.write(5);
     lcd.setCursor(4,1);
     lcd.write(8);
   }
   break;
   case 14:
   {
    lcd.setCursor(4,0);
     lcd.write(6);
     lcd.setCursor(4,1);
     lcd.write(8);
   }
   break;
   case 15:
   {
     lcd.setCursor(4,0);
     lcd.write(7);
     lcd.setCursor(4,1);
     lcd.write(8);
   }
   break;
   default:
   {
     lcd.setCursor(4,0);
     lcd.write(byte(0));
     lcd.setCursor(4,1);
     lcd.write(byte(0));
    }
    break;
   }
}
