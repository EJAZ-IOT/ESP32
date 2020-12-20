
void setup()

{
  Serial.begin(115200);
  xTaskCreatePinnedToCore(Task1,"task1",1000,NULL,1,NULL,0);
  xTaskCreatePinnedToCore(Task2,"task2",1000,NULL,1,NULL,1);
  
}

void Task1(void * pvparameters)
{
  String text = "task1 running on core : ";
  String combined = text + xPortGetCoreID();
  while(1)
  {
  Serial.println(combined);

  delay(100);
}}

void Task2(void * pvparameters)
{
   String text = "task2 running on core : ";
   String combined = text + xPortGetCoreID();
  while(1)
  {
  Serial.println(combined);

  delay(100);
}}

void loop(){}
