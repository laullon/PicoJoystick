#include <Arduino.h>
#include <PicoGamepad.h>

PicoGamepad gamepad;

const int Led = 25;

auto ledState = false;
auto count = 0;

void setup()
{
  gamepad.send_update();

  pinMode(Led, OUTPUT);

  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);

  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
}

void loop()
{
  digitalWrite(Led, ledState);
  ledState = !ledState;

  gamepad.SetButton(0, !digitalRead(10));
  gamepad.SetButton(1, !digitalRead(11));
  gamepad.SetButton(2, !digitalRead(12));
  gamepad.SetButton(3, !digitalRead(13));
  gamepad.SetButton(4, !digitalRead(14));
  gamepad.SetButton(5, !digitalRead(15));

  auto x = 1 + !digitalRead(9) - !digitalRead(8);
  auto y = 1 + !digitalRead(7) - !digitalRead(6);
  gamepad.SetX(map(x, 0, 2, 0, 512));
  gamepad.SetY(map(y, 0, 2, 0, 512));

  Serial.println(map(2, 0, 2, 0, 2047), HEX);

  gamepad.send_update();

  delay(1 / 10);
}