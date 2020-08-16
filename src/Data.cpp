#include "Data.h"

Data::Data() { this->trains = std::vector<String>{}; }

Data::~Data() {}

bool Data::addTrain(String trainName) {
  Serial.println("asdfasdf");
  for (size_t i = 0; i < trains.size(); i++) {
    if (trains[i].equals(trainName)) {
      return false;
    }
  }

  trains.push_back(trainName);
  dirty = true;

  // reorder
  bool finished = false;
  while (!finished) {
    finished = true;
    // Use simple bubblesort as it doesn't need recursion and is enough for our
    // case.
    for (size_t i = 0; i < trains.size() - 1; i++) {
      if (trains[i].compareTo(trains[i + 1]) > 0) {
        String tmp = trains[i];
        trains[i] = trains[i + 1];
        trains[i + 1] = tmp;
        finished = false;
      }
    }
  }

  return true;
}

bool Data::removeTrain(String trainName) {
  dirty = true;

  for (std::vector<String>::iterator it = trains.begin(); it != trains.end();
       ++it) {
    if (it->equals(trainName)) {
      trains.erase(it);
      return true;
    }
  }

  return false;
}

const std::vector<String>& Data::getTrains() {
  dirty = false;
  return trains;
}

bool Data::isDirty() { return dirty; }