/**********************************************************************************************
*   Program for Microbit to Send information to the Arduino for Movement                      *
***********************************************************************************************/
// serial setup...
serial.redirect(
    SerialPin.P0,
    SerialPin.P1,
    BaudRate.BaudRate9600
)
// when Microbit recieves string from other Microbit...
radio.onReceivedString(function (receivedString) {
    // if Microbit recieves "G"
    if (receivedString = "G") {
        //write "G" to serial
        serial.writeString("G")
    }
    // if Microbit recieves "S"
    if (receivedString = "S") {
        //write "S" to serial
        serial.writeString("S")
    }
    // if Microbit recieves "L"
    if (receivedString = "L") {
        //write "L" to serial
        serial.writeString("L")
    }
    // if Microbit recieves "R"
    if (receivedString = "R") {
        //write "r" to serial
        serial.writeString("R")
    }
})
