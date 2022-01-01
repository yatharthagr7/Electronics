#include <Servo.h>
int reading = 0;
Servo servo_11;
void setup()
{
 pinMode(12, INPUT);
 pinMode(A0, INPUT);
 pinMode(10, OUTPUT);
 servo_11.attach(11, 500, 2500);
 pinMode(A1, INPUT);
}
void loop()
{
 if (digitalRead(12) == 0) {
 reading = analogRead(A0);
 analogWrite(10, (reading * 0.18));
 servo_11.write((reading * 0.25));
 } else {
 reading = analogRead(A1);
 analogWrite(10, (reading * 0.75 - 15.09));
 servo_11.write((reading * 0.53 - 10.65));
 }
 delay(10); // Delay a little bit to improve simulation performance
}
