// DisplayController.c

#include "WProgram.h"
#include <DisplayController.h>
using namespace std;

#define RED_PIN 5
#define YELLOW_PIN 4
#define GREEN_PIN 3
#define RED 2
#define YELLOW 1
#define GREEN 0

void DisplayController::setHigh(DisplayColor displayColor) {
  digitalWrite(RED_PIN, (displayColor == RED) ? HIGH : LOW);
  digitalWrite(YELLOW_PIN, (displayColor == YELLOW) ? HIGH : LOW);
  digitalWrite(GREEN_PIN, (displayColor == GREEN) ? HIGH : LOW);
}

DisplayController::DisplayController(char displayName[]) {
  strcpy(displayName, _displayName);
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void DisplayController::setDisplayColor(DisplayColor displayColor) {
  _displayColor = displayColor;
  setHigh(displayColor);
}

void DisplayController::onPressReserveOrExtend() {
  // TODO 
}

void DisplayController::onPressCancel() {
  // TODO
}

