#include <NewPing.h>

#define TRIGGER_PIN D6
#define ECHO_PIN D5
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int piezoPin = D3;

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(50);
  
  unsigned int distance = sonar.ping_cm();
  
  if (distance <= 20) {
    tone(piezoPin, 1000); // Ativa o piezo a uma frequência de 1000 Hz
    delay(100); // Mantém ligado por 500 ms
    noTone(piezoPin); // Desliga o piezo
    
    Serial.print("Distancia: ");
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println(" Pare");
     
  
  } else if (distance <= 40) {
    tone(piezoPin, 2000); // Ativa o piezo a uma frequência de 2000 Hz
    delay(300); // Mantém ligado por 500 ms
    noTone(piezoPin); // Desliga o piezo

    Serial.print("Distancia: ");
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println(" Mantenha Atencao");
    
  
  } else if (distance <= 60) {
    tone(piezoPin, 3000); // Ativa o piezo a uma frequência de 3000 Hz
    delay(400); // Mantém ligado por 500 ms
    noTone(piezoPin); // Desliga o piezo

    Serial.print("Distancia: ");
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println(" Cuidado Devagar");   
  
  } else if (distance > 61) {  
    noTone(piezoPin); // Desliga o piezo
  }
}
  
 
