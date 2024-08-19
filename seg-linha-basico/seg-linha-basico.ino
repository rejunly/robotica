#include <AFMotor.h>

// Motores dianteiros DIR e ESQ
AF_DCMotor motor1(1);
AF_DCMotor motor2(4);

// Motores traseiros DIR e ESQ
AF_DCMotor motor3(2); 
AF_DCMotor motor4(3); 

//Sensores de cor
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

//Constantes das cores
#define COR_PRETO 0
#define COR_BRANCO 1
#define COR_AZUL 2
#define COR_VERDE 3
#define COR_VERMELHO 4
#define COR_INDETERMINADA 5

int red1, green1, blue1;
int red2, green2, blue2;

const unsigned long moveDuration = 1000; // Duração do movimento em milissegundos
const unsigned long stopDuration = 1000; // Tempo para parar os motores antes de iniciar o próximo movimento
const unsigned long moveCorrection = 300; // Duração do movimento de correção de rota em milissegundos



void setup()
{
  pinMode(PinOUT1, INPUT);  // Definição do PinOUT1 como sendo um pino de entrada
  pinMode(PinS21, OUTPUT);  // Definição do Pino S2 do sensor 1 como sendo um pino de saída
  pinMode(PinS31, OUTPUT);  // Definição do Pino S3 do sensor 1 como sendo um pino de saída

  pinMode(PinOUT2, INPUT);  // Definição do PinOUT2 como sendo um pino de entrada
  pinMode(PinS22, OUTPUT);  // Definição do Pino S2 do sensor 2 como sendo um pino de saída
  pinMode(PinS32, OUTPUT);  // Definição do Pino S3 do sensor 2 como sendo um pino de saída

  Serial.begin(9600);  // Inicia o monitor Serial com velocidade de 9600

  // Define a velocidade maxima para os motores 1 e 2
  motor1.setSpeed(0); // M1 
  motor2.setSpeed(0); // M4
  motor3.setSpeed(0); // M2
  motor4.setSpeed(0); // M3

  pararMotores();

}


void loop()
{
  leituraSensores();
  int corSensor1 = leituraCorSensor1();
  int corSensor2 = leituraCorSensor2();

  if (corSensor1 == COR_PRETO && corSensor2 == COR_PRETO) {
    norte();
  } else if (corSensor1 == COR_BRANCO && corSensor2 == COR_BRANCO) {
    norte();
  } else if (corSensor1 == COR_VERMELHO && corSensor2 == COR_VERMELHO){
    pararMotores();
  } else if(corSensor1 == COR_PRETO && corSensor2 == COR_BRANCO){
    correcaoEsquerda();
  } else if (corSensor1 == COR_BRANCO && corSensor2 == COR_PRETO){
    correcaoDireita();
  } else if (corSensor1 == COR_VERDE && corSensor2 == COR_BRANCO){
    norte();
    delay(moveCorrection);
    correcaoEsquerda();
    delay(moveCorrection);
  }


} //fim do loop



