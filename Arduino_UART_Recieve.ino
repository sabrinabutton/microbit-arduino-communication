#include <MotorController.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
#define SSD1306_LCDHEIGHT 128
#define SSD1306_LCDWIDTH  64


//Define the states of the machine
#define STOP_S 0
#define WAIT_STOP_S 1
#define FORWARD_S 2
#define MOVE_FORWARD_S 3
#define LEFT_S 4
#define TURN_LEFT_S 5
#define RIGHT_S 6
#define TURN_RIGHT_S 7

//MOTOR CONTROLLER
#define dirBPin 4 // direction //R
#define pwmBPin 3 // speed
#define dirAPin  12 // direction //L
#define pwmAPin  11 // speed
MotorController mc(dirAPin, pwmAPin, dirBPin, pwmBPin, 1, 1);
Adafruit_SSD1306 display(OLED_RESET);

char motion_command;

uint8_t fsm_state = STOP_S;
int move_cnt;

#define runEvery(t) for (static typeof(t) _lasttime;(typeof(t))((typeof(t))millis() - _lasttime) > (t);_lasttime += (t))

void setup() {
  
  Serial.begin(9600);
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);

  display.setCursor(0, 0);
  display.print("ON");
  display.clearDisplay();
  display.display();
  Serial.println(F("Exp 0.1"));

}

void loop() {
    
  if (Serial.available()) 
  {
      /*display.setCursor(0, 20);
    display.println("Waiting for String...");
      display.display();
    delay(2500); //allows all serial sent to be received together*/
    
      motion_command = Serial.read();
      
      if (motion_command == 'G')
      {
        fsm_state = FORWARD_S;
      }
      else if (motion_command == 'S')
      {
        fsm_state = STOP_S;
      }
      else if (motion_command == 'L')
      {
        fsm_state = TURN_LEFT_S;
      }
      else if (motion_command == 'R')
      {
        fsm_state = TURN_RIGHT_S;
      }
      else 
      {
        motion_command = 'E';
        fsm_state = STOP_S;
      }

      Serial.setCursor(0, 40);
        Serial.clearDisplay();
    Serial..print("Command recieved: ");
    display.println(motion_command);
      display.display();
      delay(3000);
 }
 
 // runEvery(50) {
      //state machine
      switch (fsm_state)
      {
        case STOP_S:  //Statements to execute
          //move_cnt = 100;
          mc.move(0,0);
          //fsm_state = WAIT_STOP_S;
          //Serial.println(F("Stop"));

          break;
        /*case WAIT_STOP_S:
         // move_cnt--;
          //if(move_cnt == 0) {
            // fsm_state = FORWARD_S;
         // }
          break;*/
        case FORWARD_S:   //Statements to execute
          //move_cnt = 100;
          mc.move(255,255);
          //fsm_state = MOVE_FORWARD_S;
          //Serial.println(F("Go"));

          break;
        /*case MOVE_FORWARD_S:   //Statements to execute
          move_cnt--;
          // if == zero - then go forward
          if(move_cnt == 0) {
             fsm_state = STOP_S;
          }
          break;*/
        case LEFT_S:
          //move_cnt = 100;
          mc.move(255,0);
          //fsm_state = TURN_LEFT_S;
          //Serial.println(F("LEFT"));

          break;
        /*case TURN_LEFT_S:
          // decrement turn counter
          move_cnt--;
          // if == zero - then go forward
          if(move_cnt == 0) {
             fsm_state = STOP_S;
          } 
         break;*/
        case RIGHT_S:
          //move_cnt = 100;
          mc.move(0,255);
          //fsm_state = TURN_RIGHT_S;
          //Serial.println(F("RIGHT"));

          break;
        /*case TURN_RIGHT_S:
          // decrement turn counter
          move_cnt--;
          // if == zero - then go forward
          if(move_cnt == 0) {
             fsm_state = FORWARD_S;
          } 
         break;*/
      
      }
     
 // }
  
  /*display.clearDisplay();
    display.setCursor(0, 0);
  display.println("Waiting for Serial...");
    display.display();
      delay(1000);*/

}
