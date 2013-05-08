
float lectureTension(){
  // Lecture de la valeur sur l'entrée analogique
  // Retourne une valeur entre 0->1024 pour 0->5v
  int valeur = analogRead(sensorPin);  

  // Converti la lecture en tension
  float tension = valeur * 5.0;
  tension /= 1024.0; 

  return tension;
}

// Tableaux qui permettent de convertir la tension en distance approximative.
//
float sharpVoltage[] = { 
  3.1, 2.5, 1.84, 1.42, 1.15, 1, 0.85, 0.73, 0.5, 0.4, 0.3 };     
int sharpCms[] = { 
  5, 10, 15, 20, 25, 30, 40, 50, 60, 70, 80 };

//Description:
//  Lecture de la tension sur l'entrée analogique 
//  et determination de la distance approximative
//
//Returns:
//  Index superieur (du tableau) dans lequel se situe la mesure.
//  Par exemple, si l'index retourné est 2, la tension du capteur se situe
//    entre les positions 1 et 2 (soit <=2.3v et >1.7v).
//  La distance est donc située entre 10 et 15 cm.
//
int distanceIndex(){
  float tension = lectureTension();
  // si tension inférieur à 0.3v on est soit très loin, soit très près
  // Donc la distance est considérée comme inconnue
  if( tension < 0.3 )
    return -1;
  // Localiser la position dans le tableau OU la tension
  // lue sur le senseur est plus grande que la valeur du tableau
  // de référence
  int index = 0;
  while( sharpVoltage[index] > tension ){
    index++;
    // Si on sort du tableau, la distance est inconnue!
    if( index == 11 )
      return -1;
  }
  return index;
}

//Description:
//  Retourne une evaluation de la distance sous forme d'une
//  chaine de caractères.
String distanceRange(){
  int idx = distanceIndex();
  if( idx == -1 )
    return "Inconnu";
  if( idx == 0 ) {       
    return "<= "+String(int(sharpCms[idx]));
  }
  return String(int(sharpCms[idx-1]))+"> x <="+String(int(sharpCms[idx]));
}

void Explore(){

  // lecture de la distance
  int idx = distanceIndex();

  // print out the value you read:
  Serial.println(idx);
  delay(1);        // delay in between reads for stability

  if(idx>4 || idx<0){
    obstacle = false;
    advance (100,100); 
  }
  else{
    
    // too close
    if(idx<=2){
      back_off (100,100);
    }
    // ok turn
    else{
      obstacle = true;
      if(servoPos > 74){
        turn_R (200,200); 
        servoDirection = 0;
      }
      else{
        turn_L (200,200);
        servoDirection = 1;
      }
    }
  }
}

