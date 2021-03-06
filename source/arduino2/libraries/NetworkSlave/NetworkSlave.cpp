#include "NetworkSlave.h"
#include "WProgram.h"
#include "Wire.h"
#include "DownstreamDataParser.h"

#define UPSTREAM_MESSAGE_SIZE 2

NetworkSlave::NetworkSlave() {
  ud->setCancel(false);
  ud->setReserve(0);
  dd->setCurrentReservation(false);
  dd->setPendingReservation(false);
  dd->setDisplayString(NULL);
}

char* NetworkSlave::getUpstreamData() {
  char message[UPSTREAM_MESSAGE_SIZE];
  message[0] = (char) ud->getCancel();
  message[1] = (char) ud->getReserve();
  return message;
}

void NetworkSlave::setDownstreamData(char *received) {
  dd = DownstreamDataParser::parseDownstreamData(received);
}

void NetworkSlave::reserve() {
  ud->setCancel(false);
  ud->setReserve(ud->getReserve()+1);
}

void NetworkSlave::cancel() {
  if (dd->getCurrentReservation()) {
    ud->setReserve(0);
    ud->setCancel(true);
  }
}

char* NetworkSlave::getDisplayString() {
	return dd->getDisplayString();
}
