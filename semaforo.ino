#define ROJO 13
#define AMARILLO 12
#define VERDE 8

void setup() {
  pinMode(ROJO, OUTPUT);
  pinMode(AMARILLO, OUTPUT);
  pinMode(VERDE, OUTPUT);
}

void loop() {

  //ROJO
  digitalWrite(ROJO, HIGH);
  digitalWrite(AMARILLO, LOW);
  digitalWrite(VERDE, LOW);
  delay(1200);

  //AMARILLO
  digitalWrite(ROJO, LOW);
  digitalWrite(AMARILLO, HIGH);
  digitalWrite(VERDE, LOW);
  delay(1200);

  //VERDE
  digitalWrite(ROJO, LOW);
  digitalWrite(AMARILLO, LOW);
  digitalWrite(VERDE, HIGH);
  delay(1200);

}
