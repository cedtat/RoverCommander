/*
  # This is a basic rover project, just for fun.
  # See it in action here : https://www.youtube.com/edit?video_id=AGPDNHpR9hc
*/

#include <Servo.h> 

int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;     //M1 Direction Control
int M2 = 7;     //M1 Direction Control

int sensorPin = 1;  // Sharp sensor pin
int headServo = 9;  // Head servo pin
int servoPos = 74;  // Init servo in middle position

int servoDirection = 0; // used to revert direction 0 or 1
Servo myservo;          // head servo object

boolean obstacle = false; // true when an obstacle is detected within a particular range

void setup(void) 
{ 
  // attach servo
  myservo.attach(headServo);
  
  // init motors
  int i;
  for(i=4;i<=7;i++)
    pinMode(i, OUTPUT);  
  
  // init communication
  Serial.begin(9600);      // Communication via USB
  Serial1.begin(9600);     // Communication via Bluetooth or whatever on Serial1
  
  // init pins
  digitalWrite(E1,LOW);   
  digitalWrite(E2,LOW); 
  pinMode(2,INPUT);
  pinMode(3,INPUT);
} 

void loop(void) 
{
  if(!Listen()){ 
    // if keyboard mode is not active
    
    // increment head rotation
    MoveHead();
    
    // explore algorythm
    Explore();
    
    // stability ??
    delay(1);
  }
}
