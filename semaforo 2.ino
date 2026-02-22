#define ROJO 13
#define AMARILLO 12
#define VERDE 11
#define BOTON 2

int modo = 0;

bool estadoBotonAnterior = HIGH;

unsigned long tiempoAnterior = 0;
const unsigned long tiempoSemaforo = 3000;
const unsigned long tiempoBlink = 500;

int fase = 0;
bool estadoBlink = false;

void apagarTodo() {
  digitalWrite(ROJO, LOW);
  digitalWrite(AMARILLO, LOW);
  digitalWrite(VERDE, LOW);
}

void setup() {
  pinMode(ROJO, OUTPUT);
  pinMode(AMARILLO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(BOTON, INPUT_PULLUP);
}

void loop() {

  unsigned long ahora = millis();

  // -------- CAMBIO DE MODO (sin antirrebote complejo) --------
  bool estadoBotonActual = digitalRead(BOTON);

  if (estadoBotonAnterior == HIGH && estadoBotonActual == LOW) {
    modo++;
    if (modo > 4) modo = 0;
  }

  estadoBotonAnterior = estadoBotonActual;

  // -------- MODOS --------
  switch (modo) {

    case 0: // Semáforo normal

      if (ahora - tiempoAnterior >= tiempoSemaforo) {
        tiempoAnterior = ahora;
        fase++;
        if (fase > 2) fase = 0;
      }

      apagarTodo();

      if (fase == 0) digitalWrite(ROJO, HIGH);
      if (fase == 1) digitalWrite(AMARILLO, HIGH);
      if (fase == 2) digitalWrite(VERDE, HIGH);

    break;

    case 1: // Solo verde
      apagarTodo();
      digitalWrite(VERDE, HIGH);
    break;

    case 2: // Todos parpadean

      if (ahora - tiempoAnterior >= tiempoBlink) {
        tiempoAnterior = ahora;
        estadoBlink = !estadoBlink;
      }

      if (estadoBlink) {
        digitalWrite(ROJO, HIGH);
        digitalWrite(AMARILLO, HIGH);
        digitalWrite(VERDE, HIGH);
      } else {
        apagarTodo();
      }

    break;

    case 3: // Amarillo intermitente

      if (ahora - tiempoAnterior >= tiempoBlink) {
        tiempoAnterior = ahora;
        estadoBlink = !estadoBlink;
      }

      apagarTodo();
      if (estadoBlink) digitalWrite(AMARILLO, HIGH);

    break;

    case 4: // Todo apagado
      apagarTodo();
    break;
  }
}
