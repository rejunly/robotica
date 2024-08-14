// Carrega as bibliotecas necessárias
#include <AFMotor.h>
#include <Ultrasonic.h>

// Definição de pinos e inicialização de variáveis
Ultrasonic ultrassom(23, 22); // Pinos trig e echo do sensor ultrassônico

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

long distancia;
const unsigned long stopDuration = 1000; // Tempo para parar os motores antes de iniciar o próximo movimento
const int limiarDistancia = 20; // Distância mínima para tomar ação evasiva

// Tempos personalizados para cada movimento de desvio
const unsigned long tempoVirarEsquerda1 = 1000;
const unsigned long tempoVirarDireita1 = 950;
const unsigned long tempoVirarDireita2 = 1000;
const unsigned long tempoVirarEsquerda2 = 1150;

// Configuração inicial
void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial a 9600 bauds
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
}

// Funções de movimento dos motores
void paraFrente() {
  motor1.setSpeed(90); 
  motor2.setSpeed(120); 
  motor3.setSpeed(140);
  motor4.setSpeed(120);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void paraTras() {
  motor1.setSpeed(90); 
  motor2.setSpeed(120); 
  motor3.setSpeed(140);
  motor4.setSpeed(120);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void virarDireita() {
  motor1.setSpeed(90); // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(120); // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(140); // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(120); // M3 = 104 RPM(60) ; 136rpm (100)

  motor1.run(FORWARD); //m1
  motor2.run(BACKWARD);
  motor3.run(BACKWARD); //m2
  motor4.run(FORWARD);
}

void virarEsquerda() {
  motor1.setSpeed(90); // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(120); // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(140); // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(120); // M3 = 104 RPM(60) ; 136rpm (100)

  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void pararMotores() {
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
}

// Função para desviar do obstáculo
void desviar() {
  // Vira para a esquerda
  virarEsquerda();
  delay(tempoVirarEsquerda1);
  pararMotores();
  delay(stopDuration);

  // Verifica a distância
  long distanciaEsquerda = ultrassom.Ranging(CM);
  Serial.print("Distância à esquerda: ");
  Serial.print(distanciaEsquerda);
  Serial.println(" cm");

  // Vira para a direita (posição inicial)
  virarDireita();
  delay(tempoVirarDireita1);
  pararMotores();
  delay(stopDuration);

  // Vira para a direita novamente
  virarDireita();
  delay(tempoVirarDireita2);
  pararMotores();
  delay(stopDuration);

  // Verifica a distância
  long distanciaDireita = ultrassom.Ranging(CM);
  Serial.print("Distância à direita: ");
  Serial.print(distanciaDireita);
  Serial.println(" cm");

  // Vira para a esquerda (posição inicial)
  virarEsquerda();
  delay(tempoVirarEsquerda2);
  pararMotores();
  delay(stopDuration);

  // Decide a direção com mais espaço
  if (distanciaDireita > distanciaEsquerda) {
    virarDireita();
  } else {
    virarEsquerda();
  }
  delay(1000); // Duração para se alinhar na direção escolhida
  pararMotores();
  delay(stopDuration);
}

// Função de loop principal
void loop() {
  distancia = ultrassom.Ranging(CM); // Mede a distância em cm
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia > limiarDistancia) {
    paraFrente(); // Se a distância for segura, move para frente
  } else {
    pararMotores(); // Para os motores antes de desviar
    delay(stopDuration);
    desviar(); // Executa a lógica de desvio
  }
}
