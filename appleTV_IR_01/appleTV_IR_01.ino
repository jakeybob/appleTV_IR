/* This software is written for an Arduino compatible Pro Micro board.
 *  Appropriate board libraries are required and can be found here: 
 *  https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide
 * 
 * Board = SparkFun Pro Micro
 * Processor = ATMega32U4 (3.3V, 8MHz)
 * 
 * Should also work fine on e.g. Arduino Uno etc but correct board/processor must
 * be selected in IDE.
 * 
 * Volume up/down/hold codes are from an LG remote – the AppleTV remote 
 * was trained to emulate them. Codes found from using debug program in the
 * IRremote lib.
 * 
 */


#include <IRremote.h>                     // https://github.com/z3t0/Arduino-IRremote
                       
                                          // I/O pins on the microcontroller
const int IRpin = 8;                      // IR sensor
const int UCpin = 2;                      // Volume UP
const int DCpin = 4;                      // Volume Down
const int MUTEpin = 6;                    // Mute

const int pulseTime = 5;                  // duration in milliseconds of volume up/down command
const int doubleClickTime = 200;          // duration in milliseconds for a double click (dbl click down to mute)

const unsigned long volUP = 551502015;    // codes for volume up/down. HOLD = code transmitted when 
const unsigned long volDOWN = 551534655;  // button stays pressed.
const unsigned long HOLD = 4294967295;

int state;                                // -1 for decreasing volume, 1 for increasing, 0 for mute
unsigned long tstamp = millis();

IRrecv irrecv(IRpin);                     // set up IRrecv object
decode_results results;                   

void setup()
{
//  Serial.begin(9600);                       // for debugging,

  pinMode(UCpin, OUTPUT);                   // set pins low. In order to send commands pin goes high,
  pinMode(UCpin, LOW);                      // causing transistor to switch and connect appropriate
                                            // control pin on DS1802 to GND, causing vol shift.  
  pinMode(DCpin, OUTPUT);
  pinMode(DCpin, LOW);

  pinMode(MUTEpin, OUTPUT);
  pinMode(MUTEpin, LOW);

  irrecv.enableIRIn();                      // start the IR receiver
   
}



void loop() {
  
    if (irrecv.decode(&results)) {          // if IR signal detected

      state = getState(results.value);      // vol up or down...?
//      Serial.println(state);                     // use to print variable to serial monitor etc!

  
      switch (state){
        case 1:
          incVolume();
        break;
  
        case -1:
          decVolume();          
        break;

        case 0:
          muteVolume();
        break;
        
      }

    irrecv.resume();                        // receive the next value
  }
  
  delay(5);

  
}




int getState(unsigned long result){

    switch (result){
      case volUP:
        state = 1;
      break;

      case volDOWN:
        if (millis() - tstamp < doubleClickTime){
          state = 0;
        }
        else{
          state = -1;
        }
        
        tstamp = millis();
      break;

      case HOLD:                            // if button held, assign previous button state instead of HOLD
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
  delay(pulseTime);
  digitalWrite(UCpin, LOW);
}

void decVolume(){
  digitalWrite(DCpin, HIGH);
  delay(pulseTime);
  digitalWrite(DCpin, LOW);
}

void muteVolume(){
  digitalWrite(MUTEpin, HIGH);
  delay(pulseTime);
  digitalWrite(MUTEpin, LOW);
}



