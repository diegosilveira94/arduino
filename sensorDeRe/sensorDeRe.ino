const int TRIG = 3;
const int ECHO = 2;
const int LED_VERMELHO = 8;  // perna R do LED RGB
const int LED_VERDE = 6;     // perna G do LED RGB
const int BUZZER = 10;

// Distancias em cm
const int DIST_BIP = 100;     // abaixo disso comeca a bipar
const int DIST_PERTO = 50;    // abaixo disso: amarelo
const int DIST_CRITICA = 20;  // abaixo disso: vermelho
const int DIST_COLADO = 5;    // abaixo disso: som continuo

const int FREQ_BIP = 2500;    // Hz
const int DURACAO_BIP = 60;   // ms

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
}

void loop() {
  int distancia = sensor_morcego(TRIG, ECHO);

  Serial.print(distancia);
  Serial.println(" cm");

  // LED RGB: amarelo = vermelho + verde
  if (distancia > DIST_PERTO) {
    cor(LOW, HIGH);   // verde
  } else if (distancia > DIST_CRITICA) {
    cor(HIGH, HIGH);  // amarelo
  } else {
    cor(HIGH, LOW);   // vermelho
  }

  // Buzzer: quanto mais perto, menor a pausa entre os bips
  if (distancia > DIST_BIP) {
    noTone(BUZZER);
    delay(100);
  } else if (distancia <= DIST_COLADO) {
    tone(BUZZER, FREQ_BIP);
    delay(60);
  } else {
    int pausa = map(distancia, DIST_COLADO, DIST_BIP, 40, 600);
    tone(BUZZER, FREQ_BIP, DURACAO_BIP);
    delay(DURACAO_BIP + pausa);
  }
}

void cor(bool vermelho, bool verde) {
  digitalWrite(LED_VERMELHO, vermelho);
  digitalWrite(LED_VERDE, verde);
}

int sensor_morcego(int pinotrig, int pinoecho) {
  digitalWrite(pinotrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig, LOW);

  // Timeout de 30 ms (~5 m). Sem eco, pulseIn devolve 0.
  unsigned long duracao = pulseIn(pinoecho, HIGH, 30000);
  if (duracao == 0) return 999;  // nada na frente

  return duracao / 58;
}
