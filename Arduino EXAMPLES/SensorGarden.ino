//Pins the moisture sensors connect to
int sensorZero = A0;
int sensorOne = A1;
int sensorTwo = A2;

//Variables for the outputs of the sensors
float outputZero ;
float outputOne ;
float outputTwo ;

//Pin to turn off and on the sensors
int VoltagePin = 8;


void setup() {

//Begin serial communications at 9600 Baud rate and let user know the sensor is reading the moisture
  Serial.begin(9600);
  Serial.println("Reading From the Sensor ...");
  delay(2000);

//Set pin to output
  pinMode(VoltagePin, OUTPUT);
}

void loop() {

//Turn on sensors
  digitalWrite(VoltagePin, HIGH);

//Allow a delay to let the sensors completely turn on 
  delay (500);

//Read the output values of the sensors
  outputZero= analogRead(sensorZero);
  outputOne= analogRead(sensorOne);
  outputTwo= analogRead(sensorTwo);
  
  delay(200);

//SENSOR 1
//Dry: 560, Wet: 288, 
//PercentageOneDry is the percent amount that the sensor is dry
  int PercentageOneDry = ((outputZero - 288)/270)*100;
//Subtract dry percentage from 100 to get the wet percentage
  int PercentageOneWet = 100 - PercentageOneDry;

//Print results
  Serial.print("Sensor One Moisture: ");
  Serial.print(PercentageOneWet);
  Serial.print("%");
  Serial.print('\n');

  delay(1000);

//Dry: 563, Wet: 289, Difference 274
//PercentageOneDry is the percent amount that the sensor is dry
  int PercentageTwoDry = ((outputOne - 289)/274)*100;
//Subtract dry percentage from 100 to get the wet percentage
  int PercentageTwoWet = 100 - PercentageTwoDry;

//Print results
  Serial.print("Sensor Two Moisture: ");
  Serial.print(PercentageTwoWet);
  Serial.print("%");
  Serial.print('\n');

  delay(1000);

//Dry:559, Wet: 286, Difference 273
//PercentageOneDry is the percent amount that the sensor is dry
int PercentageThreeDry = ((outputTwo - 286)/273)*100;
//Subtract dry percentage from 100 to get the wet percentage
int PercentageThreeWet = 100 - PercentageThreeDry;

//Print results
  Serial.print("Sensor Three Moisture: ");
  Serial.print(PercentageThreeWet);
  Serial.print("%");
  Serial.print('\n');

  delay(1000);

//Turn off sensors
  digitalWrite(VoltagePin, LOW);
  
//Wait 5 minutes
  delay(3000);

}


