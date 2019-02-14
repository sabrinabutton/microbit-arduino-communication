input.onButtonPressed(Button.A, function () {
    serial.writeString("Hi")
})
serial.redirect(
SerialPin.P0,
SerialPin.P1,
BaudRate.BaudRate9600
)
basic.forever(function () {
	
})
