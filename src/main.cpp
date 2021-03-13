#include <Arduino.h>
#include <ct1642.h>
#include <remote_vtc_hd02.h>
#include <key_button_util.h>

bool isSetNumber = false;
enum State
{
  Run,
  SetNumber,
  SetTime
};
State stateCurrent = Run;

void setup()
{
  Serial.begin(9600);
  pinMode(16, OUTPUT);
  digitalWrite(16, LOW);
  setUpRemote(D1);
  setupCT1642(D5, D6);
}

uint64_t current_key = 0;
unsigned long intervalKey = 1000;
unsigned long lastKeyBoard = 0;

void RunSelectKey()
{

  uint64_t key = getHexButtonDown();
  if (key != current_key)
  {
    current_key = key;
  }
  if (millis() - lastKeyBoard >= intervalKey)
  {
    lastKeyBoard = millis();
    current_key = 0;
  }
  if (current_key == key)
  {
    return;
  }
  printHexButtonDown();
  switch (key)
  {
  case (uint64_t)KEY_BUTTON::TIMESHIFT:
    stateCurrent = SetNumber;
    break;

  default:
    break;
  }
}

void loop()
{

  RunSelectKey();

  if (stateCurrent == Run)
  {
    showNumber(2005);
  }
  if (stateCurrent == SetNumber)
  {
    setNumber(current_key);
  }
  current_key = 0xff;
}