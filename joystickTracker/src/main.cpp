#include <Arduino.h>
#include "Z:/Arduino Projects/joystickTracker/lib/LedControl/LedControl.h"  // Change to appropriate directory

// Joystick Pins (SW is digital, X & Y are analog)
const int SW_PIN = 10;
const int X_PIN = 0;
const int Y_PIN = 1;

// LED Matrix Pins (All digital)
const int DIN_PIN = 4;
const int CS_PIN = 3;
const int CLK_PIN = 2;
LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1);

// Joystick Variables
int xPos, yPos;

// LED Matrix Variables
int xMap, yMap;

void setup() {
  // Joystick
  pinMode(SW_PIN, INPUT);
  digitalWrite(SW_PIN, HIGH);

  // LED Matrix
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {
  // Read joystick's X & Y position
  xPos = analogRead(X_PIN);
  yPos = analogRead(Y_PIN);
  
  // Map joystick position in matrix
  xMap = map(xPos, 0, 1023, 0, 7);
  yMap = map(yPos, 0, 1023, 7, 0);

  // Clear display, illuminate corresponding LED in matrix, repeat every 100ms
  lc.clearDisplay(0);
  lc.setLed(0, xMap, yMap, true);
  delay(100);
}