#include "Display.h"

#include "Util.h"

Display::Display(TFT_eSPI* tft, Mqtt* mqtt) {
  this->tft = tft;
  this->mqtt = mqtt;
}

Display::~Display() {}

void Display::setup() {
  tft->init();
  tft->setRotation(0);
  tft->fillScreen(TFT_BLACK);
  tft->setTextColor(TFT_GREEN);

  if (TFT_BL > 0) {
    pinMode(TFT_BL, OUTPUT);  // Set backlight pin to output mode
    digitalWrite(TFT_BL, TFT_BACKLIGHT_ON);
  }
  _drawList();
  _drawList();

  Util::espDelay(1000);
}

void Display::_drawList() {
  const int size = 16;

  tft->setCursor(0, 0);
  tft->setTextDatum(TC_DATUM);
  tft->setTextSize(size / 8);

  tft->drawString("OSRailway", tft->width() / 2, 0);
  tft->drawString("Control", tft->width() / 2, size);

  tft->drawLine(0, 32, tft->width(), 32, TFT_GREEN);
}

void Display::loop() {}