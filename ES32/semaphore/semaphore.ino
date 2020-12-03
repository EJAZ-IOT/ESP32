#define  GREEN 15
#define  RED   4
#define  BLUE  2


SemaphoreHandle_t xCountingSemaphore;

void setup()
{
  Serial.begin(115200);
  
  xCountingSemaphore = xSemaphoreCreateCounting(3,0);

  xTaskCreate(greenLedControllerTask, "Green Led Task",1000,NULL,1,NULL);
  xTaskCreate(redLedControllerTask, "Red Led Task", 1000,NULL,1,NULL);
  xTaskCreate(blueLedControllerTask,"Blue Led Task", 1000,NULL,1,NULL);
 
}

void greenLedControllerTask(void *pvParameters)
{
  pinMode(GREEN,OUTPUT);
  
  xSemaphoreGive(xCountingSemaphore);                         //someone have to give semaphore to start otherwise it will be DEADLOCK
  while(1)
  {
   xSemaphoreTake(xCountingSemaphore,portMAX_DELAY);         //PORTMAX DELAY means next line of code wait to execute untill semaphore is avaliable
     Serial.println("This is GREEN Task");

   xSemaphoreGive(xCountingSemaphore);
   vTaskDelay(1);                                     //vTaskDelay blocked a task for specified number of ticks
  }
}

void redLedControllerTask(void *pvParameters)
{
  pinMode(RED,OUTPUT);
  while(1)
  {
    xSemaphoreTake(xCountingSemaphore,portMAX_DELAY);
      Serial.println("This is RED Task");

    xSemaphoreGive(xCountingSemaphore);
    vTaskDelay(1);
  }
}
void blueLedControllerTask(void *pvParameters)
{
  pinMode(BLUE,OUTPUT);
  while(1)
  {
    xSemaphoreTake(xCountingSemaphore,portMAX_DELAY);
      Serial.println("This is BLUE Task");

    xSemaphoreGive(xCountingSemaphore);
    vTaskDelay(1);
  }
}


void loop(){}
