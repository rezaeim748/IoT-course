// #include <LiquidCrystal.h>
#include <Keypad.h>
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

void sendTime(){
  Serial.print(expression);
  delay(500);
}
void sendSnooze(){
  Serial.print("snooze");
  delay(500);
}
void sendStop(){
  Serial.print("stop");
  delay(500);
}

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}


void loop(){
  char key = keypad.getKey();
  if(key){
    if(key == '#'){
      Serial1.println();
      Serial1.println("time sent");
      sendTime();
    }
    else if(key == '+'){
      Serial1.println('+');
      sendSnooze();
    }
    else if(key == '/'){
      Serial1.println('/');
      sendStop();
    }
    else{
      Serial1.print(key);
      expression += key;
    }
  }
}
