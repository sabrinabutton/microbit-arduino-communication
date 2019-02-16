/**********************************************************************************************
*   Program for Microbit to Send information to another Microbit to communicate with Arduino  *
***********************************************************************************************/
//set variable "motor_on" which checks whether the robot's motors are running to 0, indicating it is not on
let motor_on = 0

//when A and B are pressed... 
input.onButtonPressed(Button.AB, function () {
    //if the motor is off
    if (motor_on = 0) {
        //tell other microbit to send "G" for go
        radio.sendString("G")
    }
    //if the motor is on
    if (motor_on = 1) {
        //tell other microbit to send "G" for stop
        radio.sendString("S")
    }
})

//if A is pressed (left button)
input.onButtonPressed(Button.B, function () {
    //tell other microbit to send "R" for right
    radio.sendString("R")
})

//if B is pressed (right button)
input.onButtonPressed(Button.A, function () {
    //tell other microbit to send "L" for left
    radio.sendString("L")
})
