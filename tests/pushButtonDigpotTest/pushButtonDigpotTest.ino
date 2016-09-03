 const int UC1pin = 2;
 const int DC1pin = 3;
 const int UC0pin = 4;
 const int DC0pin = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(UC1pin, OUTPUT);
  pinMode(UC1pin, HIGH);
  
  pinMode(DC1pin, OUTPUT);
  pinMode(DC1pin, HIGH);
  
  pinMode(UC0pin, OUTPUT);
  pinMode(UC0pin, HIGH);
  
  pinMode(DC0pin, OUTPUT);
  pinMode(DC0pin, HIGH);


}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(UC1pin, LOW);
  digitalWrite(UC0pin, LOW);

  delay(500);
  
  digitalWrite(UC1pin, HIGH);
  digitalWrite(UC0pin, HIGH);

  delay(500);
}
