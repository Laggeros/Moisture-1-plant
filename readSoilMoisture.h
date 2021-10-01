#include "convertToPercent.h"

int sensors[6] = {A0, A1, A2, A3, A6, A7};
int sensorValue; 
int percentSensorValue;

int readSoilMoisture(int sensor){
  for (int j = 0; j < 10; j++) {  //Averaging 10 readings to reduce error possibility
    sensorValue = sensorValue + analogRead(sensors[sensor]); 
    delay(3); 
  }
  sensorValue = sensorValue/10; 
  Serial.print("Sensor analog value: ");
  Serial.println(sensorValue);
  Serial.print("Sensor value: ");
  percentSensorValue = convertToPercent(sensorValue, sensor);
  Serial.print(percentSensorValue);Serial.println("%");
  
  lcd.clear();
  lcd.print("Pot number ");
  lcd.print(sensor);
  lcd.setCursor(0,1);
  lcd.print("Moisture: "); 
  lcd.setCursor(11,1);
  lcd.print("    ");
  lcd.setCursor(11,1);
  lcd.print(percentSensorValue); 
  lcd.print("%");

  return percentSensorValue;
  sensorValue = 0;
}
