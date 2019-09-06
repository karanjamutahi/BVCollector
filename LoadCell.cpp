#include "LoadCell.h"

LoadCell::LoadCell(uint8_t clockPin, uint8_t dataPin, float scaleFactor ) {
  long read;
  char buffer [255];
  LogPrintTag(F("LoadCell"), F("Initialising"));
  HX711 scale;
  myScale = scale
  scale.begin(dataPin, clockPin);
  read = myScale.read();
  LogPrintRaw(read);

  scale.set_scale(scaleFactor);
  read = myScale.read();
  sprintf(buffer, "%ld", read);
  LogPrintTag(F("LoadCell-Scaled"), buffer);

  myScale.tare();
  
}

uint32_t LoadCell::read() {
  //Return 3 averages
  myScale.power_up();
  return myScale.get_units(3);
  myScale.power_down();
}
