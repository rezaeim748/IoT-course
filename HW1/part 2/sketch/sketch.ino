const int sensorPin = A0;
const int BuzzerPin = 4;
const int ledPin = 11;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  // digitalWrite(13, HIGH);
}

void loop() {
  // Read the Photoresistor sensor value
  int sensorReading = analogRead(sensorPin);

  // Adjust LED brightness based on LDRValue using PWM
  int sunLight = map(sensorReading, 0, 1023, 0, 255);
  analogWrite(ledPin, 255 - sunLight);
  //Serial.println(LEDBrightness);
  //Serial.println("---------------------------------");
  //delay(10210); 



  if(sunLight >= 252){
    digitalWrite(BuzzerPin, HIGH); // Turn on Buzzer
    delay(1000);  // Buzzer sound for 1 second
    digitalWrite(BuzzerPin, LOW); // Turn off Buzzer
    //Serial.begin(9600);
    //Serial.println("Mohammadreza Rezaei - 9831028");
    //Serial.println("---------------------------------");
    //delay(10210); 

  }
  

  delay(100); 

}
