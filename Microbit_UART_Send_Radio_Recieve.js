/**********************************************************************************************
*   Program for Microbit to Send information to the Arduino for Movement                      *
***********************************************************************************************/
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
})
