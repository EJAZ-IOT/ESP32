#define GREEN  15
#define RED    4
#define BLUE   2


TaskHandle_t green_Handle,red_Handle,blue_Handle;

void setup() {
  Serial.begin(112500);
  xTaskCreate(greenLedController,"GREEN LED TASK",1000,NULL,1,&green_Handle);
  xTaskCreate(redLedController,"RED LED TASK",1000,NULL,1,&red_Handle);
  xTaskCreate(blueLedController,"BLUE LED TASK",1000,NULL,1,&blue_Handle);
  

}

void greenLedController(void *pvParameters)
{
  pinMode(GREEN,OUTPUT);
   while(1)
   {
    digitalWrite(GREEN,digitalRead(GREEN)^1);
    Serial.print("GREEN LED TASK\n");
     vTaskPrioritySet(blue_Handle,3);
    //delay(50);
   }
  
}

void redLedController(void *pvParameters)
{
  pinMode(RED,OUTPUT);
   while(1)
   {
    digitalWrite(RED,digitalRead(RED)^1);
     Serial.print("RED LED TASK\n");
    //delay(50);
   }
  
}

void blueLedController(void *pvParameters)
{
  pinMode(BLUE,OUTPUT);
   while(1)
   {
    digitalWrite(BLUE,digitalRead(BLUE)^1);
    Serial.print("BLUE LED TASK\n");
     //delay(50);
   }
  
}
void loop() {}
