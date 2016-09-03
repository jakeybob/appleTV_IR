
#include <IRremote.h>

const int IRpin = 8;
const int UCpin = 2;
const int DCpin = 4;
const int MUTEpin = 6;

const unsigned long volUP = 551502015;
const unsigned long volDOWN = 551534655;
const unsigned long HOLD = 4294967295;

int state = 0;  // -1 for decreasing volume, 1 for increasing
unsigned long tstamp;


IRrecv irrecv(IRpin);

decode_results results;

void setup()
{
  Serial.begin(9600);

  pinMode(UCpin, OUTPUT);
  pinMode(UCpin, LOW);
  
  pinMode(DCpin, OUTPUT);
  pinMode(DCpin, LOW);

  pinMode(MUTEpin, OUTPUT);
  pinMode(MUTEpin, LOW);

  irrecv.enableIRIn(); // Start the receiver
  

  
}



void loop() {
    if (irrecv.decode(&results)) {

    state = getState(results.value);
    Serial.println(state);
    Serial.println(millis());

    switch (state){
      case 1:
        incVolume();
      break;

      case -1:
        decVolume();
      break;
      
    }

    
    
    irrecv.resume(); // Receive the next value
  }
  
  delay(50);

  
}




int getState(unsigned long result){

//    Serial.println(result);
    switch (result){
      case volUP:
        state = 1;
      break;

      case volDOWN:
        state = -1;
      break;

      case HOLD:
        if (state == 1){
          state = 1;
        }
        if (state == -1){
          state = -1;
        }
      break;
      
    }

    return state;
  
}


void incVolume(){
  digitalWrite(UCpin, HIGH);
  delay(10);
  digitalWrite(UCpin, LOW);
}


void decVolume(){
  digitalWrite(DCpin, HIGH);
  delay(10);
  digitalWrite(DCpin, LOW);
  
}

void muteVolume(){
  digitalWrite(MUTEpin, HIGH);
  delay(10);
  digitalWrite(MUTEpin, LOW);
}



