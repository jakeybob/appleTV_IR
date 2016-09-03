
#include <IRremote.h>

int RECV_PIN = 9;

const unsigned long volUP = 551502015;
const unsigned long volDOWN = 551534655;
const unsigned long HOLD = 4294967295;

int state = 0;  // -1 for decreasing volume, 1 for increasing


IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}



void loop() {
  if (irrecv.decode(&results)) {

    state = getState(results.value);
    Serial.println(state);

    
    
    irrecv.resume(); // Receive the next value
  }
  
  delay(100);
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


