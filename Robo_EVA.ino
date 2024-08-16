// Inclusão das Bibliotecas
#include <AFMotor.h>
#include <Ultrasonic.h>

// Declaração dos Motores (Usando o Motor Shield Adafruit)
AF_DCMotor motor1(1);
AF_DCMotor motor2(4);
AF_DCMotor motor3(2);
AF_DCMotor motor4(3);

// Definição dos Pinos dos Sensores de Cor
#define PinOUT1 34
#define PinS01 26
#define PinS11 27
#define PinS21 28
#define PinS31 29

#define PinOUT2 35
#define PinS02 30
#define PinS12 31
#define PinS22 32
#define PinS32 33

//////////////////////////////////////////////

// Definição do Pino do Sensor IR
const int PinInfravermelho = A15;

// Definição dos Pinos do Sensor Ultrassônico
Ultrasonic ultrassom(23, 22);

// Variáveis para Armazenar as Leituras dos Sensores de Cor
int red1, green1, blue1;
int red2, green2, blue2;
int infravermelho;

int prevRed1, prevGreen1, prevBlue1;
int prevRed2, prevGreen2, prevBlue2;
int prevInfravermelho;

// Variável para a Distância Medida pelo Sensor Ultrassônico
long distancia;

// Constantes para Controle de Tempo e Limite de Distância
const unsigned long stopDuration = 1000;
const int limiarDistancia = 15;

//////////////////////////////////////////////

void setup() {
  // Inicialização da Comunicação Serial
  Serial.begin(9600);

  // Inicialização dos Motores no Estado Parado
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);
  pararMotores();

  // Configuração dos Pinos dos Sensores de Cor
  pinMode(PinOUT1, INPUT);
  pinMode(PinS21, OUTPUT);
  pinMode(PinS31, OUTPUT);

  pinMode(PinOUT2, INPUT);
  pinMode(PinS22, OUTPUT);
  pinMode(PinS32, OUTPUT);

  // Configuração do Pino do Sensor IR
  pinMode(PinInfravermelho, INPUT);
}

//////////////////////////////////////////////

void loop() {
  // Medição da Distância pelo Sensor Ultrassônico
  distancia = ultrassom.Ranging(CM);
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Decisão Baseada na Distância Medida
  seguirLinha();
  delay(1000);
}

//////////////////////////////////////////////

void seguirLinha() {
  // Leitura dos Sensores de Cor e IR
  lerSensoresDeCor();
  infravermelho = digitalRead(PinInfravermelho);

  // Exibição das Leituras
  Serial.print("Leituras do Sensor Esquerdo - R: "); Serial.print(red1);
  Serial.print(" G: "); Serial.print(green1); Serial.print(" B: "); Serial.println(blue1);
  Serial.print("Leituras do Sensor Direito - R: "); Serial.print(red2);
  Serial.print(" G: "); Serial.print(green2); Serial.print(" B: "); Serial.println(blue2);
  Serial.print("Leitura do Sensor IR: "); Serial.println(infravermelho);

  // Decisão Baseada na Leitura Atual e Anterior dos Sensores - Priorizando Interseção
  if (isIntersecao()) {
    Serial.println("Interseção detectada. Decidindo ação...");

    // Situação 1
    if (isVerde(red1, green1, blue1) && isVerde(red2, green2, blue2) && isPretoInfravermelho()) {
      Serial.println("Situação 1: Ambos Verde, IR Preto. Virando 180 graus.");
      virarEm180();
    }
    // Situação 2
    else if (isBranco(red1, green1, blue1) && isVerde(red2, green2, blue2) && isPretoInfravermelho()) {
      Serial.println("Situação 2: Esquerda Branco, Direita Verde, IR Preto. Virando à direita.");
      virarDireita();
    }
    // Situação 3
    else if (isVerde(red1, green1, blue1) && isBranco(red2, green2, blue2) && isPretoInfravermelho()) {
      Serial.println("Situação 3: Esquerda Verde, Direita Branco, IR Preto. Virando à esquerda.");
      virarEsquerda();
    }
    // Situação 4
    else if (isPreto(red1, green1, blue1) && isPreto(red2, green2, blue2) && isPretoInfravermelho() &&
             isBranco(prevRed1, prevGreen1, prevBlue1) && isBranco(prevRed2, prevGreen2, prevBlue2)) {
      Serial.println("Situação 4: Ambos Preto agora, Branco antes. Seguindo em frente.");
      norte();
    }
    // Situação 6
    else if (isBranco(red1, green1, blue1) && isPreto(red2, green2, blue2) && isPretoInfravermelho() &&
             isBranco(prevRed1, prevGreen1, prevBlue1) && isBranco(prevRed2, prevGreen2, prevBlue2)) {
      Serial.println("Situação 6: Esquerda Branco, Direita Preto agora, Branco antes. Seguindo em frente.");
      norte();
    }
    // Situação 7
    else if (isPreto(red1, green1, blue1) && isBranco(red2, green2, blue2) && isPretoInfravermelho() &&
             isBranco(prevRed1, prevGreen1, prevBlue1) && isBranco(prevRed2, prevGreen2, prevBlue2)) {
      Serial.println("Situação 7: Esquerda Preto, Direita Branco agora, Branco antes. Seguindo em frente.");
      norte();
    }
    // Situação 8
    else if (isVerde(red1, green1, blue1) && isBranco(red2, green2, blue2) && isPretoInfravermelho() &&
             isPreto(prevRed1, prevGreen1, prevBlue1) && isPreto(prevRed2, prevGreen2, prevBlue2)) {
      Serial.println("Situação 8: Esquerda Verde agora, Preto antes. Seguindo em frente.");
      norte();
    }
    // Situação 9
    else if (isBranco(red1, green1, blue1) && isVerde(red2, green2, blue2) && isPretoInfravermelho() &&
             isPreto(prevRed1, prevGreen1, prevBlue1) && isPreto(prevRed2, prevGreen2, prevBlue2)) {
      Serial.println("Situação 9: Direita Verde agora, Preto antes. Seguindo em frente.");
      norte();
    }
  } else {
    // Lógica para ajuste leve baseado na detecção de preto por um único sensor
    if (isPreto(red1, green1, blue1) && isBranco(red2, green2, blue2)) {
      Serial.println("Sensor Esquerdo Preto, Sensor Direito Branco. Ajustando levemente à esquerda.");
      ajustarLevementeEsquerda();
    } else if (isBranco(red1, green1, blue1) && isPreto(red2, green2, blue2)) {
      Serial.println("Sensor Esquerdo Branco, Sensor Direito Preto. Ajustando levemente à direita.");
      ajustarLevementeDireita();
    } else {
      // Continuar a seguir a linha normalmente
      if (isPreto(red1, green1, blue1) && isPreto(red2, green2, blue2)) {
        Serial.println("Ambos os sensores leem Preto");
        norte();
      } else if (isBranco(red1, green1, blue1) && isBranco(red2, green2, blue2)) {
        Serial.println("Ambos os sensores leem Branco. Seguindo em frente.");
        norte();
      } else if (isVerde(red1, green1, blue1)) {
        Serial.println("Sensor Esquerdo Verde. Virando à esquerda.");
        virarEsquerda();
      } else if (isVerde(red2, green2, blue2)) {
        Serial.println("Sensor Direito Verde. Virando à direita.");
        virarDireita();
      } else {
        Serial.println("Nenhuma condição específica. Seguindo em frente.");
        norte();
      }
    }
  }

  // Atualizar valores anteriores
  prevRed1 = red1;
  prevGreen1 = green1;
  prevBlue1 = blue1;
  prevRed2 = red2;
  prevGreen2 = green2;
  prevBlue2 = blue2;
  prevInfravermelho = infravermelho;
}

