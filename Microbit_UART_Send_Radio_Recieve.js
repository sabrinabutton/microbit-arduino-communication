/**********************************************************************************************
*   Program for Microbit to Send information to the Arduino for Movement                      *
***********************************************************************************************/
radio.setGroup(1)
// serial setup...
serial.redirect(
    SerialPin.P0,
    SerialPin.P1,
    BaudRate.BaudRate9600
)
// when Microbit recieves string from other
radio.onReceivedString(function (receivedString) {
    // write recievedString to serial
    serial.writeString(receivedString)
    if (receivedString == "G") {
        // show user
        basic.showLeds(`
            . . . . .
            . . . . #
            . . . # .
            # . # . .
            . # . . .
            `)
        // pause and clear
        basic.pause(300)
        basic.clearScreen()
    } else if (receivedString == "S") {
        // show user
        basic.showLeds(`
            # . . . #
            . # . # .
            . . # . .
            . # . # .
            # . . . #
            `)
        // pause and clear
        basic.pause(300)
        basic.clearScreen()
    } else if (receivedString == "L") {
        // show user
        basic.showLeds(`
            . . # . .
            . # . . .
            # # # # #
            . # . . .
            . . # . .
            `)
        // pause and clear
        basic.pause(300)
        basic.clearScreen()
    } else if (receivedString == "R") {
        // show user
        basic.showLeds(`
            . . # . .
            . . . # .
            # # # # #
            . . . # .
            . . # . .
            `)
        // pause and clear
        basic.pause(300)
        basic.clearScreen()
    }
})

