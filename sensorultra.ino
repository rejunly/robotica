// Definição dos pinos de conexão do sensor
const int trigPin = 11;
const int echoPin = 12;
const int alertPin = 13;

// Variáveis para armazenar a duração e a distância
long duration;
int distance;
int distancia_limite = 10;

void setup() {
  // put your setup code here, to run once:

   // Inicializa a comunicação serial
  Serial.begin(9600);

  // Define os modos dos pinos
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(alertPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Certifique-se de que o pino trig está baixo
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Envie um pulso alto de 10 microsegundos no pino trig
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Meça o tempo de duração do pulso no pino echo
  duration = pulseIn(echoPin, HIGH);

  // Calcule a distância em centímetros, ajuste o fator de conversão se necessário
  distance = duration * 0.0343 / 2; // ajuste da constante

  // Exiba a distância medida no Monitor Serial
  Serial.print("Distância: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= distancia_limite) {
    //Serial.println("Não seguro");
    //pararMotores();
    digitalWrite(alertPin, HIGH);
  } else {
    digitalWrite(alertPin, LOW);
    //norte();
    //Serial.println("Seguro");
  }

  // Aguarde 100ms antes de fazer a próxima medição
  delay(100);

}
