#include <stdint.h>
#include <string>
using namespace std;
void setUpRemote(uint8_t recv_pin);

uint64_t getHexButtonDown();

String getCharFromRemote();

void printHexButtonDown();

void getInfoRemote();