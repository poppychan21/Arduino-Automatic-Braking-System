//www.elegoo.com
//2016.12.09
//Kim Han Nguyen
// Joystick and Servo combined
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
const int buzzer = 12;

int pos = 0;    // variable to store the servo position

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  
  pinMode(buzzer, OUTPUT);
  
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // Serial.print() means to ouput the statement like cout
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");

  // using the map() function, this maps the specific pin to the directions that will rotate
  // within its ranges.
  // Use one of the axis of the joystick to control the servo: X-AXIS
  // [datatype] variable = map(values, x-axis[fromLow], y-axis[fromHigh], in-degrees[toLow], in-degrees[toHigh])
  // value's current range and target range in degrees
  int val = analogRead(X_pin);
  val = map(val, 0, 1023, 0, 180); 
  myservo.write(val);
  
  Buzzer();
  
  delay(15);
}
void Buzzer() 
{
 if (digitalRead(SW_pin) == LOW)
{
  digitalWrite(buzzer, HIGH);
}
 else
{
  digitalWrite(buzzer, LOW);
}
}
