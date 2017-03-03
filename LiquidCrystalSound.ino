// LiquidCristal Display used as VU meter or SVI, see Readme section for details.
 // 1 audio analog input
 // LCD connection are made as Arduino is using: https://www.arduino.cc/en/Tutorial/HelloWorld
 // https://github.com/Jorghe/LCD-VU-meter/

#include  <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 // int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0; // This might be not required

  // Since the size of the matrix might vary, it can be a LCD of 20x4 or 16x2 and so forth
byte const columns = 20, rows = 4;
byte arreglo[columns];
volatile int randomizer;


void setup() 
{
  lcd.begin(columns, rows);
}

void loop() 
{

    // This order is required in order to maintain the past value (from right to left)
   /*
    arreglo[8] = arreglo[7];
    arreglo[7] = arreglo[6];
    arreglo[6] = arreglo[5];
    arreglo[5] = arreglo[4];
    arreglo[4] = arreglo[3];
    arreglo[3] = arreglo[2];
    arreglo[2] = arreglo[1];
    arreglo[1] = arreglo[0];
    arreglo[0] = generador();
    */
randomizer = generador();

arreglo[0] = randomizer;

printing();

    // This loops works as a method to move every element of the array to the right
    // it is important to note that these values will be assigned from right to left
    for (int i=(sizeof(arreglo) - 1); i>0; i--)
    {
      arreglo[i] = arreglo[i-1];
    }

  delay(100);

  lcd.setCursor(0,3);
  lcd.write((generador(),HEX));
  
} // Fin del loop

void printing()
{
  for (int i=0; i < 20; i++)
  {
    vumetro(arreglo[i],i);
  }
} 

// This simulates an escalated input signal from 0 to 15
int generador()
{
int  entrada = map(analogRead(A0),0,700,0,15);

  return entrada;
}



int vumetro(int character, int col)
{
  // Creación de cada una de las celdas
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
 
 /*
   lcd.setCursor(col,3);
   lcd.print(salida, HEX);
*/
}
