#define      RED     4
#define      BLUE    2

EventGroupHandle_t  xEventGroup;

#define TASK1_BIT (1UL<<0UL)//setting bit0 in event group to 1
#define TASK2_BIT (1UL<<1UL)

void setup()
{
  Serial.begin(115200);
  pinMode(RED,OUTPUT);
  pinMode(BLUE,OUTPUT);

  xEventGroup =  xEventGroupCreate();

  xTaskCreate(EventBitSettingTask, "Bit Setter",1000,NULL,1,NULL );
  xTaskCreate(EventBitReadingTask, "Bit Reader",1000,NULL,1,NULL);
}


void EventBitSettingTask(void *pvParameters)
{
  const TickType_t xDelay500ms  = pdMS_TO_TICKS(500);
  while(1)
  {
    xEventGroupSetBits(xEventGroup,TASK1_BIT);
    vTaskDelay(xDelay500ms);
    xEventGroupSetBits(xEventGroup,TASK2_BIT);
  }
  
}

void EventBitReadingTask(void *pvParameters)
{
  const EventBits_t xBitsToWaitFor = (TASK1_BIT |TASK2_BIT);
  EventBits_t xEventGroupValue;
  
  while(1)
  {
   xEventGroupValue = xEventGroupWaitBits(xEventGroup,
                                    xBitsToWaitFor,
                                    pdTRUE,
                                    pdTRUE,
                                    portMAX_DELAY
                                   );
  if((xEventGroupValue & TASK1_BIT) !=0)
  {
     digitalWrite(RED,digitalRead(RED)^1);
  }

  if((xEventGroupValue & TASK2_BIT)!=0)
  {
    digitalWrite(BLUE,digitalRead(BLUE)^1);
  }
}
}
void loop(){}
