# Arduino Setup

This code is designed to create a setup using various components such as a liquid crystal display (LCD), an ultrasonic sensor, a tilt switch, and an MPU6050 accelerometer and gyroscope module. 

The code reads data from these components and sends it to an ESP8266 Wi-Fi module, which is accessible by an IP address and speficic and that allows to send the data.

## Prerequisites

Before using this code, you need to install the following libraries:

- [LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal)
- [Ultrasonic](https://github.com/ErickSimoes/Ultrasonic)
- [Adafruit_MPU6050](https://github.com/adafruit/Adafruit_MPU6050)
- [Adafruit_Sensor](https://github.com/adafruit/Adafruit_Sensor)
- [Wire](https://www.arduino.cc/en/reference/wire)

You can install these libraries through the Arduino Library Manager.

## Wiring Instructions

To use this code, you need to connect the components as follows:

All components are on 5V and GND.

- LCD: Connect the necessary pins (rs, en, d4, d5, d6, d7) to the corresponding pins on the Arduino board.
- Ultrasonic Sensor: Connect the trigger and echo pins of the sensor to digital pins 11 and 12 on the Arduino board.
- Tilt Switch: Connect the tilt switch to digital pin 8 on the Arduino board.
- MPU6050: Connect the SDA and SCL pins of the MPU6050 module to the corresponding SDA and SCL pins on the Arduino board. Also, make sure to provide the module with the required power and ground connections.
- Wifi ESP8266: Connect RX to TX2 16 & TX to RX2 17, VCC to 5V & GND to GND.

## Configuration

Before uploading the code to your Arduino board, make sure to modify the following parts according to your setup:

1. Wi-Fi Configuration:
   - In the `setup()` function, modify the Wi-Fi credentials in the `sendATcommand()` function calls to match your network's SSID and password. The current values are `"OnePlus5TA"` and `"df444efd2b55"`, respectively. 
   - Additionally, ensure that your ESP8266 module is compatible with the AT commands used in the code. Adjust the baud rate (`Serial2.begin(9600)`) if required.

## Usage

1. Upload the code to your Arduino board.
2. Open the serial monitor (baud rate: 9600) to monitor the output, configure line to NL & CR.
3. Make sure your Arduino board is connected to the Wi-Fi network specified in the code.
4. The code will continuously read data from the sensors, including the ultrasonic sensor, tilt switch, and MPU6050 module.
5. When a specific HTTP request is received from the server (check IP with AT+CIFSR command), the Arduino will send a JSON format response containing the current states of the ultrasonic sensor, tilt and temperature.
6. The response will be sent to the server via the ESP8266 module, using the AT commands.
7. The server can then process the received data.

Please note that this README provides only a brief overview of the code's functionality and configuration. For a more detailed understanding, refer to the comments within the code itself.
