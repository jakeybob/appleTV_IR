// http://arduino.stackexchange.com/questions/10255/how-to-interface-ds1801-digital-resistor-with-arduino-due-spi-interface-what-cl
// http://docs-europe.electrocomponents.com/webdocs/078a/0900766b8078aeaf.pdf

#include <SPI.h>


// set pin 10 as the slave select for the digital pot:
const int slaveSelectPin = 5;
int mute = 64;
int loud = 63;
int soft = 0;

void setup() {
  pinMode (slaveSelectPin, OUTPUT);
  digitalWrite(slaveSelectPin, LOW);
  Serial.begin(9600);
  
  // initialize SPI:
//  SPI.setBitOrder(LSBFIRST);
//  SPI.setDataMode(SPI_MODE0);
//  SPI.setClockDivider(slaveSelectPin,SPI_CLOCK_DIV8);
//  SPI.begin();
  SPI.beginTransaction(SPISettings(100, LSBFIRST, SPI_MODE0));
  
  delay(100);
   digitalPotWrite(mute, mute);
}

void loop() {

  digitalPotWrite(B10000000, B10000000);
    delay(200);
  }

void digitalPotWrite(int left, int right) {
  // take the SS pin low to select the chip:
  digitalWrite(slaveSelectPin, HIGH);

SPI.transfer(left);
delay(50);
SPI.transfer(right);

  
  // take the SS pin high to de-select the chip:
  digitalWrite(slaveSelectPin, LOW);
}
