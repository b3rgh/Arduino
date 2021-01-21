/*

    This sketch reads accelerometer of 9DOF IMU at 100 Hz
    and is based on the Adafruit 9DOF Tester example

    Using:
      Adafruit 9-DOF IMU Breakout - L3GD20H + LSM303
      https://www.adafruit.com/product/1714
      Arduino Uno
      
      Adafruit Sensor library
      Adafruit LSM303 library
      Adafruit L3GD20 library
      Adafruit 9DOF library

    Connect & setup the IMU:
    https://learn.adafruit.com/adafruit-9-dof-imu-breakout

*/

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_L3GD20_U.h>
#include <Adafruit_9DOF.h>


Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(30301);  // Accelerometer
// Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(30302);  // Magnetometer
// Adafruit_L3GD20_Unified gyro = Adafruit_L3GD20_Unified(20);  // Gyroscope

/** Displays basic sensor information including: min, max, resolution, and units.
 */
void displaySensorDetails(void) {
  sensor_t sensor;
  
  // Accelerometer details
  accel.getSensor(&sensor);
  Serial.println(F("----------- ACCELEROMETER ----------"));
  Serial.print  (F("Sensor:       ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:   ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:    ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:    ")); Serial.print(sensor.max_value); Serial.println(F(" m/s^2"));
  Serial.print  (F("Min Value:    ")); Serial.print(sensor.min_value); Serial.println(F(" m/s^2"));
  Serial.print  (F("Resolution:   ")); Serial.print(sensor.resolution); Serial.println(F(" m/s^2"));
  Serial.println(F("------------------------------------"));
  Serial.println(F(""));
  
  // Magnetometer details
  /*mag.getSensor(&sensor);
  Serial.println(F("----------- MAGNETOMETER -----------"));
  Serial.print  (F("Sensor:       ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:   ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:    ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:    ")); Serial.print(sensor.max_value); Serial.println(F(" uT"));
  Serial.print  (F("Min Value:    ")); Serial.print(sensor.min_value); Serial.println(F(" uT"));
  Serial.print  (F("Resolution:   ")); Serial.print(sensor.resolution); Serial.println(F(" uT"));  
  Serial.println(F("------------------------------------"));
  Serial.println(F(""));*/
  
  // Gyroscope details
  /*gyro.getSensor(&sensor);
  Serial.println(F("------------- GYROSCOPE -----------"));
  Serial.print  (F("Sensor:       ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:   ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:    ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:    ")); Serial.print(sensor.max_value); Serial.println(F(" rad/s"));
  Serial.print  (F("Min Value:    ")); Serial.print(sensor.min_value); Serial.println(F(" rad/s"));
  Serial.print  (F("Resolution:   ")); Serial.print(sensor.resolution); Serial.println(F(" rad/s"));
  Serial.println(F("------------------------------------"));
  Serial.println(F(""));*/
  
  delay(500);
}

void setup(void)
{
  Serial.begin(115200);
  Serial.println(F("Read accelerometer at 100 Hz")); Serial.println("");
  
  // Accelerometer initialization
  if (!accel.begin()) {
    // There was a problem detecting the ADXL345 ... check your connections
    Serial.println(F("Ooops, no LSM303 detected ... Check your wiring!"));
    while (1);
  }

  // Magnetometer initialization
  /*if (!mag.begin()) {
    // There was a problem detecting the LSM303 ... check your connections
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    while(1);
  }*/

  // Gyroscope initialization
  /*if (!gyro.begin()) {
    // There was a problem detecting the L3GD20 ... check your connections
    Serial.print("Ooops, no L3GD20 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }*/
  
  displaySensorDetails();
}

void loop(void)
{
  // get timestamp
  unsigned long t = millis();  // milliseconds since start

  // get sensor event
  sensors_event_t event;

  Serial.print(t); Serial.print("  "); // timestamp of reading (ms since start)
  
  // Accelerometer reading (acceleration is measured in m/s^2)
  accel.getEvent(&event);
  Serial.print(event.acceleration.x); Serial.print("  ");  // X in m/s^2
  Serial.print(event.acceleration.y); Serial.print("  ");  // Y in m/s^2
  Serial.print(event.acceleration.z); Serial.print("  ");  // Z in m/s^2
  Serial.println("");

  // Magnetometer reading (magnetic vector values are in micro-Tesla (uT))
  /*mag.getEvent(&event);
  Serial.print(event.magnetic.x); Serial.print("  ");  // X in uT
  Serial.print(event.magnetic.y); Serial.print("  ");  // Y in uT
  Serial.print(event.magnetic.z); Serial.print("  ");  // Z in uT
  Serial.println("");*/

  // Gyroscope reading (gyrocope values in rad/s)
  /*gyro.getEvent(&event);
  Serial.print(event.gyro.x); Serial.print("  ");  // X in rad/s
  Serial.print(event.gyro.y); Serial.print("  ");  // Y in rad/s
  Serial.print(event.gyro.z); Serial.print("  ");  // Z in rad/s
  Serial.println("");*/


  while (millis() - t <= 9) {
    // wait
    // 9ms results in ~100 Hz sampling frequency
  }

}
