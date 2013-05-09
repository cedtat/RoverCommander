/*
  # This function is only incrementing servo position in the provided direction
  # Servo is incremented only if there is no obstacle to search one
  # if there is an obstacle, servo is stopping to help robot go away from obstacle
*/
#include <Servo.h> 


int headServo = 9;       // Head servo pin
int servoPos;            // Servo position variable
int servoLeft = 120;     // max servo position to look at left
int servoRight = 20;     // max servo position to look at right
int servoDirection = 0;  // used to revert direction 0 or 1
Servo myservo;           // head servo object

void initHead(){
  // attach servo
  myservo.attach(headServo); 
}

int GetPosition(){
  return servoPos;
}

void SetServoDirection(int dir){
  servoDirection = dir;
}

void MoveHead(){
 
  if(!obstacle){
    if(servoPos > 120)
      servoDirection = 1;
    
    if(servoPos < 20)
      servoDirection = 0;
    
    // increment servo position
    if(servoDirection == 0)
       servoPos++;
    else
       servoPos--;
       
    myservo.write(servoPos);                  
    delay(5);
  }
}
