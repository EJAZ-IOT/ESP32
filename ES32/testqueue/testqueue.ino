QueueHandle_t Queue1;
void setup()

{
  Serial.begin(115200);
  
  Queue1 = xQueueCreate(5,sizeof(int32_t));
  xTaskCreatePinnedToCore(Task1,"task1",1000,NULL,1,NULL,0);
  xTaskCreatePinnedToCore(Task2,"task2",1000,NULL,1,NULL,1);
  
}

void Task1(void * pvparameters)
{
  BaseType_t qStatus;
  int32_t a=10;
  const TickType_t xTickstoWait = pdMS_TO_TICKS(100);
  while(1)
  {
   qStatus = xQueueSend(Queue1,&a,0);
     
}}

void Task2(void * pvparameters)
{
  BaseType_t qStatus;
   int32_t a;
   const TickType_t xTickstoWait = pdMS_TO_TICKS(100);
  while(1)
  {
   qStatus = xQueueReceive(Queue1,&a,xTickstoWait);
   Serial.print("Value of a from task1 : ");
   Serial.println(a);

}}

void loop(){}
