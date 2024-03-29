
#include <Ultrasonic.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // LCD arduino library
int count;
Ultrasonic ultrasonic(7,8); // (Trig PIN,Echo PIN)
bool isPersonHere;
int triggerDistanceHigh = 50;
int triggerDistanceLow = 35;
int waitingTime = 2000;

void setup() 
{
  lcd.begin(16, 2);
  count = 0;
  isPersonHere = false;
}

void loop()
{  
  lcd.clear();
  //write on first row first column
  lcd.setCursor(0, 0);
  lcd.print(count);
  lcd.print(" persons saw");
  //write on second row first column
  lcd.setCursor(0, 1);
  lcd.print("Joshfire");
 
  if(ultrasonic.Ranging(CM)<triggerDistanceLow && isPersonHere==false)
   {
     count += 1;
     isPersonHere=true;
     
     //wait 2 seconde before detecting someone
     delay(waitingTime);
   }
   
   if(ultrasonic.Ranging(CM)>triggerDistanceHigh)
   {
     isPersonHere=false;
   }
   
  delay(100);
}
