/* Servo Learning
by Brandon Stuhlmueller <signsbystu.com>
This is my first program
29 March 2019
 */
#include <Servo.h>

Servo servoA; //creates a servo object called servoa this allows you to conrol it by calling it servoa later
int run;
const int buttonPin = 2; //pushbutton pin
const int redPin = 12; //pin the red LED is connected to
const int greenPin = 13; //pin the yellow LED is connected to

int counter = 0; //variable to keep track of button presses
int pos = 0; //variable for position of servo
int buttonState = 0; //variable for reading pushbutton status

void setup() {
  run = 0; //program does not move until button pressed
  servoA.attach(9); // this attaches the name servoA to pin 9 on the arduino
  pinMode(buttonPin, INPUT); // set the pushbutton input pin
  pinMode(redPin, OUTPUT); // initialize the LED pin as an output
  pinMode(greenPin, OUTPUT); // initialize the LED pin as an output
  Serial.begin(9600);//start serial port
  randomSeed(analogRead(0));  //start number generator using pin A0
}

void loop() {
  int buttonState; // local variable to hold the pushbutton state
  buttonState = digitalRead(buttonPin); //read state of button with digitalRead and store value in buttonState
  
  if (buttonState == HIGH){ //Roxanne turn on the red light - keep it on until button is pressed
  digitalWrite(redPin, HIGH); //turn on the reeeed lighhhttt
  } else {
    digitalWrite(redPin, LOW); //ok you can turn off the red light
  } 
  if (buttonState == LOW) {// turn on green led and move servoA
  {
    counter++;
    delay(150);
  } 
  if(counter == 0)
    servoA.write (20);  // zero degrees
  else if(counter == 1)
    servoA.write(180);
  else if(counter == 2)
    servoA.write (150); 
  else if(counter == 3)  
    servoA.write (180);
  //else reset the counter to 0 which resets the servo to 0 degrees
  else
   counter = 0;
 // turn green LED on:
    digitalWrite(greenPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(greenPin, LOW);
  }
}