//////////////////////////////////////////////

void lerSensoresDeCor() {
  // Leitura do sensor 1 (Esquerdo)
  digitalWrite(PinS21, LOW);
  digitalWrite(PinS31, LOW);
  red1 = pulseIn(PinOUT1, LOW);

  digitalWrite(PinS21, HIGH);
  digitalWrite(PinS31, HIGH);
  green1 = pulseIn(PinOUT1, LOW);

  digitalWrite(PinS21, LOW);
  digitalWrite(PinS31, HIGH);
  blue1 = pulseIn(PinOUT1, LOW);

  // Leitura do sensor 2 (Direito)
  digitalWrite(PinS22, LOW);
  digitalWrite(PinS32, LOW);
  red2 = pulseIn(PinOUT2, LOW);

  digitalWrite(PinS22, HIGH);
  digitalWrite(PinS32, HIGH);
  green2 = pulseIn(PinOUT2, LOW);

  digitalWrite(PinS22, LOW);
  digitalWrite(PinS32, HIGH);
  blue2 = pulseIn(PinOUT2, LOW);
}

//////////////////////////////////////////////

bool isIntersecao() {
  return infravermelho == LOW;
}

bool isPreto(int red, int green, int blue) {
  return red > 25 && green > 25 && blue > 25;
}

bool isBranco(int red, int green, int blue) {
  return red < 10 && green < 10 && blue < 10;
}

bool isVerde(int red, int green, int blue) {
  return green < red && green < blue;
}

bool isPretoInfravermelho() {
  return infravermelho == LOW;
}

//////////////////////////////////////////////

void norte() {
  motor1.setSpeed(60);
  motor2.setSpeed(60);
  motor3.setSpeed(60);
  motor4.setSpeed(60);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void pararMotores() {
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor3.setSpeed(0);
  motor4.setSpeed(0);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void virarDireita() {
  motor1.setSpeed(60);
  motor2.setSpeed(60);
  motor3.setSpeed(60);
  motor4.setSpeed(60);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

  delay(500);
}

void virarEsquerda() {
  motor1.setSpeed(60);
  motor2.setSpeed(60);
  motor3.setSpeed(60);
  motor4.setSpeed(60);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

  delay(500);
}

void virarEm180() {
  virarDireita();
  virarDireita();
}

void desviar() {
  motor1.setSpeed(60);
  motor2.setSpeed(60);
  motor3.setSpeed(60);
  motor4.setSpeed(60);

  // Movimento de desvio para a direita
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

  delay(1000);

  // Continuar em frente após desvio
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

  delay(1000);
}

void ajustarLevementeEsquerda() {
  motor1.setSpeed(50); //m1
  motor2.setSpeed(60); //m4
  motor3.setSpeed(50); //m2
  motor4.setSpeed(60); //m3

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

  delay(600); // Ajuste fino, tempo curto
}

void ajustarLevementeDireita() {
  motor1.setSpeed(60); //m1
  motor2.setSpeed(50); //m4
  motor3.setSpeed(60); //m2
  motor4.setSpeed(50);  //m3 

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

  delay(600); // Ajuste fino, tempo curto
}
