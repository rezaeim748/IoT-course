// #include <LiquidCrystal.h>
#include <Keypad.h>

#define GREEN_LED 53
#define RED_LED 52
#define BUZZER 50

int readtimes = 0;

const uint8_t ROWS = 4;
const uint8_t COLS = 4;
char keys[ROWS][COLS] = {
  { '7', '8', '9', '/' }, 
  { '4', '5', '6', '*' },
  { '1', '2', '3', '-' },
  { '#', '0', '=', '+' }
};
uint8_t rowPins[ROWS] = { 29,28,27,26 }; // Pins connected to R1, R2, R3, R4
uint8_t colPins[COLS] = { 25,24,23,22 }; // Pins connected to C1, C2, C3, C4
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
String expression = "";

void send(){
  readtimes = readtimes + 1;
  Serial.println(expression);
  delay(5000);
}

// comment

void logic(){
  if(expression == "Hi"){
    Serial1.println("  Hi is recieved");
    digitalWrite(GREEN_LED, HIGH);
  }else{
    Serial1.print("  Hello is recieved");
    digitalWrite(RED_LED, HIGH); 
    digitalWrite(BUZZER, HIGH);
  }
  delay(3000);
}

void reset(){
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);
}


void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

}

void loop(){
  char key = keypad.getKey();
  if(key){
    delay(500);
    if(key == '#'){
      expression = "Hello";
      Serial1.print("Hello sent");
      send();
    }
  }

  reset();
  String message = Serial.readString();
  
  // probabale error in lcd reading
  if(message != "" && message != "\n" && message != NULL && readtimes == 1){
    expression = message;
    logic();
  }
  
}
