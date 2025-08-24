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

int candidatesNum = 0;

void send(){
  Serial.print(expression);
  expression = "";
  delay(3000);
}

void setup() {
  Serial.begin(9600);
  Serial1.begin(115200);
  
}


void showCandidates(){
  for (int i = 0; i < candidatesNum; i++) {
    // Access and print each string in the list
    Serial1.print("candidate ");
    Serial1.println(i + 1);
  }
}















void loop(){
  char key = keypad.getKey();
  if(key){
    delay(500);
    if(key == '#'){
      send();
    }else{
      Serial1.print(key);
      expression += key;
    }
  }

  String message = Serial.readString();
  if (message != "" && message != "\n" && message != NULL){
    candidatesNum = message.toInt();
    showCandidates();
  }
  


  
}
