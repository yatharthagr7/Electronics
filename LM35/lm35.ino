#include<LiquidCrystal.h>
const int rs=12,en=11,d4=5,d5=4,d6=3,d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int degree;
double realdegree;
String lcdbuffer;
void setup()
{
  //pinMode(A0,INPUT);
  lcd.begin(16,2);
  realdegree=0;
  degree=0;
  lcd.print("Today's Temp. is:");
}

void loop()
{
  lcd.print("");
  degree=analogRead(0);
  realdegree=(double)degree/1024;
  realdegree*=5;
  realdegree-=0.5;
  realdegree*=100;
  lcd.setCursor(0,1);
  realdegree=(9.0/5)*(realdegree)+32;
  String output=String(realdegree)+String((char)178)+"F";
  lcd.print(output);
}
