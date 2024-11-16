#include <Keyboard.h>
#include <KeyboardLayout.h>
#include <Arduino.h>
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>

/* Make sure to download all the necessary libraries in order to run this code. Arduino IDE is reccomended. */


void setup() {

  /* Initialize the Receiver. Baud rate MUST be 115200 or else verification outputs will be incomprehensible. */

  Serial.begin(115200);
  Serial.println("Receiver Initiated.");
  printActiveIRProtocols(&Serial);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Keyboard.begin();

}

void loop() {

   if (IrReceiver.decode()) {

        Serial.println();

        /* Error handler, allows for more precise inputs. */

        if (IrReceiver.decodedIRData.command == UNKNOWN) {
          Serial.println("Noise. Reposition Transmitter.");
          IrReceiver.printIRResultRawFormatted(&Serial, true);
          IrReceiver.resume();
        } else {
          IrReceiver.resume(); 

        }

        /* Controller 1 receiver code */

        if (IrReceiver.decodedIRData.command == 0x60) {
          Serial.println("UP button pressed.");
          Keyboard.press('W');
          Keyboard.release('W');

        }
        else if (IrReceiver.decodedIRData.command == 0x61) {
          Serial.println("DOWN button pressed.");
          Keyboard.press('S');
          Keyboard.release('S');

        } 
        else if (IrReceiver.decodedIRData.command == 0x65) {
          Serial.println("LEFT button pressed.");
          Keyboard.press('A');
          Keyboard.release('A');

        } 
        else if (IrReceiver.decodedIRData.command == 0x62) {
          Serial.println("RIGHT button pressed.");
          Keyboard.press('D');
          Keyboard.release('D');

        } 
        else if (IrReceiver.decodedIRData.command == 0x6C) {
          Serial.println("A button pressed.");
          Keyboard.press('B');
          Keyboard.release('B');

        } 
        else if (IrReceiver.decodedIRData.command == 0x14) {
          Serial.println("B button pressed.");
          Keyboard.press('Q');
          Keyboard.release('Q');

        } 
        
        /* Controller 2 receiver code */

        else if (IrReceiver.decodedIRData.command == 0xC) {
          Serial.println("UP button pressed.");
          Keyboard.press('I');
          Keyboard.release('I');

        } 
        else if (IrReceiver.decodedIRData.command == 0xD) {
          Serial.println("DOWN button pressed.");
          Keyboard.press('K');
          Keyboard.release('K');

        } 
        else if (IrReceiver.decodedIRData.command == 0xA) {
          Serial.println("LEFT button pressed.");
          Keyboard.press('J');
          Keyboard.release('J');

        } 
        else if (IrReceiver.decodedIRData.command == 0xE) {
          Serial.println("RIGHT button pressed.");
          Keyboard.press('L');
          Keyboard.release('L');
          
        }
        else if (IrReceiver.decodedIRData.command == 0x8) {
          Serial.println("A button pressed.");
          Keyboard.press('B');
          Keyboard.release('B');
          
        }
        else if (IrReceiver.decodedIRData.command == 0x9) {
          Serial.println("B button pressed.");
          Keyboard.press('Q');
          Keyboard.release('Q');
          
        } 

        /* Both controllers have different receiver codes to allow for multiple controller usage. */
    }
}

/*

    To add controllers, copy the code structure below and replace 0xFF with the hexadecimal values outputted by your remote. 
    To change the keyboard input, replace 'KEY' with any key on your keyboard currently not present in the code. 
    Use IRremote tester code to determine the hexadecimal values (Go to File > Examples > IRremote > SimpleReceiver.ino). 
    Make sure to un-comment the #define DECODE for the remote brand you are using for accurate reading. 


        if (IrReceiver.decodedIRData.command == 0xFF) {
          Serial.println("UP button pressed.");
          Keyboard.press('KEY');
          Keyboard.release('KEY');

        }
        else if (IrReceiver.decodedIRData.command == 0xFF) {
          Serial.println("DOWN button pressed.");
          Keyboard.press('KEY');
          Keyboard.release('KEY');

        } 
        else if (IrReceiver.decodedIRData.command == 0xFF) {
          Serial.println("LEFT button pressed.");
          Keyboard.press('KEY');
          Keyboard.release('KEY');

        } 
        else if (IrReceiver.decodedIRData.command == 0xFF) {
          Serial.println("RIGHT button pressed.");
          Keyboard.press('KEY');
          Keyboard.release('KEY');

        } 
        else if (IrReceiver.decodedIRData.command == 0xFF) {
          Serial.println("A button pressed.");
          Keyboard.press('KEY');
          Keyboard.release('KEY');

        } 
        else if (IrReceiver.decodedIRData.command == 0xFF) {
          Serial.println("B button pressed.");
          Keyboard.press('KEY');
          Keyboard.release('KEY');

        }



*/



