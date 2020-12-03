#define   GREEN 15
#define   RED   4
#define   BLUE  2


#define TASK1_BIT   (1UL << 0UL)
#define TASK2_BIT   (1UL << 1UL)
#define TASK3_BIT   (1UL << 2UL)

EventGroupHandle_t  xEventGroup;

const TickType_t xDelay500ms =  pdMS_TO_TICKS(500);
void setup()
{
   xEventGroup  =  xEventGroupCreate();

   xTaskCreate(InputTask1, "Input Task 1", 1000,NULL,1,NULL);
   xTaskCreate(InputTask2, "Input Task 2", 1000, NULL, 1, NULL );
   xTaskCreate(InputTask3, "Input Task 3", 1000, NULL, 1,NULL);
   xTaskCreate(OutputTask, "Output Task", 1000, NULL, 1, NULL);
   
}

void InputTask1(void *pvParameters)
{
  while(1)
  {
     xEventGroupSetBits(xEventGroup, TASK1_BIT);
     vTaskDelay(xDelay500ms);
  }
}
void InputTask2(void *pvParameters)
{
  while(1)
  {
    xEventGroupSetBits(xEventGroup, TASK2_BIT);
    vTaskDelay(xDelay500ms);
  }
}


void InputTask3(void *pvParameters)
{
  while(1)
  {
    xEventGroupSetBits(xEventGroup,TASK3_BIT);
    vTaskDelay(xDelay500ms);
  }
}


void OutputTask(void *pvParameters)
{ 
  pinMode(GREEN,OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(BLUE,OUTPUT);
  
  const EventBits_t xBitsToWaitFor  = (TASK1_BIT | TASK2_BIT | TASK3_BIT);
  EventBits_t xEventGroupValue;
  while(1)
  {
    xEventGroupValue  = xEventGroupWaitBits(xEventGroup,
                                            xBitsToWaitFor,
                                            pdTRUE,
                                            pdTRUE,
                                            portMAX_DELAY
                                            );
   if((xEventGroupValue & TASK1_BIT) !=0)
   {
    digitalWrite(GREEN,digitalRead(GREEN)^1);
   }
   if((xEventGroupValue & TASK2_BIT !=0))
   {
      digitalWrite(RED,digitalRead(RED)^1);
   }
   if((xEventGroupValue & TASK3_BIT !=0))
   {
    digitalWrite(BLUE,digitalRead(BLUE)^1);
   }
  }
}
void loop(){}
