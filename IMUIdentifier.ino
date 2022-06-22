#include <Wire.h>
// Similar to https://github.com/Levi--G/IMU-WhoAmIVerifier except for Arduinos instead of ESP's.
// Supported IMUs are the more common ones from Invensense

//Do be aware that MPU9150's will report as 6050s, this is because a 9150 is a 6050 with a magnetometer
//if you have a 9250 board and it reports as a 6050, it's most likely a 9150.

//This code will check for an IMU when reset and, if one is found, it will report what it is.
//To re run the check without resetting the Arduino, pull pin 4 to GND.

//Curently supported ones are:

//MPU6050           //ICM20608
//MPU6500           //ICM20609
//MPU9250           //ICM20649
//MPU9255           //ICM20690
//ICM20600          //ICM20648
//ICM20601          //ICM20649
//ICM20602          //ICM20948

void setup() {
  pinMode(4, INPUT_PULLUP);
  Wire.begin();
  Serial.begin(9600);
  while (!Serial) ;
  Serial.println("\n=========== IMU Identifier ===========");
}

void loop() {
  static int a = 0;
  while (digitalRead(4) && a != 0) ;   //do once
  a = 1;

  switch (readByte(0x68, 0x75)) {
    case 0x68:
      Serial.println("IMU Detected: MPU6050, ADO = 0");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0x70:
      Serial.println("IMU Detected: MPU6500, ADO = 0");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0x71:
      Serial.println("IMU Detected: MPU9250, ADO = 0");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer, 3 Axis Magnetometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0x73:
      Serial.println("IMU Detected: MPU9255, ADO = 0");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer, 3 Axis Magnetometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0x11:
      Serial.println("IMU Detected: ICM20600, ADO = 0");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0xAC:
      Serial.println("IMU Detected: ICM20601, ADO = 0");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0x12:
      Serial.println("IMU Detected: ICM20602, ADO = 0");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0xAF:
      Serial.println("IMU Detected: ICM20608, ADO = 0");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0xA6:
      Serial.println("IMU Detected: ICM20609, ADO = 0");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0x98:
      Serial.println("IMU Detected: ICM20689, ADO = 0");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0x20:
      Serial.println("IMU Detected: ICM20690, ADO = 0");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0xFF:
      break;
    default:
      Serial.print("Unknown: 0x");
      Serial.println(readByte(0x69, 0x00), HEX);
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
  }

  switch (readByte(0x68, 0x00)) {
    case 0xE0:
      Serial.println("IMU Detected: ICM20648, ADO = 0");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0xE1:
      Serial.println("IMU Detected: ICM20649, ADO = 0");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0xEA:
      Serial.println("IMU Detected: ICM20948, ADO = 0");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer, 3 Axis Magnetometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0xFF:
      break;
    default:
      Serial.print("Unknown: 0x");
      Serial.println(readByte(0x69, 0x00), HEX);
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
  }

  switch (readByte(0x69, 0x75)) {
    case 0x68:
      Serial.println("IMU Detected: MPU6050, ADO = 1");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0x70:
      Serial.println("IMU Detected: MPU6500, ADO = 1");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0x71:
      Serial.println("IMU Detected: MPU9250, ADO = 1");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer, 3 Axis Magnetometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0x73:
      Serial.println("IMU Detected: MPU9255, ADO = 1");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer, 3 Axis Magnetometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0x11:
      Serial.println("IMU Detected: ICM20600, ADO = 1");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0xAC:
      Serial.println("IMU Detected: ICM20601, ADO = 1");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0x12:
      Serial.println("IMU Detected: ICM20602, ADO = 1");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0xAF:
      Serial.println("IMU Detected: ICM20608, ADO = 1");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0xA6:
      Serial.println("IMU Detected: ICM20609, ADO = 1");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0x98:
      Serial.println("IMU Detected: ICM20689, ADO = 1");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0x20:
      Serial.println("IMU Detected: ICM20690, ADO = 1");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0xFF:
      break;
    default:
      Serial.print("Unknown: 0x");
      Serial.println("----------------------------------");
      Serial.println(readByte(0x69, 0x00), HEX);
      delay(2000);
      return;
      break;
  }
  switch (readByte(0x69, 0x00)) {
    case 0xE0:
      Serial.println("IMU Detected: ICM20648, ADO = 1");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0xE1:
      Serial.println("IMU Detected: ICM20649, ADO = 1");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0xEA:
      Serial.println("IMU Detected: ICM20948, ADO = 1");
      Serial.println("3 Axis Gyro, 3 Axis Accelerometer, 3 Axis Magnetometer");
      Serial.println("----------------------------------");
      delay(2000);
      return;
      break;
    case 0xFF:
      Serial.println("No IMU detected");
      delay(2000);
      break;
    default:
      Serial.print("Unknown: 0x");
      Serial.println("----------------------------------");
      Serial.println(readByte(0x69, 0x00), HEX);
      delay(2000);
      return;
      break;
  }

}

uint8_t readByte(uint8_t address, uint8_t subAddress)
{
  uint8_t data;                            // `data` will store the register data
  Wire.beginTransmission(address);         // Initialize the Tx buffer
  Wire.write(subAddress);                  // Put slave register address in Tx buffer
  Wire.endTransmission(false);             // Send the Tx buffer, but send a restart to keep connection alive
  Wire.requestFrom(address, (uint8_t) 1);  // Read one byte from slave register address
  data = Wire.read();                      // Fill Rx buffer with result
  return data;                             // Return data read from slave register
}
