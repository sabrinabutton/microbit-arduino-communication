/*
  Arduino Starter Kit example
  Project 5 - Servo Mood Indicator

  This sketch is written to accompany Project 5 in the Arduino Starter Kit

  Parts required:
  - servo motor
  - 10 kilohm potentiometer
  - two 100 uF electrolytic capacitors

  created 13 Sep 2012
  by Scott Fitzgerald

  http://www.arduino.cc/starterKit

  This example code is part of the public domain.
*/

// include the Servo library
//#include <Servo.h>

//Servo myServo;  // create a servo object
// Motor Control library
#include <MotorController.h>
#include <SPI.h>
#include <Wire.h>
//#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
#define SSD1306_LCDHEIGHT 128 
#define SSD1306_LCDWIDTH  64 
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define dirBPin 4 // direction //R
#define pwmBPin 3 // speed
#define dirAPin  12 // direction //L
#define pwmAPin  11 // speed


int const digPin1 = A0;
int const potPin2 = A1;
int const digPin3 = A2;
int const potPin4 = A3;
int const digPin5 = A6;// analog pin used to connect the potentiometer

int digVal1;
int potVal2; 
int digVal3; 
int potVal4; 
int digVal5; // variable to read the value from the analog pin
int leftSpeed, rightSpeed;
int incomingByte = 0;   // for incoming serial data

MotorController mc(dirAPin, pwmAPin, dirBPin, pwmBPin, 1, 1);
void setup() {
 
  //myServo.attach(9); // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // open a serial connection to your computer
  Serial.println("OK, serial started");
  pinMode(digPin1, INPUT);
//  pinMode(potPin2, INPUT);
  pinMode(digPin3, INPUT);
 // pinMode(potPin4, INPUT);
  pinMode(digPin5, INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
    display.setTextColor(WHITE);
  display.setTextSize(1);
  
display.setCursor(0,0);
display.print("ON");
display.display();

}

void loop() {
  digVal1 = digitalRead(digPin1);
  potVal2 = analogRead(potPin2);
  digVal3 = digitalRead(digPin3);
  potVal4 = analogRead(potPin4);
  digVal5 = digitalRead(digPin5);
  // read the value of the potentiometer
  // print out the value to the Serial Monitor
  //dark digital=1, pot=<50
  //white digital=0, pot=>50
  
  //if on the line
 if (digVal3)
  //if only middle is dark, both motors same speed (goes straight)
 {
  leftSpeed=155;
  rightSpeed=195;
  
 if (potVal4>400)
 { //if middle left is dark but left is light, slow left some
  leftSpeed=140;
  rightSpeed=180;
 }
  if (potVal2>400)
 { //if middle right is dark but right is light, slow right some
  leftSpeed=135; //fast speed
  rightSpeed=155;
 }
 }
 else 
 {
   if (potVal4>potVal2)
   {
     leftSpeed=0;
     rightSpeed=195;
   }
   else
   {
     leftSpeed=155;
     rightSpeed=0;
   }
 }
  
 display.clearDisplay();
 display.setCursor(0,10);
 display.print(potVal4);
 display.print("   ")
 display.print(digVal3);
 display.print("   ");
 display.print(potVal2);
 display.setCursor(0,20);
 display.print("RS:  ");
 display.print(rightSpeed);
 display.print("   ");
 display.print("LS:  ");
 display.print(leftSpeed);
 

        // send data only when you receive data:
        while (Serial.available() > 0) {
                // read the incoming byte:
               // incomingByte = Serial.parseInt();

                // say what you got:
               // display.println("Hello!");
              
                if (Serial.read() == 'i') {
                   //Serial.println("Hello!");
                 // Serial.println(incomingByte, DEC);
                  
 Serial.print(potVal4);
 Serial.print("   ");
 Serial.print(digVal3);
 Serial.print("   ");
 Serial.print(potVal2);
 Serial.print("RS:  ");
 Serial.print(rightSpeed);
 Serial.print("   ");
 Serial.print("LS:  ");
 Serial.print(leftSpeed);
 Serial.print("\r");
                }
        }
                 
  mc.move(rightSpeed, leftSpeed);
  display.display();

  // set the servo position
 // myServo.write(angle);

  // wait for the servo to get there
  delay(10);
}
