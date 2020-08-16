#ifndef DATA_H_
#define DATA_H_

#include "Arduino.h"
#include "vector"

class Data {
 public:
  Data();
  virtual ~Data();
  bool isDirty();
  bool addTrain(String trainName);
  bool removeTrain(String trainName);
  const std::vector<String>& getTrains();

 private:
  bool dirty;
  std::vector<String> trains;
};

#endif /* DATA_H_ */