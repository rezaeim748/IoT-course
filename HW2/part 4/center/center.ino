//#include "stdio.h"
//#include "tinyexpr.h"
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

#define GREEN_LED 22
#define RED_LED 23


String expression = "";
String result = "";
int currentVoting = 0;
int candidatesNum = 0;
const int maxCandidate = 10;
int candidatesList[maxCandidate] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int candidatesVotes[maxCandidate] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool isVoting = false;
int modeNum = 1;
String modesList[] = {"1.decision", "2.create voting", "3.voting"};
String optionsList[] = {"1.create voting", "2.start voting", "3.finish voting"};
bool isOptionsShowed = false;
bool isCandidatesShowed = false;
String tempkey = "";
int vote = 0;









void setup() {
  Serial.begin(9600);
  Serial1.begin(115200);

}


void showResult(){
  int allVotes = 0;
  for (int i = 0; i < candidatesNum; i++) {
    allVotes += candidatesVotes[i];
  }
  float percent;
  Serial1.print("Poll No: ");
  for (int i = 0; i < candidatesNum; i++) {
    percent = (float(candidatesVotes[i]) / float(allVotes)) * 100;
    Serial1.print(i + 1);
    Serial1.print(":");
    Serial1.print(percent);
    Serial1.print("%, ");
  }
  Serial1.println();
  
}

void send(){
  Serial.print(candidatesNum);
  delay(3000);
}


void clearCandidates(){
  for (int i = 0; i < sizeof(candidatesList) / sizeof(candidatesList[0]); i++) {
    candidatesList[i] = 0;
    candidatesNum = 0;
    candidatesVotes[i] = 0;
  }
}

void showCandidates(){
  for (int i = 0; i < sizeof(candidatesList) / sizeof(candidatesList[0]); i++) {
    if(candidatesList[i] == 1){
      // Access and print each string in the list
      Serial1.print("candidate ");
      Serial1.println(i + 1);
    }
  }
  delay(500);
}

void showOptions(){
  Serial1.println(optionsList[0]);
  Serial1.println(optionsList[1]);
  Serial1.println(optionsList[2]);
  delay(500);
}


void loop(){
  char key = keypad.getKey();


  if(modeNum == 1){
    if(isOptionsShowed == false){
      showOptions();
      isOptionsShowed = true;
    }

    if(key == '1'){
      modeNum = 2;
      Serial1.println("lets create a voting");
      Serial1.println("for adding candidate press + button");
      Serial1.println("for completing the voting press = button");
    }

    if(key == '2'){
      Serial1.println("voting started");  
      modeNum = 3;
    }
    
  }

  if(modeNum == 2){
    if(key == '+'){
      candidatesNum = candidatesNum + 1;
      Serial1.print("candidate ");
      Serial1.print(candidatesNum);
      Serial1.println(" added");
    }
    candidatesList[candidatesNum - 1] = 1;
    if(key == '='){
      Serial1.println("voting created");
      modeNum = 1;
      isOptionsShowed = false;
      isCandidatesShowed = false;
    }
  }

  if(modeNum == 3){
    if(isCandidatesShowed == false){
      showCandidates();
      isCandidatesShowed = true;
      send();
    }
    if(key == '3'){
      Serial1.println("voting finished");  
      modeNum = 1;
      isOptionsShowed = false;
      showResult();
      clearCandidates();
    }

    
  }

  

  

  

  
      














      

      
      String message = Serial.readString();
      if(message != "" && message != "\n" && message != NULL && modeNum == 3){
        Serial1.print("your vote recieved: candidate ");
        Serial1.println(message);
        vote = message.toInt();
        candidatesVotes[vote - 1] += 1;
        
        
        //expression = message;
        //seprate();
        //logic();
      }
      
//      delay(5000);
}
