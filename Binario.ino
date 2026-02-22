int bits[5] = {13, 12, 11, 10, 9}; 

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(bits[i], OUTPUT);
  }
  
  Serial.begin(9600);
  Serial.println("=== CONTADOR BINARIO DEL 0 AL 20 ===");
  Serial.println("LEDs: [13][12][11][10][9] = [16][8][4][2][1]");
  Serial.println("-----------------------------------");
}

void loop() {

  for (int numero = 0; numero <= 20; numero++) {
    
    
    Serial.print("Número decimal: ");
    Serial.print(numero);
    Serial.print(" | Binario: ");
    
    for (int bit = 4; bit >= 0; bit--) {
      int valorBit = bitRead(numero, bit);
      Serial.print(valorBit); 
      
     
      if (valorBit == 1) {
        digitalWrite(bits[4 - bit], HIGH); 
      } else {
        digitalWrite(bits[4 - bit], LOW);  
      }
    }
    
    Serial.println();
    
    delay(1500); 
  }
  
  Serial.println("¡Ciclo completado! Empezando de nuevo...");
  delay(3000);
}
