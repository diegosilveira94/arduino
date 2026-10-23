int ldr_pin = A0;
int valorldr = 0;
const int BUZZER = 10;

void setup() {
  pinMode(ldr_pin, INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
   valorldr=analogRead(ldr_pin);
   if (valorldr > 900) {
     tone(BUZZER, 1000);
   } else {
     noTone(BUZZER);
   }
   Serial.print("Valor lido pelo LDR = ");
   Serial.println(valorldr);
}