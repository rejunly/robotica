#include <AFMotor.h>
#include <Ultrasonic.h>

// Definição de pinos e inicialização de variáveis
Ultrasonic ultrassom(23, 22); // Pinos trig e echo do sensor ultrassônico

#define PinOUT1 7  // Definição do Pino OUT do sensor 1 na entrada digital 7
#define PinS01 26  // Definição do Pino S0 do sensor 1 na entrada digital 26
#define PinS11 27  // Definição do Pino S1 do sensor 1 na entrada digital 27
#define PinS21 28  // Definição do Pino S2 do sensor 1 na entrada digital 28
#define PinS31 29  // Definição do Pino S3 do sensor 1 na entrada digital 29

#define PinOUT2 6  // Definição do Pino OUT do sensor 2 na entrada digital 6
#define PinS02 30  // Definição do Pino S0 do sensor 2 na entrada digital 30
#define PinS12 31  // Definição do Pino S1 do sensor 2 na entrada digital 31
#define PinS22 32  // Definição do Pino S2 do sensor 2 na entrada digital 32
#define PinS32 33  // Definição do Pino S3 do sensor 2 na entrada digital 33

AF_DCMotor motor1(1); 
AF_DCMotor motor2(4);
AF_DCMotor motor3(2);
AF_DCMotor motor4(3);

const unsigned long moveDuration = 10000; // Duração do movimento em milissegundos
const unsigned long stopDuration = 1000; // Tempo para parar os motores antes de iniciar o próximo movimento

int red1, green1, blue1;  // Variáveis para o sensor 1
int red2, green2, blue2;  // Variáveis para o sensor 2

void paraFrente() {
  motor1.setSpeed(100); //M1
  motor2.setSpeed(100); //M4
  motor3.setSpeed(500); //M2
  motor4.setSpeed(100); //M3

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void pararMotores(){
  motor1.setSpeed(0); // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(0); // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(0); // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(0); // M3 = 104 RPM(60) ; 136rpm (100)
} 

void lerSensor(int pinOUT, int pinS2, int pinS3, int &red, int &green, int &blue, const char* sensorName) {
  digitalWrite(pinS2, LOW);
  digitalWrite(pinS3, LOW);
  red = pulseIn(pinOUT, LOW);
  Serial.print(sensorName); 
  Serial.print(" - R: "); 
  Serial.print(red); 
  delay(15);

  digitalWrite(pinS2, HIGH);
  digitalWrite(pinS3, HIGH);
  green = pulseIn(pinOUT, LOW);
  Serial.print(" G: "); 
  Serial.print(green); 
  delay(15);

  digitalWrite(pinS2, LOW);
  digitalWrite(pinS3, HIGH);
  blue = pulseIn(pinOUT, LOW);
  Serial.print(" B: "); 
  Serial.println(blue); 
  delay(15);
}

const char* detectarCor1(int red1, int green1, int blue1) {
  if (blue1 > 25 && red1 > 25 && green1 > 25) {
    return "Preto";
  } else if (blue1 < 10 && red1 < 10 && green1 < 10) {
    return "Branco";
  } else if (blue1 < red1 && blue1 < green1) {
    return "Azul";
  } else if (green1 < red1 && green1 < blue1) {
    return "Verde";
  } else if (red1 < blue1 && red1 < green1 && red1 < 100) {
    return "Vermelho";
  }
  return "Indefinido";
}

const char* detectarCor2(int red2, int green2, int blue2) {
  if (blue2 > 25 && red2 > 25 && green2 > 25) {
    return "Preto";
  } else if (blue2 < 10 && red2 < 10 && green2 < 10) {
    return "Branco";
  } else if (blue2 < red2 && blue2 < green2) {
    return "Azul";
  } else if (green2 < red2 && green2 < blue2) {
    return "Verde";
  } else if (red2 < blue2 && red2 < green2 && red2 < 100) {
    return "Vermelho";
  }
  return "Indefinido";
}

void setup() {
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor3.setSpeed(500);
  motor4.setSpeed(100);

  pararMotores();

  pinMode(PinOUT1, INPUT);  // Definição do PinOUT1 como sendo um pino de entrada
  pinMode(PinS01, OUTPUT);
  pinMode(PinS11, OUTPUT);
  pinMode(PinS21, OUTPUT);  // Definição do Pino S2 do sensor 1 como sendo um pino de saída
  pinMode(PinS31, OUTPUT);  // Definição do Pino S3 do sensor 1 como sendo um pino de saída

  pinMode(PinOUT2, INPUT);  // Definição do PinOUT2 como sendo um pino de entrada
  pinMode(PinS02, OUTPUT);
  pinMode(PinS12, OUTPUT);
  pinMode(PinS22, OUTPUT);  // Definição do Pino S2 do sensor 2 como sendo um pino de saída
  pinMode(PinS32, OUTPUT);  // Definição do Pino S3 do sensor 2 como sendo um pino de saída

  Serial.begin(9600);  // Inicia o monitor Serial com velocidade de 9600
}

void loop() {
  lerSensor(PinOUT1, PinS21, PinS31, red1, green1, blue1, "Sensor 1");
  lerSensor(PinOUT2, PinS22, PinS32, red2, green2, blue2, "Sensor 2");

  const char* corSensor1 = detectarCor1(red1, green1, blue1);
  const char* corSensor2 = detectarCor2(red2, green2, blue2);

  Serial.print("Sensor 1: ");
  Serial.print(corSensor1);
  Serial.print(" - Sensor 2: ");
  Serial.println(corSensor2);

  if (strcmp(corSensor1, "Branco") == 0 && strcmp(corSensor2, "Branco") == 0) {
    paraFrente();
  } else {
    pararMotores();
  }
  delay(1000); // Pequeno atraso para evitar leituras excessivas
}
