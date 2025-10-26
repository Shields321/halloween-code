//Full code
#include <Arduino.h>

#define LASER_RECEIVER_PIN 53
#define LED 51 // test LED when LED is on system is ready to run when its off system in running 
#define relay1 49 // realy 1 is 120V plug relay
#define relay2 47 // realy 2 is fog machine 
#define relay3 45 // realy 3 is low voltage witch realy

void setup() {
  Serial.begin(9600);

  pinMode(LASER_RECEIVER_PIN, INPUT);  
  pinMode(LED, OUTPUT);  
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
}
void loop() {
  int laserValue = digitalRead(LASER_RECEIVER_PIN);
  Serial.print(laserValue);
  if (laserValue == HIGH) {
      digitalWrite(LED, LOW);   
    
    // Activate the relays
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    delay(10*1000);  // Delay for 10 seconds
    digitalWrite(relay2, LOW);
    delay(5*1000);  // Delay for 5 seconds
    digitalWrite(relay1, LOW);
    digitalWrite(relay3, LOW);
    delay(120000);  // Delay for 2 min           
  }
  else{
    digitalWrite(LED, HIGH); 
  }
}
