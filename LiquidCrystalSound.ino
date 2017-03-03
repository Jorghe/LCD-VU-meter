// LiquidCristal Display used as VU meter or SVI, see Readme section for details.
// 1 audio analog input
// LCD connection are made as Arduino is using: https://www.arduino.cc/en/Tutorial/HelloWorld
// https://github.com/Jorghe/LCD-VU-meter/

#include  <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define input sonido as Analog
long salida;
int sonido=A0;

// Since the LCD may vary from 16x2 to 20x4, change these values to modify your hardware display
byte const columns = 20, rows = 4;
byte arreglo[columns];


void setup() 
{
  // Initialize lcd col and row
  lcd.begin(columns,rows);
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
if(salida==0)
  {
     lcd.setCursor(col,0);
     lcd.write(8);
     lcd.setCursor(col,1);
     lcd.write((byte)0);
  }
else if(salida==1)
   {
     lcd.setCursor(col,0);
     lcd.write(8);
     lcd.setCursor(col,1);
     lcd.write(1);
   }
else if(salida==2)
   {
     lcd.setCursor(col,0);
     lcd.write(8);
     lcd.setCursor(col,1);
     lcd.write(2);
   }
else if(salida==3)
   {
     lcd.setCursor(col,0);
     lcd.write(8);
     lcd.setCursor(col,1);
     lcd.write(3);
   }
else if(salida==4)
   {
     lcd.setCursor(col,0);
     lcd.write(8);
     lcd.setCursor(col,1);
     lcd.write(4);
   }
else if(salida==5)
   {
     lcd.setCursor(col,0);
     lcd.write(8);
     lcd.setCursor(col,1);
     lcd.write(5);
   }
else if(salida==6)
   {
    lcd.setCursor(col,0);
     lcd.write(8);
     lcd.setCursor(col,1);
     lcd.write(6);
   }
else if(salida==7)
   {
    lcd.setCursor(col,0);
     lcd.write(char(8));
     lcd.setCursor(col,1);
     lcd.write(7);
   }
else if(salida==8)
   {
    lcd.setCursor(col,0);
     lcd.write((byte)0);
     lcd.setCursor(col,1);
     lcd.write(8);
   }
else if(salida==9)
   {
    lcd.setCursor(col,0);
     lcd.write(1);
     lcd.setCursor(col,1);
     lcd.write(8);
   }
else if(salida==10)
   {
    lcd.setCursor(col,0);
     lcd.write(2);
     lcd.setCursor(col,1);
     lcd.write(8);
   }
else if(salida==11)
   {
    lcd.setCursor(col,0);
     lcd.write(3);
     lcd.setCursor(col,1);
     lcd.write(8);
   }
else if(salida==12)
   {
    lcd.setCursor(col,0);
     lcd.write(4);
     lcd.setCursor(col,1);
     lcd.write(8);
   }
else if(salida==13)
   {
    lcd.setCursor(col,0);
     lcd.write(5);
     lcd.setCursor(col,1);
     lcd.write(8);
   }
else if(salida==14)
   {
    lcd.setCursor(col,0);
     lcd.write(6);
     lcd.setCursor(col,1);
     lcd.write(8);
   }
else if(salida==15)
   {
     lcd.setCursor(col,0);
     lcd.write(7);
     lcd.setCursor(col  ,1);
     lcd.write(8);
   }

}
