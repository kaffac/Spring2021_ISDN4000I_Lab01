int analogPin0 = A0; 
int analogPin1 = A1;
int analogPin2 = A2; 
int analogPin3 = A3;
int analogPin4 = A4; 
int analogPin5 = A5;
int analogPin6 = A6; 
int analogPin7 = A7;
int digitalPin = 13;
int sensorValue0 = 0;   
int sensorValue1 = 1;   
int sensorValue2 = 2;   
int sensorValue3 = 3;   
int sensorValue4 = 4;  
int sensorValue5 = 5;   
int sensorValue6 = 6;   
int sensorValue7 = 7;   
int i = 0;             //counter for the filter
int sumOfPrevious12AverageValue;  


void setup() {
  pinMode(digitalPin, OUTPUT);
  Serial.begin(9600);
}

  
void loop() {

  if (i == 12){i=0;} //make sure the filter array only stores in 0-11 numbers
  sumOfPrevious12AverageValue = 0;
  
  sensorValue0 = 1024-analogRead(analogPin0); //process the data so that the reading value is around 0 when there is no obstacle in front of the sensor 
  sensorValue1 = 1024-analogRead(analogPin1);
  sensorValue2 = 1024-analogRead(analogPin2);
  sensorValue3 = 1024-analogRead(analogPin3);
  sensorValue4 = 1024-analogRead(analogPin4);
  sensorValue5 = 1024-analogRead(analogPin5);
  sensorValue6 = 1024-analogRead(analogPin6);
  sensorValue7 = 1024-analogRead(analogPin7);
  
  float weightedSum = (1000.0/7)*(0*sensorValue0 + 1*sensorValue1 + 2*sensorValue2 + 3*sensorValue3 + 4*sensorValue4 + 5*sensorValue5 + 6*sensorValue6 + 7*sensorValue7);
  int normalSum = (sensorValue0 + sensorValue1 + sensorValue2 + sensorValue3 + sensorValue4 + sensorValue5 + sensorValue6 + sensorValue7);
  float averageValue = weightedSum/normalSum;

  float filter[12] ; //declare a filter array to store n previous average numbers 
  filter[i] = averageValue;
 
  for (int j=0; j<12; j++){
    sumOfPrevious12AverageValue += filter[j];  
  }

  float filteredAverageValue = sumOfPrevious12AverageValue/12;
  Serial.print("Line position: ");
  Serial.print(averageValue);
  Serial.print("   Filtered position: " );
  Serial.print(filteredAverageValue);
  
  if (averageValue > 500){
    Serial.println("    Turn right");
  }
  else if (averageValue < 500){
    Serial.println("    Turn left");
  }
  else Serial.println(" ");
  

  i += 1; //update the counter
  
  delay(20);
  
}
