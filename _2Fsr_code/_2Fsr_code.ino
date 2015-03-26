int fsrPin0 = 0;     // the FSR and 10K pulldown are connected to a0 
int fsrPin1 = 1; 
 
int fsrReading0;     // the analog reading from the FSR resistor divider 
int fsrReading1; 
 
int fsrVoltage0;     // the analog reading converted to voltage 
int fsrVoltage1; 
 
// The voltage converted to resistance, can be very big so make "long" 
unsigned long fsrResistance0; 
unsigned long fsrConductance0; 
unsigned long fsrResistance1;   
unsigned long fsrConductance1;  // Finally, the resistance converted to force 
long fsrForce0; 
long fsrForce1; 
 
void setup(void) { 
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  } 
  
void loop() { 
  fsrReading0 = analogRead(fsrPin0);    
  fsrReading1 = analogRead(fsrPin1);   
  Serial.print("Analog reading0 = "); 
  Serial.println(fsrReading0); 
  Serial.print("Analog reading1 = "); 
  Serial.println(fsrReading1); 
  
  // analog voltage reading ranges from about 0 to 1023 which maps to 0V to 5V  
  fsrVoltage0 = map(fsrReading0, 0, 1023, 0, 5000); 
  Serial.print("Voltage reading in mV0 = "); 
  Serial.println(fsrVoltage0);   
  fsrVoltage1 = map(fsrReading1, 0, 1023, 0, 5000); 
  Serial.print("Voltage reading in mV1 = "); 
  Serial.println(fsrVoltage1);   
  
  if (fsrVoltage0 == 0) { 
    Serial.println("No pressure0");   
  } 
  else { 
    // The voltage = Vcc * R / (R + FSR) where R = 10K and Vcc = 5V     // so FSR = ((Vcc - V) * R) / V        yay math!     
    fsrResistance0 = 5000 - fsrVoltage0;     // fsrVoltage is in millivolts so 5V = 5000mV     
    fsrResistance0 *= 10000;                // 10K resistor 
    fsrResistance0 /= fsrVoltage0; 
 //   Serial.print("FSR resistance in ohms0 = "); 
 //   Serial.println(fsrResistance0); 
      
    fsrConductance0 = 1000000;           // we measure in micromhos so  
    fsrConductance0 /= fsrResistance0;     
//    Serial.print("Conductance in microMhos0: "); 
//    Serial.println(fsrConductance0); 
   
    // Use the two FSR guide graphs to approximate the force     
  if (fsrConductance0 <= 1000) {       
      fsrForce0 = fsrConductance0 / 80;       
      Serial.print("Force in Newtons0: "); 
      Serial.println(fsrForce0);       
    } 
  else { 
      fsrForce0 = fsrConductance0 - 1000;       
      fsrForce0 /= 30; 
      Serial.print("Force in Newtons0: "); 
      Serial.println(fsrForce0);             
 
    } 
      
  } 
   
  if (fsrVoltage1 == 0) 
  { 
    Serial.println("No pressure1 and no bending");   
  } 
  else { 
    // The voltage = Vcc * R / (R + FSR) where R = 10K and Vcc = 5V     // so FSR = ((Vcc - V) * R) / V        yay math!     fsrResistance1 = 5000 - fsrVoltage1;     // fsrVoltage is in millivolts so 5V = 5000mV     fsrResistance1 *= 10000;                // 10K resistor 
    fsrResistance1 /= fsrVoltage1; 
    Serial.print("FSR resistance in ohms1 = "); 
    Serial.println(fsrResistance1); 
     
    fsrConductance1 = 1000000;           // we measure in micromhos so      fsrConductance1 /= fsrResistance1; 
 //   Serial.print("Conductance in microMhos1: "); 
 //   Serial.println(fsrConductance1); 
 */    
    // Use the two FSR guide graphs to approximate the force     
  if (fsrConductance1 <= 1000) 
  {       
     fsrForce1 = fsrConductance1 / 80;       
     Serial.print("Force in Newtons1: "); 
     Serial.println(fsrForce1);       //check see if belong in loop
    } 
  else { 
    fsrForce1 = fsrConductance1 - 1000;       
    fsrForce1 /= 30; 
    Serial.print("Force in Newtons1: "); 
    Serial.println(fsrForce1);             
    }
  }
 
/*  if (fsrReading0 > fsrReading1) { 
    Serial.print("Move Right"); 
  }  
  if (fsrReading0 = fsrReading1){
    Serial.print("You're right on the money, baby");
  }
  else { 
    Serial.print("Move Left"); 
  }*/
  Serial.println("--------------------"); 
  delay(5000); 
}

 

