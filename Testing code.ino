//Full code
#include <Arduino.h>

#define LASER_RECEIVER_PIN 53
#define LED 51

void setup() {
  Serial.begin(9600);

  pinMode(LASER_RECEIVER_PIN, INPUT);  
  pinMode(LED, OUTPUT);  
}
void loop() {
  int laserValue = digitalRead(LASER_RECEIVER_PIN);
  Serial.print(laserValue);
  if (laserValue == HIGH) {
      digitalWrite(LED, LOW); 
      Serial.print("1");           
  }
  else{
    digitalWrite(LED, HIGH); 
    Serial.print("0");
  }
}
