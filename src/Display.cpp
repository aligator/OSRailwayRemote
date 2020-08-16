#include "Display.h"

#include "Util.h"

// it did not work when putting this inside of the display class...
TFT_eSPI tft = TFT_eSPI(135, 240);

Display::Display(Mqtt* mqtt) { this->mqtt = mqtt; }

Display::~Display() {}

void Display::setup() {
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN);

  if (TFT_BL > 0) {
    pinMode(TFT_BL, OUTPUT);  // Set backlight pin to output mode
    digitalWrite(TFT_BL, TFT_BACKLIGHT_ON);
  }
  _drawList();
}

void Display::_drawList() {
  const int size = 16;

  tft.setCursor(0, 0);
  tft.setTextDatum(TC_DATUM);
  tft.setTextSize(size / 8);
  tft.fillScreen(TFT_BLACK);

  tft.drawString("OSRailway", tft.width() / 2, 0);
  tft.drawString("Remote", tft.width() / 2, size);

  tft.drawLine(0, 32, tft.width(), 32, TFT_GREEN);

  for (size_t i = 0; i < mqtt->data.getTrains().size(); i++) {
    tft.drawString(mqtt->data.getTrains()[i], tft.width() / 2,
                   (i + 2) * size + 1);
  }
}

void Display::loop() {
  if (mqtt->data.isDirty()) {
    _drawList();
  }
}