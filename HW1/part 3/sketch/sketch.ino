#include <Keypad.h>
#include "SevSeg.h"
SevSeg sevseg1;
SevSeg sevseg2; 

// Define the keypad
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {13, 12, 11, 10}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; // Connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Define 7-segment display pins
const byte segmentPins1[] = {14, 15, 16, 17, 18, 19, 20, 21}; // A, B, C, D, E, F, G, DP
const byte segmentPins2[] = {23, 25, 27, 29, 31, 33, 35, 37}; // A, B, C, D, E, F, G, DP
const byte digitPins1[] = {A0}; // Anode pins of the 7-segment displays
const byte digitPins2[] = {A1}; // Anode pins of the 7-segment displays
const byte chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '#'};
const int sensorPin = A2;



// Define the start button pin
//const int startButtonPin = 5;

int digit1 = 0; // First digit of the timer
int digit2 = 0; // Second digit of the timer
bool counting = false;
String input = "";
int timer = 0;
bool isEnoughSun = true;








void setup() {
  // Initialize the displays
  //for (int i = 0; i < 7; i++) {
  //  pinMode(segmentPins[i], OUTPUT);
  //}
  //for (int i = 0; i < 2; i++) {
  //  pinMode(digitPins[i], OUTPUT);
  //}
  Serial.begin(9600);

  byte numDigits = 1;
  //byte digitPins[] = {4}; // Pin number connected to the common pin of the display
  //byte segmentPins[] = {13, 12, 11, 10, 9, 7, 6, 5};
  bool resistorsOnSegments = true;

  byte hardwareConfig = COMMON_ANODE; 
  sevseg1.begin(hardwareConfig, numDigits, digitPins1, segmentPins1, resistorsOnSegments);
  sevseg2.begin(hardwareConfig, numDigits, digitPins2, segmentPins2, resistorsOnSegments);
  sevseg1.setBrightness(90);
  sevseg2.setBrightness(90);
  

  
  sevseg1.setNumber(4);
  sevseg1.refreshDisplay();

  
  }

void loop() {

  char key = keypad.getKey();

  if (!counting){
  }

  bool found = false;
  for (int number = 0; number < 11; number++) {
    if (key == chars[number]){
      found = true;
    }
  }
  
  if (found and !counting and isEnoughSun){
    //Serial.println(input);
    
    input = input + key;
    Serial.println(input);
    
    int length = 0;
    for (int i = 0; input[i] != '\0'; i++) {
      length++;
    }

    if (key == '#'){
      if (length > 2){
        digit1 = input[length - 3] - '0';
        digit2 = input[length - 2] - '0';
      }
      if (length == 2){
        digit1 = 0;
        digit2 = input[length - 2] - '0';
      }
      if (length == 1){
        digit1 = 0;
        digit2 = 0;
      }
      timer = digit1 * 10 + digit2;
      input = "";
      counting = true;

    }

  }


  if (counting and isEnoughSun){
    count();
  }

  
  int sensorReading = analogRead(sensorPin);
  int sunLight = map(sensorReading, 0, 1023, 0, 255);
  if (sunLight < 20){
    isEnoughSun = false;
  }
  else{
    isEnoughSun = true;
  }

  
  


 
}




void count(){
  sevseg1.setNumber(timer / 10);
  sevseg1.refreshDisplay();
  sevseg2.setNumber(timer % 10);
  sevseg2.refreshDisplay();
  timer = timer - 1;
  delay(1000);
  if (timer == -1){
    counting = false;
  }

  
}












