/*
 # Editor : Phoebe
 # Date   : 2012.11.6
 # Ver    : 0.1
 # Product: Cherokey 4WD Mobile Platform
 # SKU    : RBO0102
   
 # Description:     
 # Drive 2 motors with this Cherokey 4WD Mobile Platform  
 # Connect the D4,D5,D6,D7 to UNO digital 4,5,6,7
 
*/
#include <Servo.h> 

int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;     //M1 Direction Control
int M2 = 7;     //M1 Direction Control

int sensorPin = 1;  //Sharp se  nsor pin
int headServo = 9;
int servoPos = 74;
int servoDirection = 0;
Servo myservo;

boolean obstacle = false;

void setup(void) 
{ 
  // attach servo
  myservo.attach(headServo);
  
  // init motors
  int i;
  for(i=4;i<=7;i++)
    pinMode(i, OUTPUT);  
  
  // init communication
  Serial.begin(9600);
  Serial1.begin(9600);      //Set Baud Rate
  Serial1.println("Run keyboard control");
  
  // init pins
  digitalWrite(E1,LOW);   
  digitalWrite(E2,LOW); 
  pinMode(2,INPUT);
  pinMode(3,INPUT);
} 

void loop(void) 
{
  if(!Listen()){ 
    MoveHead();
    Explore();
    Serial.println("test...");
    delay(1);
  }
}
