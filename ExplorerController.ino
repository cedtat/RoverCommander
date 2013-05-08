/*
    This code has been inspired by an article from Dominique Meurisse : http://arduino103.blogspot.fr/2011/06/detecteur-de-proximite-infrarouge-sharp.html
*/

float readVoltage(){
  // Read voltage value
  // Convert value between 0->1024 in voltage 0->5v
  int val = analogRead(sensorPin);  
  float voltage = val * 5.0;
  voltage /= 1024.0; 

  return voltage;
}

// Basic tab conversion between voltage and distance
float sharpVoltage[] = { 
  3.1, 2.5, 1.84, 1.42, 1.15, 1, 0.85, 0.73, 0.5, 0.4, 0.3 };     
int sharpCms[] = { 
  5, 10, 15, 20, 25, 30, 40, 50, 60, 70, 80 };

//Description:
//  Read voltage on analogic pin and determine distance 
//
//Returns:
//  Above tab index corresponding to distance givng an approximate range
//

int distanceIndex(){
  float voltage = readVoltage();
  
  // if voltage is < 0.3, it is difficult to know if distance is very low or far, we return an unknown value
  if( voltage < 0.3 )
    return -1;
    
  // Return corresponding index
  int index = 0;
  while( sharpVoltage[index] > voltage ){
    index++;
    // if value is above range, we return an unknown value
    if( index == 11 )
      return -1;
  }
  return index;
}


//Description:
//  return a string providing distance information
String distanceRange(){
  int idx = distanceIndex();
  if( idx == -1 )
    return "Unknown";
  if( idx == 0 ) {       
    return "<= "+String(int(sharpCms[idx]));
  }
  return String(int(sharpCms[idx-1]))+"> x <="+String(int(sharpCms[idx]));
}


void Explore(){

  // read distance index
  int idx = distanceIndex();


  // if distance outside 5 - 20 cm range
  if(idx>4 || idx<0){
    obstacle = false;
    advance (100,100); 
  }
  else{
    
    // too close, distance < 15 cm
    if(idx<=1){
      back_off (100,100);
    }
    // ok turn
    else{
      
      obstacle = true;
      
      // turn depending on servo middle position (here 74)
      if(servoPos > 74){
        turn_R (200,200); 
        
        // force servo to turn in the direction of the obstacle
        servoDirection = 0;
      }
      else{
        turn_L (200,200);
     
        // force servo to turn in the direction of the obstacle
        servoDirection = 1;
      }
    }
  }
}

