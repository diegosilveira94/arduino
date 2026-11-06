int pinA=2;
int pinB=3;
int pinC=4;
int pinD=5;
int pinE=6;
int pinF=7;
int pinG=8;
int botaoLiga=9;    // liga/desliga e inicia o sorteio
int botaoParar=10;  // para a animação e mostra o número

#define APERTADO LOW  // botão ligado entre o pino e o GND

int estado = 0;  // 0 = desligado, 1 = sorteando, 2 = mostrando resultado
int numero = 0;

void setup ()
{
  Serial.begin(9600);
  pinMode(botaoLiga, INPUT_PULLUP);
  pinMode(botaoParar, INPUT_PULLUP);

  for (int x=2;x<=8;x++){
    pinMode (x, OUTPUT);
  }

  apagar();
  randomSeed(analogRead(A0));  // pra não sortear sempre a mesma sequência
}

void loop ()
{
  // Botão 1: se está desligado, começa o sorteio. Se não, desliga.
  if (digitalRead(botaoLiga) == APERTADO)
  {
    if (estado == 0)
    {
      estado = 1;
      Serial.println("SORTEANDO...");
    }
    else
    {
      estado = 0;
      apagar();
      Serial.println("DESLIGADO");
    }
    esperarSoltar(botaoLiga);
  }

  // Botão 2: durante a animação, para e mostra o número sorteado
  if (digitalRead(botaoParar) == APERTADO && estado == 1)
  {
    estado = 2;
    Serial.print("NUMERO SORTEADO: ");
    Serial.println(numero);
    esperarSoltar(botaoParar);
  }

  // Animação: troca o número bem rápido
  if (estado == 1)
  {
    int novo;
    do {
      novo = random(0, 10);
    } while (novo == numero);  // evita repetir o mesmo número seguido

    numero = novo;
    mostrar(numero);
    delay(50);
  }
}

void esperarSoltar (int botao)
{
  while (digitalRead(botao) == APERTADO) { }
  delay(50);  // debounce
}

void segmentos (int a, int b, int c, int d, int e, int f, int g)
{
  digitalWrite (pinA, a);
  digitalWrite (pinB, b);
  digitalWrite (pinC, c);
  digitalWrite (pinD, d);
  digitalWrite (pinE, e);
  digitalWrite (pinF, f);
  digitalWrite (pinG, g);
}

void apagar ()
{
  segmentos(0,0,0,0,0,0,0);
}

void mostrar (int n)
{
  if (n==0) segmentos(1,1,1,1,1,1,0);
  if (n==1) segmentos(1,0,1,0,0,0,0);
  if (n==2) segmentos(1,1,0,1,1,0,1);
  if (n==3) segmentos(1,1,1,1,0,0,1);
  if (n==4) segmentos(1,0,1,0,0,1,1);
  if (n==5) segmentos(0,1,1,1,0,1,1);
  if (n==6) segmentos(0,1,1,1,1,1,1);
  if (n==7) segmentos(1,1,1,0,0,0,0);
  if (n==8) segmentos(1,1,1,1,1,1,1);
  if (n==9) segmentos(1,1,1,1,0,1,1);
}