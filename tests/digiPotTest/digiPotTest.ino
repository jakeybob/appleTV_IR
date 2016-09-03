#include <SPI.h>

const int slaveSelectPin = 10;
const int channel = 1;


void setup() {
  pinMode(slaveSelectPin, OUTPUT);
  Serial.begin(9600);
//  SPI.begin();
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE1));

}

void loop() {
  


  digitalPotDBincrement();

  delay(1000);

  digitalPotDBdecrement();

  delay(1000);


}


void digitalPotDBincrement(){
  digitalWrite(slaveSelectPin, LOW);
//  byte controlAddressData = B01011101;

  SPI.transfer16(0b0101110111111111);
    unsigned long test = SPI.transfer16(0b0011000011111101);
//    Serial.println(test);

  
  digitalWrite(slaveSelectPin, HIGH);
}

void digitalPotDBdecrement(){
  digitalWrite(slaveSelectPin, LOW);
  byte controlAddress = B01011101;
  byte data = B11111110;

  word data2transfer = (controlAddress * 256) + data;
  SPI.transfer16(data2transfer);


  digitalWrite(slaveSelectPin, HIGH);
}


void digitalPotWrite(int address, int value) {
  // take the SS pin low to select the chip:
  digitalWrite(slaveSelectPin, LOW);
  //  send in the address and value via SPI:
  SPI.transfer(address);
  SPI.transfer(value);
  // take the SS pin high to de-select the chip:
  digitalWrite(slaveSelectPin, HIGH);
}
