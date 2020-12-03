QueueHandle_t YearQueue;

void setup()
{
  Serial.begin(115200);
  YearQueue = xQueueCreate(5, sizeof(int32_t));

  xTaskCreate(vSenderTask,"Sender Task 1",1024,(void*)2020,1,NULL);
  xTaskCreate(vSenderTask,"Sender Task 2",1024,(void*)2021,1,NULL);
  xTaskCreate(vReceiverTask,"Receiver Task",1024,NULL,2`,NULL);
}

void vSenderTask(void *pvParameters)
{
  BaseType_t qStatus;
  int32_t valueToSend;
  valueToSend =(int32_t)pvParameters;
  while(1)
  {
    qStatus = xQueueSend(YearQueue,&valueToSend,0);
    if(qStatus != pdPASS)
    {
      Serial.println("could not send to queue");
    }
  }
}
void vReceiverTask(void *pvParameters)
{
  BaseType_t  qStatus;
  int32_t valuereceived;
  const TickType_t xTickToWait = pdMS_TO_TICKS(100);
  while(1)
  {
    qStatus = xQueueReceive(YearQueue,&valuereceived,xTickToWait);

    if(qStatus == pdPASS)
    {
      Serial.print("Data received sucessfully : ");
      Serial.println(valuereceived);
    }
    else
    {
      Serial.print("could not receive sucessfully");
    }
  }
}
void loop(){}
