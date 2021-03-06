/**
 * @file  ultraSonicSensor.cpp
 * @brief 超音波センサ処理を記載
 * 
 * @date 2020/12/24 まずcでファイル分割をかく
 */

#include "ultraSonicSensor.h"

/**
 * @brief 超音波センサ初期化
 * 
 */
bool ultraSonicSensorInitialize(){
  pinMode(Trig_PIN, OUTPUT); 
  pinMode(Echo_PIN,INPUT); 

  /*init buzzer*/
  digitalWrite(Trig_PIN,LOW);

  return true;
}

/*detection of ultrasonic distance*/
/**
 * @brief 距離測定(HC-SR04センサー)
 * 
 * @sa https://github.com/sparkfun/HC-SR04_UltrasonicSensor
 * 
 * @note 公式と少しコードが違うかも
 * 
 * @return distance[cm]
 */
int ultraSonicSensorWatch(){
  long echo_distance;
  digitalWrite(Trig_PIN,LOW);
  delayMicroseconds(5);                                                                              
  digitalWrite(Trig_PIN,HIGH);
  delayMicroseconds(15);
  digitalWrite(Trig_PIN,LOW);
  echo_distance=pulseIn(Echo_PIN,HIGH);
  echo_distance=echo_distance*0.01657; //how far away is the object in cm
 //Serial.println((int)echo_distance);
  return round(echo_distance);
}