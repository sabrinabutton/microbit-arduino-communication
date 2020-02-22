// Motor Control library
#include <MotorController.h>

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


uint8_t fsm_state = STOP_S;
int move_cnt;

#define runEvery(t) for (static typeof(t) _lasttime;(typeof(t))((typeof(t))millis() - _lasttime) > (t);_lasttime += (t))
void setup(){
  Serial.begin(9600);
  // software version
  Serial.println(F("Exp 0.1"));

}

void loop(){

   while (Serial.available() > 0) {
                // read the incoming byte:
               int incomingByte = Serial.parseInt();

                // say what you got:
               Serial.println(incomingByte);
              
                switch(incomingByte){
                  case 1:
                    fsm_state = LEFT_S;
                  break;
                  case 2:
                    fsm_state = RIGHT_S;
                  break;
                  case 3:
                    fsm_state = STOP_S;
                  break;
                  case 4:
                    fsm_state = FORWARD_S;
                  break;
                }
   }

  runEvery(50) {
      //state machine
      switch (fsm_state)
      {
        case STOP_S:  //Statements to execute
          move_cnt = 100;
          mc.move(0,0);
          fsm_state = WAIT_STOP_S;
          Serial.println(F("Stop"));

          break;
        case WAIT_STOP_S:
          move_cnt--;
          if(move_cnt == 0) {
             fsm_state = FORWARD_S;
          }
          break;
        case FORWARD_S:   //Statements to execute
          move_cnt = 100;
          mc.move(255,255);
          fsm_state = MOVE_FORWARD_S;
          Serial.println(F("Go"));

          break;
        case MOVE_FORWARD_S:   //Statements to execute
          move_cnt--;
          // if == zero - then go forward
          if(move_cnt == 0) {
             fsm_state = LEFT_S;
          }
          break;
        case LEFT_S:
          move_cnt = 100;
          mc.move(255,0);
          fsm_state = TURN_LEFT_S;
          Serial.println(F("LEFT"));

          break;
        case TURN_LEFT_S:
          // decrement turn counter
          move_cnt--;
          // if == zero - then go forward
          if(move_cnt == 0) {
             fsm_state = RIGHT_S;
          } 
         break;
        case RIGHT_S:
          move_cnt = 100;
          mc.move(0,255);
          fsm_state = TURN_RIGHT_S;
          Serial.println(F("RIGHT"));

          break;
        case TURN_RIGHT_S:
          // decrement turn counter
          move_cnt--;
          // if == zero - then go forward
          if(move_cnt == 0) {
             fsm_state = FORWARD_S;
          } 
         break;
       default:
         break;
      }
     
  }
}