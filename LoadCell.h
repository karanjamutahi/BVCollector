#include <HX711.h>
#include "LogPrint.h"

class LoadCell {
  private:
    HX711 * myScale;
  public:
    LoadCell(uint8_t clockPin, uint8_t dataPin);
    uint32_t read();
    
  protected:

  
};
