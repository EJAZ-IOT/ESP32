
QueueHandle_t yearQueue;

void setup()
{
 Serial.begin(115200);
 yearQueue = xQueueCreate(5,sizeof(int32_t));

 xTaskCreate(vSenderTask,"Sender Task",1000,NULL,1,NULL);
 xTaskCreate(vReceiverTask,"Receiver Task",1000,NULL,1,NULL);
}

void vSenderTask(void *pvPararmeters)
{
  BaseType_t qStatus;
  int32_t ValuetoSend = 2021;
  const TickType_t xTickstoWait = pdMS_TO_TICKS(100);
  while(1)
  {
    qStatus = xQueueSend(yearQueue,&ValuetoSend,0);
  } 
 
}
void vReceiverTask(void *pvParameters)
{
  BaseType_t qStatus;
  int32_t ValueReceived;
  const TickType_t xTickstoWait = pdMS_TO_TICKS(100);
  while(1)
  {
    qStatus = xQueueReceive(yearQueue,&ValueReceived,xTickstoWait);
    
    Serial.print("Recieved Value : ");
    Serial.println(ValueReceived);
  }
}




void loop()
{}
