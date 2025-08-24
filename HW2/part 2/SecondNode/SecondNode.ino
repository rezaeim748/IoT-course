
#define BUZZER 50


String expression = "";
String result = "";

int timer = 0;
bool counting = false;



void turn_Buzzer_on(){
    digitalWrite(BUZZER, HIGH);
}

void turn_Buzzer_off(){
    digitalWrite(BUZZER, LOW);
}


void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(BUZZER, OUTPUT);

}

void loop(){
      String message = Serial.readString();
      if(message != "" && message != "\n" && message != NULL){
        Serial1.println(message);
        if(message == "snooze"){
          timer = timer + 5;
          counting = true;
          turn_Buzzer_off();
        }
        else if(message == "stop"){
          counting = false;
          turn_Buzzer_off();
        }
        else{
          timer = message.toInt();
          counting = true;
          //Serial1.println(timer);
        }
        expression = message;
        
      }
      if(counting){
        count();
      }
}



void count(){
  timer = timer - 1;
  Serial1.println(timer);
  delay(1000);
  if (timer == 0){
    counting = false;
    turn_Buzzer_on();
  }
}
