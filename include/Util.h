#ifndef UTIL_H_
#define UTIL_H_

#include <Arduino.h>

class Util {
 public:
  static boolean isValidNumber(String str);
  static void espDelay(int ms);
};
#endif /* UTIL_H_ */