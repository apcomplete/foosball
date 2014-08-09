#include <Logging.h>

const int player1ButtonPin = 2;
const int player2ButtonPin = 3;

const int player1LEDPin = 12;
const int player2LEDPin = 13;

int previousButton1State, previousButton2State;
int button1State, button2State;

void setup() {
  Log.Init(LOG_LEVEL_DEBUG, 38400L);

  //set up player button pins
  pinMode(player1ButtonPin, INPUT);
  pinMode(player2ButtonPin, INPUT);
  
  //set up player led pins
  pinMode(player1LEDPin, OUTPUT);
  pinMode(player2LEDPin, OUTPUT);
}

void scoreGoal(int playerNumber) {
  int ledPin = playerNumber == player1ButtonPin ? player1LEDPin : player2LEDPin;
  digitalWrite(ledPin, digitalRead(ledPin) == HIGH ? LOW : HIGH);
}

void loop() {
  
  int currentPlayerPin = player1ButtonPin;
  
  while(true) {
    currentPlayerPin = currentPlayerPin == player1ButtonPin ? player2ButtonPin : player1ButtonPin;
    if(digitalRead(currentPlayerPin) == LOW) {
      break;
    }
    delay(10);
  }
  
  int currentState;
  
  do {
    currentState = digitalRead(player1LEDPin);
    delay(10);
  } while(digitalRead(currentPlayerPin) != HIGH);
  
  scoreGoal(currentPlayerPin);
}
