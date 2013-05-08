/*
  # This script is listening to keyboard on Serial1
  # Before sending navigation command you must stop roaming mode with 'x'
  # To enter back in romaing mode, send 'r'
*/

boolean listening = false ;

boolean Listen(){

  
  if(Serial1.available()){
    char val = Serial1.read();
    if(val != -1)
    {
      switch(val)
      {
      case 'z'://Move Forward
        advance (255,255);   //move forward in max speed
        Serial1.println("Moving forward");
        break;
      case 's'://Move Backward
        back_off (255,255);   //move back in max speed
        Serial1.println("Moving backward");
        break;
      case 'q'://Turn Left        
        turn_L (255,255);        
        Serial1.println("Turning left");
        break;       
      case 'd'://Turn Right        
        turn_R (255,255);
        Serial1.println("Turning right");
        break;
      case 'h':
        Serial1.println("Hello");
        break;
      case 'x':
        stop();
        Serial1.println("Stoping roaming");
        listening = true;
        break;
      case 'r':
        stop();
        listening = false;
        Serial1.println("Begin roaming");
        break;
      
      }
    }
    else{
      stop();
      Serial1.println("Stop !");  
    }
  } 
  
  return listening;
}
