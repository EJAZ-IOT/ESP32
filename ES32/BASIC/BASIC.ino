const int button =15;
const int ledPin2 =4;
const int ledPin  =2;
int buttonstate =0;
void setup() {
  pinMode(button,INPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin,OUTPUT);

}

void loop() {
  buttonstate= digitalRead(button);
  //digitalWrite(ledPin,digitalRead(ledPin)^1);
  //delay(100);
  if(buttonstate == HIGH)
  {
    digitalWrite(ledPin2,HIGH);
  }
  else
  {
     digitalWrite(ledPin2,LOW);
  }

}
