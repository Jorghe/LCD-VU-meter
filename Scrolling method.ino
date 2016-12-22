// The following program creates a sequence from 0 to 9 and then from 9 to 0 and
// the number is placed in every single column and row of the display.

// The method is to use a for function to cycle every row and within the cycle is the
// second cycle to move every column.

int row=0,col=0;
int a, b;

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
  // Set number of columns and rows for the display
  lcd.begin(20, 4);

}

void loop() 
{
  //a rows
  //b columns
    
    // The first cycle to scroll every row
    // The cycle within is to scroll every single column
  for(int a=0; a<4; a++)
  {
  lcd.setCursor(b, a);
  for(int b=0; b<20; b++)
  {
    
    // Compare if cycle is a two digit number and 
    // RESET column to 0
    if(b>9)
    {
      col=19-b;
    }
     
  // Place Cursor in order and print the value of column
      lcd.setCursor(b,a);
      lcd.print(col);
      delay(400);

  // Relocate column to next value
      col++;
  }
  
  // Relocate row to next value
    row++;
  }
}
