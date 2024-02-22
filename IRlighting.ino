#include <Arduino.h>
#include <M5Unified.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

enum modes {
  darken,
  brighten,
  sleepTimer,
  allOn,
  allOff,
  nightLight
}

const uint16_t IrLed = 9;  // GPIO pin.

uint16_t rawData[115];  // The signal.
uint8_t setupFlag = 1;  // Check the mode was changed. Case changed, it has 1.
enum modes mode;

auto cfg = M5.config();

IRsend irsend(IrLed);  // Set the pin to be used to sending the signal.

void setup() {
  M5.begin(cfg);
  irsend.begin();

  M5.Display.setCursor(0, 5);
  M5.Display.setTextSize(3);
  M5.Display.print("MODE:");

  mode = darken;
}

void loop() {

}