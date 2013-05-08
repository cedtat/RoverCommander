/*
  # This function is only incrementing servo position in the provided direction
  # Servo is incremented only if there is no obstacle to search one
  # if there is an obstacle, servo is stopping to help robot go away from obstacle
*/
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
