#include "Display.h"

#include "Util.h"
#include "bmp.h"

Display::Display(TFT_eSPI* tft) { this->tft = tft; }

Display::~Display() {}

void Display::setup() {
  tft->init();

  tft->setRotation(0);
  tft->fillScreen(TFT_BLACK);
  tft->setTextColor(TFT_GREEN);
  tft->setCursor(0, 0);
  tft->setTextDatum(TC_DATUM);
  tft->setTextSize(2);

  if (TFT_BL > 0) {
    pinMode(TFT_BL, OUTPUT);  // Set backlight pin to output mode
    digitalWrite(TFT_BL, TFT_BACKLIGHT_ON);
  }

  tft->drawString("OSRailway", tft->width() / 2, 0);
  tft->drawString("Control", tft->width() / 2, 16);

  tft->drawLine(0, 32, tft->width(), 32, TFT_GREEN);

  Util::espDelay(1000);
}

void Display::loop() {}