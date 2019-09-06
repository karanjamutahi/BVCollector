#include "LogPrint.h"

void LogPrintTag(char * tag, char * message) {
  char buffer [255];
  sprintf(buffer, "[%s]\t%s", tag, message);
  SerialMon.println(buffer);
  }
