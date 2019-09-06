#define TINY_GSM_MODEM_SIM800
#define SerialMon Serial
#define SerialAT Serial1
#define TINY_GSM_DEBUG  SerialMon
#define TINY_GSM_RX_BUFFER  650
#define TINY_GSM_USE_GPRS true

#define SAFARICOM_APN F("safaricom");
#define SAFARICOM_APN_USERNAME F("saf");
#define SAFARICOM_APN_PASSWORD F("data");

 
#include <TinyGsmClient.h>
#include <ArduinoHttpClient.h>
#include <ArduinoJson.h>
#include "LogPrint.h"

#ifdef MODEM_DEBUG
#define MODEM_TAG F("MODEM")
#define DEBUG_PRINT SerialMon.print
#define DEBUG_PRINTLN LogPrint
#endif

class Comms {
  private:
    uint8_t status = 0;
    uint16_t serialize(BrainVData &data, char * buffer);
    uint16_t serialize(BrainVData & data, char * buffer, bool lib);
    
  public:
    Comms(char * server, uint16_t port);
    uint8_t Send(char * Json);
  
  protected:
  
  }
