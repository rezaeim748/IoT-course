

String expression = "";
String result = "";



void logic(){
  randomSeed(3055); 
  int temp = random(0, 100);
  if(temp < 50){
    Serial.print("Hi");
    delay(5000);
  }else{
    Serial.print("Hello");
    delay(5000);
  }
  delay(500);
}



void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  
}

void loop(){
      //reset();
      String message = Serial.readString();
      if(message != "" && message != "\n" && message != NULL){
        Serial1.println("Hello is recieved");
        expression = message;
    
        logic();
      }

}
