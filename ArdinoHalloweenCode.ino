//Full code
#include <Arduino.h>

#define LASER_RECEIVER_PIN 10
#define LED 7
#define relay1 3
#define relay2 4
#define relay3 12

void setup() {
  Serial.begin(9600);

  pinMode(LASER_RECEIVER_PIN, INPUT);  
  pinMode(LED, OUTPUT);  
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  
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
    delay(120*1000);  // Delay for 2 min           
  }
  else{
    digitalWrite(LED, HIGH); 
  }
}
