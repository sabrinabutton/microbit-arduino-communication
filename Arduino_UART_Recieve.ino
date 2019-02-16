#include <MotorController.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
#define SSD1306_LCDHEIGHT 128
#define SSD1306_LCDWIDTH  64
Adafruit_SSD1306 display(OLED_RESET);

char motion_command;

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

}

void loop() {
  
  int i = 0;
  
  display.clearDisplay();
    display.setCursor(0, 0);
  display.println("Waiting for Serial...");
    display.display();
      delay(1000);
  
  if (Serial.available()) 
  {
      display.setCursor(0, 20);
    display.println("Waiting for String...");
      display.display();
    delay(2500); //allows all serial sent to be received together
    while (Serial.available() && i < 1) 
    {
      motion_command = Serial.read();
      
      if (motion_command == "G")
      {
        
      }
      else if (motion_command == "S")
      {
        
      }
      else if (motion_command == "L")
      {
        
      }
      else if (motion_command == "R")
      {
        
      }
      else 
      {
        motion_command = "Error";
      }
    
  }   

  if (i > 0) 
  {
      display.setCursor(0, 40);
        display.clearDisplay();
    display.println("Command recieved!", motion_command);
      display.display();
      delay(3000);
  }
  
}
