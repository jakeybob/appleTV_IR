 const int UCpin = 7;
 const int DCpin = 8;


void setup() {
  // put your setup code here, to run once:
  pinMode(UCpin, OUTPUT);
  pinMode(UCpin, LOW);
  
  pinMode(DCpin, OUTPUT);
  pinMode(DCpin, LOW);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(UCpin, HIGH);

  delay(5000);

  digitalWrite(UCpin, LOW);

  delay(1000);




  digitalWrite(DCpin, HIGH);

  delay(5000);

  digitalWrite(DCpin, LOW);

  delay(1000);


}
