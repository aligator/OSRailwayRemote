#include "Util.h"

void Util::espDelay(int ms) {
  esp_sleep_enable_timer_wakeup(ms * 1000);
  esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_ON);
  esp_light_sleep_start();
}

boolean Util::isValidNumber(String str) {
  boolean isNum = false;
  for (byte i = 0; i < str.length(); i++) {
    isNum = isDigit(str.charAt(i)) ||
            (i == 0 && (str.charAt(i) == '+' || str.charAt(i) == '.' ||
                        str.charAt(i) == '-'));
    if (!isNum) {
      return false;
    }
  }
  return isNum;
}
