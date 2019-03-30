/* Servo Learning
by Brandon Stuhlmueller <signsbystu.com>
This is my first program
29 March 2019
 */
#include <Servo.h>
Servo servoA; //creates a servo object called servoa this allows you to conrol it by calling it servoA later
int pos = 0; //variable to store the servo position
const int redPin = 12; //pin the red LED is connected to
const int greenPin = 13; //pin the yellow LED is connected to
const int bluePin = 11; //pin for blue LED 
const int buttonPin = 2; //pushbutton pin
int buttonState = 0; //variable for reading pushbutton status

void setup() {
  servoA.attach(9); // this attaches the name servoA to pin 9 on the arduino
  pinMode(buttonPin, INPUT); // set the pushbutton input pin
  pinMode(redPin, OUTPUT); // initialize the LED pin as an output
  pinMode(greenPin, OUTPUT); // initialize the LED pin as an output
  pinMode(bluePin, OUTPUT); // initialize the LED pin as an output
  Serial.begin(9600);//start serial port
  randomSeed(analogRead(0));  //start number generator using pin A0
}

void loop() {
  buttonState = digitalRead(buttonPin); //read state of button with digitalRead and store value in buttonState
  if (buttonState == HIGH){ //checks state of button
  digitalWrite(redPin, HIGH); //Roxanne turn on the red light - keep it on until button is pressed
  digitalWrite(greenPin, LOW); //make sure the green light is off when button is high
  } else {
    digitalWrite(greenPin, HIGH); //turn on the green light
    digitalWrite(redPin, LOW); //turn off the reeeed lighhhttt
    pos = random(0,180); //generate random number from 0-180
    delay(275); //set a delay so the number has time to generate and get loaded
    Serial.print("button pressed");
    Serial.print("Random Number");
    Serial.println(pos);
    servoA.write(pos);
    delay (500);
  } 
}
