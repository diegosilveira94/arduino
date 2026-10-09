const int LED_VERMELHO = 8;

const int LED_AZUL = 9;

const int LED_VERDE = 7;

const int LED_AMARELO = 2;

const int BUZZER = 10;
 
void setup() {

  pinMode(LED_VERMELHO, OUTPUT);

  pinMode(LED_AZUL, OUTPUT);

  pinMode(LED_VERDE, OUTPUT);

  pinMode(LED_AMARELO, OUTPUT);

}
 
void sirene() {

  for (int frequencia = 2000; frequencia <= 1800; frequencia += 50) {

    tone(BUZZER, frequencia);

    delay(3);

  }
 
  for (int frequencia = 4000; frequencia >= 600; frequencia -= 50) {

    tone(BUZZER, frequencia);

    delay(3);

  }

}
 
void loop() {
 
  digitalWrite(LED_VERMELHO, HIGH);

  digitalWrite(LED_AZUL, LOW);

  digitalWrite(LED_VERDE, LOW);

  digitalWrite(LED_AMARELO, LOW);

  sirene();
 
  digitalWrite(LED_VERMELHO, LOW);

  digitalWrite(LED_AZUL, HIGH);

  digitalWrite(LED_VERDE, LOW);

  digitalWrite(LED_AMARELO, LOW);

  sirene();
 
  digitalWrite(LED_VERMELHO, LOW);

  digitalWrite(LED_AZUL, LOW);

  digitalWrite(LED_VERDE, HIGH);

  digitalWrite(LED_AMARELO, LOW);

  sirene();
 
  digitalWrite(LED_VERMELHO, LOW);

  digitalWrite(LED_AZUL, LOW);

  digitalWrite(LED_VERDE, LOW);

  digitalWrite(LED_AMARELO, HIGH);

  sirene();

}
 