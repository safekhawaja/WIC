/*
 Work Incentive Chair: ESE111 Best Final Project
 
 The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED Screen

    Plug in the power supply w/ Vss/Vcc, either directly or through a breadboard. 
    Plug the contrast pin (Vo), register select pin (RS), Read/Wrte pin, enable pin (E), and 
    the data pins through a breadboard.
    
    The lcd.begin(16,2) command set up the LCD number of columns and rows. For example, if you 
    have an LCD with 20 columns and 4 rows (20x4) you will have to change this to lcd.begin(20x4).

    The lcd.print("--message--") command print a message to first column and row of lcd display. 
    The "message" must have maximum length equal to lcd columns number. For example, for 16 
    columns display max length is equal with 16 and for 20 columns display max length is equal with 20.

    The lcd.setCursor(0,1) command will set cursor to first column of second row. If you have an 
    LCD 20x4 and you want to print a message to column five and third row you have to use lcd.setCursor(4,2).

  created by Saif Khawaja in collaboration with Gaston A.
  modified 26 Dec 2020
  
  By Saif Khawaja

  This code is in the public domain.

  https://github.com/safekhawaja/WIC
*/

//Innclude LCD library
#include <LiquidCrystal.h>

int sensorPins[] = {A0, A1, A2, A3};    // select the input pin for the pressure sensor
int sensorVals[];    // empty array for analog values from sensors

int button = 7;    // select the input pin for the massage button
int massage = 8;    // select the out pin to route to the massage vibrator circuit 

int dispense = 9;    // select the out pin to route to the m&m dispenser circuit 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);    // initialize library with interface pins 

void setup() {
  
  // initializing LCD screen
  lcd.begin(16,2);

  // initializing pressure sensors
  for (int i = 0; i < 4; i = i+ 1 {
      pinMode(sensorPins[i], INPUT);
  }

  pinMode(button, INPUT);    // initializing button mode
  pinMode(massage, OUTPUT);    // initializing button mode
}

void loop() {

  // read the value from the sensor and put in array
  
  for (int i = 0; i < 4; i = i+ 1 {
      sensorVals = analogRead(sensorPins[i]);
  }

  lcd.setCursor(0,0);

  // situation 1: sitting with good posture:
    if (sensorVals[0] < 300) {
      if (sensorVals[1] > 750) {
        if (sensorVals[2] < 600) {
          if (sensorVals[3] > 650) {                        
            lcd.print("Keep it up!");
            // after x amount, m&ms are dispersed 
            delay(300000); // 5 mins
            digitalWrite(9, HIGH);
        }
      }
    }
  }

  // situation 2: sitting with upper back curve posture:
    if (sensorVals[0] < 300) {
      if (sensorVals[1] > 750) {
        if (sensorVals[2] < 600) {
          if (sensorVals[3] < 650) {            
            lcd.print("Sit up straight!");
        }
      }
    }
  }

  // situation 3: sitting with lower back curve posture:
    if (sensorVals[0] > 400) {
      if (sensorVals[1] < 400) {
        if (sensorVals[2] < 400) {
          if (sensorVals[3] < 400) {            
            lcd.print("Lean back!");
        }
      }
    }
  }

  // if button is pressed, start massage
  if (digitalRead(button) = HIGH) {
    digitalWrite(massage, HIGH);
  }

}
