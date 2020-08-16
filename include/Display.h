#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <TFT_eSPI.h>

#include "Arduino.h"
#include "Data.h"
#include "Mqtt.h"

#ifndef TFT_DISPOFF
#define TFT_DISPOFF 0x28
#endif

#ifndef TFT_SLPIN
#define TFT_SLPIN 0x10
#endif

#define TFT_MOSI 19
#define TFT_SCLK 18
#define TFT_CS 5
#define TFT_DC 16
#define TFT_RST 23

#define TFT_BL 4   // Display backlight control pin
#define ADC_EN 14  // ADC_EN is the ADC detection enable port
#define ADC_PIN 34
#define BUTTON_1 35
#define BUTTON_2 0

class Display {
 public:
  Display(Mqtt* mqtt);
  virtual ~Display();

  void setup();
  void loop();

 private:
  Mqtt* mqtt;

  void _drawList();
};

#endif /* DISPLAY_H_ */