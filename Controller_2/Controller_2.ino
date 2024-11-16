#include <Arduino.h>

#if !defined(ARDUINO_ESP32C3_DEV)  
#define DISABLE_CODE_FOR_RECEIVER
#endif

#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>


/* The required libraries are the Arduino library to program the Arduino Nano's used for each controller and the IRremote library 
   which allows for infrared communication. */


const int b1 = 5; //White button
const int b2 = 6; //Black button
const int b3 = 7; //Yellow button
const int b4 = 8; //Green button
const int b5 = 9; //Red button
const int b6 = 10; //Blue button

const int LED = 2; //Indicator LED on D2



void setup() {
  pinMode(b1, INPUT); //White Button
  pinMode(b2, INPUT); //Black Button 
  pinMode(b3, INPUT); //Yellow Button
  pinMode(b4, INPUT); //Green Button
  pinMode(b5, INPUT); //Red Button
  pinMode(b6, INPUT); //Blue Button
  pinMode(LED, OUTPUT); //Indicator LED

  IrSender.begin();
  enableLEDFeedback();

}


/* The buttons are colour coded as per the PCB layout. The white button is the "A" button, the black button is the "B" button, 
   yellow is "LEFT", green is "UP", red is "RIGHT", and blue is "DOWN". Colour coding is purely for recognition, feel free to 
   use different button colours.*/

   
void loop() {
  
  if (digitalRead(b1) == HIGH) {
    IrSender.sendSamsung(0x7, 0x9, 0); // A
    digitalWrite(LED, HIGH);
  }

  if (digitalRead(b2) == HIGH) {
    IrSender.sendSamsung(0x7, 0xA, 0); // B
    digitalWrite(LED, HIGH);
  }

  if (digitalRead(b3) == HIGH) {
    IrSender.sendSamsung(0x7, 0x4, 0); // LEFT
    digitalWrite(LED, HIGH);
  }

  if (digitalRead(b4) == HIGH) {
    IrSender.sendSamsung(0x7, 0x5, 0); // UP
    digitalWrite(LED, HIGH);
  }

  if (digitalRead(b5) == HIGH) {
    IrSender.sendSamsung(0x7, 0x8, 0); // DOWN
    digitalWrite(LED, HIGH);
  }

  if (digitalRead(b6) == HIGH) {
    IrSender.sendSamsung(0x7, 0x6, 0); // RIGHT
    digitalWrite(LED, HIGH);
  }
  
  digitalWrite(LED, LOW);

  delay(50);

}
