/**********************************************************************************************
*   Program for Microbit to Send information to another Microbit to communicate with Arduino  *
***********************************************************************************************/
input.onGesture(Gesture.Shake, function () {
    // tell other microbit to send "G" for go
    radio.sendString("G")
    basic.showLeds(`
        . . . . .
        . . . . #
        . . . # .
        # . # . .
        . # . . .
        `)
})
// if A is pressed (left button)
input.onButtonPressed(Button.B, function () {
    // tell other microbit to send "R" for right
    radio.sendString("R")
    basic.showLeds(`
        . . # . .
        . . . # .
        # # # # #
        . . . # .
        . . # . .
        `)
})
// when A and B are pressed...
input.onButtonPressed(Button.AB, function () {
    // tell other microbit to send "G" for stop
    radio.sendString("S")
    basic.showLeds(`
        # . . . #
        . # . # .
        . . # . .
        . # . # .
        # . . . #
        `)
})
// if B is pressed (right button)
input.onButtonPressed(Button.A, function () {
    // tell other microbit to send "L" for left
    radio.sendString("L")
    basic.showLeds(`
        . . # . .
        . # . . .
        # # # # #
        . # . . .
        . . # . .
        `)
})
