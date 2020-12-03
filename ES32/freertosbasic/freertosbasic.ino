

#define GREEN  15
#define RED    4
#define BLUE   2


void setup() {
  Serial.begin(112500);
  xTaskCreate(greenLedControlTask,
               "GREEN LED TASK",
               1000,
               NULL,
               1,
               NULL);
  xTaskCreatePinnedToCore(redLedControlTask,
               "RED LED TASK",
               1000,
               NULL,
               1,
               NULL,
               1);
               
  xTaskCreate(blueLedControlTask,
              "BLUE LED TASK",
              1000,
              NULL,
              3,
              NULL);

  
}

void greenLedControlTask(void *pvparameters)
{
  pinMode(GREEN,OUTPUT);

  while(1)
  {
   digitalWrite(GREEN,digitalRead(GREEN)^1);
   Serial.println("This is GREEN");
   Serial.println(xPortGetCoreID());
   delay(100);
  }

}

void redLedControlTask(void *pvparameters)
{
  pinMode(RED,OUTPUT);
  while(1)
  {
    digitalWrite(RED,digitalRead(RED)^1);
    Serial.println("This is RED");
    Serial.println(xPortGetCoreID());
    delay(100);
  }
  
}

void blueLedControlTask(void *pvparameters)
{
  pinMode(BLUE,OUTPUT);
  while(1)
  {
    digitalWrite(BLUE,digitalRead(BLUE)^1);
    Serial.println("This is BLUE");
     delay(100);
  }
    
}

void loop()
{}
