#include <Stepper.h>

// Número de passos necessários para completar uma revolução
const int stepsPerRevolution = 2048;
const int stepsToMove = 1;

// Inicialização dos motores de passo
//IN1 - IN3 - IN2 - IN4
Stepper motor1 = Stepper(stepsPerRevolution, 36, 38, 37, 39); //para trás
Stepper motor2 = Stepper(stepsPerRevolution, 40, 42, 41, 43);
Stepper motor3 = Stepper(stepsPerRevolution, 44, 46, 45, 47); //para trás
Stepper motor4 = Stepper(stepsPerRevolution, 48, 50, 49, 51);

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
  motor1.setSpeed(25);
  motor2.setSpeed(25);
  motor3.setSpeed(25);
  motor4.setSpeed(25);
  pararMotores();

}


void loop()
{
  leituraSensores();
  int corSensor1 = leituraCorSensor1();
  int corSensor2 = leituraCorSensor2();

  // Executa os passos dos motores simultaneamente
  for (int i = 0; i < stepsPerRevolution; i += stepsToMove) {
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
    } else if (corSensor1 == COR_VERDE || corSensor1 == COR_AZUL && corSensor2 == COR_BRANCO){
      pararMotores();
    }
  }


} //fim do loop



