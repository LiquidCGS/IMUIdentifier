# IMUIdentifier
Tiny program to identify what type of Invsense IMU you got

Any arduino with an i2c bus and a serial output can run this.


Do be aware that MPU9150's will report as 6050s, this is because a 9150 is a 6050 with a magnetometer so if you have a 9250 board and it reports as a 6050, it's most likely a 9150.

This code will check for an IMU when reset and, if one is found, it will report what it is. To re run the check without resetting the Arduino, pull pin 4 to GND.

Curently supported IMU's are:

* MPU3050
* MPU6050           
* MPU6500           
* MPU9250           
* MPU9255           
* ICG20330          
* IAM20380          
* IAM20381          
* ICM20600          
* ICM20601          
* ICM20602          
* ICM20608-G        
* ICM20609          
* ICM20648          
* ICM20649
* ICG20660
* IAM20680
* IAM20680HP
* ICM20689
* ICM20690
* ICM20948
* ICM40627 
* IIM42351
* IIM42352
* ICM42605 
* IIM42652  
* ICM42670-P
* ICM42688-V