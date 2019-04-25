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
    basic.pause(200)
    basic.clearScreen()
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
    basic.pause(200)
    basic.clearScreen()
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
    basic.pause(200)
    basic.clearScreen()
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
    basic.pause(200)
    basic.clearScreen()
})
radio.setGroup(1)
