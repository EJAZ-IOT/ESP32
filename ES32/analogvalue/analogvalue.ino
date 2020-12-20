const int potPin = 4;
int potArray[10];

void setup() {

  Serial.begin(115200);
  pinMode(potPin, INPUT);

}

void loop() {
  int sum =0 , avg =0;
  for (int i = 0; i < 10; i++) 
  {
    potArray[i] = analogRead(potPin);
    sum+=potArray[i];
    delay(1000);
  }
  Serial.print("Sample Taken: ");
  Serial.print("[");
  
  for (int i=0; i<10; i++)
  {
    Serial.print(potArray[i]);
    if(i!=9){
    Serial.print(",");
  }}
  Serial.println("]");
  avg =sum/10;
  Serial.print("Average of Ten Sample is : ");
  Serial.println(avg);
  
}
