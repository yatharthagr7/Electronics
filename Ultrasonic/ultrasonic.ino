const int led=13;
int distance_cm;
float duration;

void setup() {
  pinMode(led, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
  
}

void loop() {
  
// transmission
  pinMode(6, OUTPUT); // defined the pin as a output
 digitalWrite(led, LOW);

 digitalWrite(6, LOW);
  delayMicroseconds(15); 
  digitalWrite(6,HIGH);
  delayMicroseconds(15);
  digitalWrite(6, LOW);// receiver

  pinMode(6, INPUT);
  
  duration=pulseIn(6,HIGH);
  
  distance_cm=(duration*0.034)/2;
  
  Serial.print(distance_cm); 
  Serial.print("cm");
  Serial.println();
  if(distance_cm<=30)
  {
    digitalWrite(led,HIGH);
    }
  else
  {
    digitalWrite(led, LOW);
    } 

  delay(10);
}
