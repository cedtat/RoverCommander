/*
  # This is a basic rover project, just for fun.
  # See it in action here : https://www.youtube.com/edit?video_id=AGPDNHpR9hc
  #
  # this script is distributed under Creative Commons Attribution-ShareAlike 3.0 License
*/

boolean obstacle = false; // true when an obstacle is detected within a particular range

void setup(void) 
{ 

  
  // init communication
  Serial.begin(9600);      // Communication via USB
  Serial1.begin(9600);     // Communication via Bluetooth or whatever on Serial1
  
  initHead();
  initMotor();
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
