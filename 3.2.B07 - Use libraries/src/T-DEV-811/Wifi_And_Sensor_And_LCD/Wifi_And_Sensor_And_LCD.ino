/*
 * Liquid cristal counter
 */
// Library
#include <LiquidCrystal.h>
#include <Ultrasonic.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
// #include <Wire.h>

// Initalisation de la librairie
Adafruit_MPU6050 mpu;

Ultrasonic ultrasonic(11, 12);
float tempValue;
int dist;
int tiltPin = 10;      // pin number for tilt switch signal 
int tiltState = 0;    // variable for reading the tilt switch status
int ledPin =  13;     // pin number of LED 
int linkID;
int reqSize;
const byte maxURLLength = 20;
char urlBuffer[maxURLLength];
int distance = 0;
int tilt = 0;
int temperature = 0;
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
char *dialog[] = {"Tilted: ", "Distance: ", "Temp: "};
int count = 0;

void setup() {
  pinMode(ledPin, OUTPUT);  // set the LED pin as output      
  Serial.begin(9600);  // Initialisation du moniteur série
  Serial2.begin(9600);  // Initialisation de la communication avec l'ESP8266
  delay(1000);  // Attente de 1 seconde pour la stabilité de la communication

  gyro_setup();
  pinMode(tiltPin, INPUT);  // set the tilt switch pin as input
  lcd.begin(16, 2);
  analogWrite(8,15);
  delay(1000);

  sendATcommand("AT+CWQAP", "OK", 1000);
  sendATcommand("AT+CWJAP_CUR=\"OnePlus5TA\",\"df444efd2b55\"", "OK", 10000);
  sendATcommand("AT+CIPMUX=1", "OK", 5000);
  sendATcommand("AT+CIPSERVER=1,80", "OK", 5000);
}

void loop() {
  gyro();
  dist = ultrasonic.read(CM);
  tiltState = digitalRead(tiltPin);
  
  if (tiltState == HIGH) {     
    digitalWrite(ledPin, HIGH); 
    tilt = 1;
  } 
  else {
    digitalWrite(ledPin, LOW);
    tilt = 0;
  }

  if(dist < 30){
      distance = 1;
  } else {
      distance = 0;
  }

  Display_Data_LCD();
  handle_Request();
  
  delay(5000); // Attend 1 second
}

void Display_Data_LCD() {
  lcd.clear();
  lcd.print("Trash data : ");
  lcd.setCursor(0, 1);// place le curseur au 1er caractère de la 2nde ligne
  
  switch (count) {
    case 0:
      lcd.print(dialog[count]);
      lcd.print(tiltState);
      count = 1;
      break;
    case 1:
      lcd.print(dialog[count]);
      lcd.print(dist);
      lcd.print(" cm");
      count = 2;
      break;
    case 2:
      lcd.print(dialog[count]);
      lcd.print(tempValue);
      lcd.print(" degC");
      count = 0;
      break;
  }

  // Serial.print(tiltState);
  // Serial.print(" Tilted state\n");

  // Serial.print(tempValue);
  // Serial.print(" degC\n");

  // Serial.print(dist);
  // Serial.println(" cm\n");
}

void handle_Request() {
  if (Serial2.available()) {  // Check if data is available to read
    String response = Serial2.readStringUntil('\n');  // Read the incoming data until newline character
    char *wifiReturn = response.c_str();
    String jsonResponse = "{ \"results\": [" + String(distance) + ", " + String(tilt) + ", " + String(temperature) + "] }";
    if (sscanf(wifiReturn, "+IPD,%d,%d:GET %s HTTP/1.1", &linkID, &reqSize, urlBuffer) == 3) {
      Serial.println("Got HTTP Request");
      String urlCompare = String(urlBuffer);
      String urlReference = "/captors";
      if(urlCompare == urlReference) {
        Serial.print("Request on /captors \n");
        Serial2.println("AT+CIPSEND=" + String(linkID) +",24");
        delay(2000);
        Serial2.println(jsonResponse);
        delay(2000);
        Serial2.println("AT+CIPCLOSE=" + String(linkID));
        delay(2000);
        Serial.println("Reponse envoyée");
      }
      else {
        Serial.print("Request on wrong endpoint");
        Serial2.println("AT+CIPCLOSE=" + String(linkID));
      }
    }
  }
}

void gyro() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  /* Print out the values */
  // Serial.print("Acceleration X: ");
  // Serial.print(a.acceleration.x);
  // Serial.print(", Y: ");
  // Serial.print(a.acceleration.y);
  // Serial.print(", Z: ");
  // Serial.print(a.acceleration.z);
  // Serial.println(" m/s^2");

  // Serial.print("Rotation X: ");
  // Serial.print(g.gyro.x);
  // Serial.print(", Y: ");
  // Serial.print(g.gyro.y);
  // Serial.print(", Z: ");
  // Serial.print(g.gyro.z);
  // Serial.println(" rad/s");

  // Serial.print("Temperature: ");
  // Serial.print(temp.temperature);
  // Serial.println(" degC");

  if(temp.temperature > 20){
    temperature = 1;
  } else {
    temperature = 0;
  }

  tempValue = temp.temperature;
  // Serial.println("");
}

void gyro_setup() {
  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }
}

uint8_t sendATcommand(const char* ATcommand, const char* expected_answer, unsigned int timeout)
{
  uint8_t x = 0, answer = 0;
  char response[100];
  unsigned long previous;

  memset(response, '\0', 100); // Initialize the string

  delay(100);

  while (Serial2.available() > 0) { // Clean the input buffer
    Serial2.read();
  }
 
  Serial2.println(ATcommand);    // Send the AT command

  Serial.println(Serial2.read()); 

  x = 0;
  previous = millis();

  // This loop waits for the answer
  do {
    if (Serial2.available() != 0) {
      // if there are data in the UART input buffer, reads it and checks for the answer
      response[x] = Serial2.read();
      Serial.print(response[x]);
      x++;
      // check if the desired answer is in the response of the module
      if (strstr(response, expected_answer) != NULL) {
        answer = "OK\r\n";
      }
    }
    // Waits for the asnwer with time out
  } while ((answer == 0) && ((millis() - previous) < timeout));

  // fonaSerial->print("\n");
  return answer;
}
