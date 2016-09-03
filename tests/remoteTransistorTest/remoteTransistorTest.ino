 
#include <IRremote.h>

// Note: Right speaker channel = channel 1 on pot, Left = channel 0

const int IRpin = 9;
const int UCpin = 7;
const int DCpin = 8;
const int MUTEpin = 13;

const unsigned long volUP = 551502015;
const unsigned long volDOWN = 551534655;
const unsigned long HOLD = 4294967295;

int state = 0;  // -1 for decreasing volume, 1 for increasing

IRrecv irrecv(IRpin);

decode_results results;


 void setup() {
  pinMode(UCpin, OUTPUT);
  pinMode(UCpin, LOW);
  
  pinMode(DCpin, OUTPUT);
  pinMode(DCpin, LOW);

  pinMode(MUTEpin, OUTPUT);
  pinMode(MUTEpin, LOW);
  
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  
}


void loop(){

    if (irrecv.decode(&results)) {

    state = getState(results.value);
    Serial.println(state);

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


void incVolume(){
  Serial.println("Inc");
  digitalWrite(UCpin, HIGH);
  delay(10);
  digitalWrite(UCpin, LOW);
}


void decVolume(){
  Serial.println("Dec");
  digitalWrite(DCpin, HIGH);
  delay(10);
  digitalWrite(DCpin, LOW);
}

int getState(unsigned long result){

    //Serial.println(result);
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
