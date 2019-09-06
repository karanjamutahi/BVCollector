//Init everything
#include "LoadCell.h"
#include "Modem.h"
#include "MPU.h"
#include "BrainVData.h"

void setup() {
  SerialMon.begin(115200);
  LoadCell Tension();
  
}
 
//Read modem for time
//Check time. When time is 30seconds from when we checked, read everything and store in array
//When time is 10 minutes from last send(check modem). Upload everything

void loop() {


}
 
