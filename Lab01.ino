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


void setup() {
  pinMode(digitalPin, OUTPUT);
  Serial.begin(9600);
}
  int i = 0;
  
void loop() {

  if (i== 12){
    i=0;
    }
  
  // read the value from the sensor:
  sensorValue0 = analogRead(analogPin0);
  sensorValue1 = analogRead(analogPin1);
  sensorValue2 = analogRead(analogPin2);
  sensorValue3 = analogRead(analogPin3);
  sensorValue4 = analogRead(analogPin4);
  sensorValue5 = analogRead(analogPin5);
  sensorValue6 = analogRead(analogPin6);
  sensorValue7 = analogRead(analogPin7);
  
  float finalNumber = (0*(1024.0-sensorValue0) + 1000/7*(1024.0-sensorValue1) + 2000/7*(1024-sensorValue2) + 3000/7*(1024-sensorValue3) + 4000/7*(1024-sensorValue4) + 5000/7*(1024-sensorValue5) + 6000/7*(1024-sensorValue6) + 7000/7*(1024-sensorValue7))/((1024-sensorValue0)+(1024-sensorValue1)+(1024-sensorValue2)+(1024-sensorValue3)+(1024-sensorValue4)+(1024-sensorValue5)+(1024-sensorValue6)+(1024-sensorValue7));

 // declare an array
  float filter[12] ; 

  filter[i] = finalNumber;

  float finalFinalNumber = ((filter[0]+filter[1]+filter[2]+filter[3]+filter[4]+filter[5]+filter[6]+filter[7]+filter[8]+filter[9]+filter[10]+filter[11])/12);
  Serial.print(finalNumber);
  Serial.print(" ");
  Serial.print("Line position: " );
  Serial.print(finalFinalNumber);
  if (finalFinalNumber > 500){
    Serial.println("    Turn Right");
    }
    else if (finalFinalNumber <500){
      Serial.println("    Turn Left");
      }
      else Serial.println(" ");
  
  i = i+1;
  
  delay(20);
}
