void MoveHead(){
 /*
  myservo.write(20);                  // sets the servo position according to the scaled value 
  delay(600);                         // waits for the servo to get there 
  myservo.write(120);
  delay(600);
 */
 
  if(!obstacle){
    if(servoPos > 120)
      servoDirection = 1;
    
    if(servoPos < 20)
      servoDirection = 0;
    
    
    if(servoDirection == 0)
       servoPos++;
    else
       servoPos--;
       
    myservo.write(servoPos);                  // sets the servo position according to the scaled value  
    delay(5);
  }
}
