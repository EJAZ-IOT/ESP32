#define GREEN  15
#define RED    4
#define BLUE   2


const uint16_t *greenLed = (uint16_t *)GREEN;
const uint16_t *redLed = (uint16_t *)RED;
const uint16_t *blueLed = (uint16_t *)BLUE;

void setup() {

  xTaskCreate(ledControllerTask," GREEN LED TASK",1000,(void *)greenLed ,1,NULL);
  xTaskCreate(ledControllerTask," RED LED TASK",1000,(void *)redLed ,1,NULL);
  xTaskCreate(ledControllerTask," BLUE LED TASK",1000,(void *)blueLed ,1,NULL);
 

}

void ledControllerTask(void *pvParameters)
{
  pinMode(GREEN,OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(BLUE,OUTPUT);

  while(1)
  {

    digitalWrite(*(uint8_t)pvParameters,digitalRead(*(uint8_t)pvParameters)^1);
  }
}

void loop() {}
