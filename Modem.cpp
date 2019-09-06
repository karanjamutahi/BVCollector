#include "Modem.h"

Comms::Comms(char * server, uint16_t port) {
  //Init all helper objects
  TinyGsm modem(SerialAT);
  TinyGsmClient commClient(modem);
  HTTPClient http(client, server, port);
  
  SerialAT.begin(2400); 
  DEBUG_PRINTLN(MODEM_TAG, F("Starting Modem ..."));
 
  modem.restart();
  
  if(modem.gprsConnect(SAFARICOM_APN, SAFARICOM_APN_USERNAME, SAFARICOM_APN_PASSWORD)) {
    DEBUG_PRINTLN(F("GPRS"), "OK");
    }
    else {
      DEBUG_PRINTLN(F("GPRS"), "FAIL")
    }

  }

/*  Attempt to Send data to server via HTTP POST
*   @param path: The path to send data to
*   @param data: Object containing specially structured data
*/
uint8_t Comms::Send(BrainVData &data, const char * path) {
  if(modem.gprsConnect(SAFARICOM_APN, SAFARICOM_APN_USERNAME, SAFARICOM_APN_PASSWORD)) {
    DEBUG_PRINTLN(F("GPRS"), "OK");
   }
  else {
    DEBUG_PRINTLN(F("GPRS"), "FAIL");
    return -1;
  }

  char buffer [550];
  serialize(data, buffer);

  if(http.post(path, F('application/json'), sizeof(buffer) ,buffer) == 0) {
    DEBUG_PRINTLN(F("SEND"), "OK");
   }
  else {
    DEBUG_PRINTLN(F("SEND"), "FAIL");
    return -2;
  }
}

uint16_t Comms::serialize(BrainVData &data, char * buffer) {
  uint16_t index = 0;
  //Open JSON string
  buffer[index++] = F('{'); 
  uint8_t arrayLength = sizeof(*data)/sizeof(*data)[0];
  
  for(int i=0; i< arrayLength ; i++) {
    //Open array
    buffer[index++] = F('[');

    //First item: LoadCell
    buffer[index++] = F("LC:");
    buffer[index++] = (*data)[i]->LC; 

    //TODO: Fill in all items

    //Close array.Ready for next item
    buffer[index++] = F(']');

    //Don't put comma for last data point
    if(i+1 == arrayLength) break;
    buffer[index++] = F(',');
  }

  //Close JSON string
  buffer[index++] = '}';
  return index;
}

//Serialize using arduinojson
uint16_t Comms::serialize(BrainVData & data, char * buffer, bool lib) {


}
   
