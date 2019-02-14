//for microbit to send radio to other microbit which then talks to arduino
input.onButtonPressed(Button.A, function () {
    radio.sendString("L")
})
input.onButtonPressed(Button.B, function () {
    radio.sendString("R")
})
input.onButtonPressed(Button.AB, function () {
    if (true) {
    	
    }
})
