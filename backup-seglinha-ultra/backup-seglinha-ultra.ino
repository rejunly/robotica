#include <Stepper.h>
#include <TimerOne.h>


// Número de passos necessários para completar uma revolução
const int stepsPerRevolution = 2048;
const int stepsToMove = 1;

long distancia;
const int limiarDistancia = 20;  // Distância mínima para tomar ação evasiva


// Inicialização dos motores de passo
//IN1 - IN3 - IN2 - IN4
Stepper motor1 = Stepper(stepsPerRevolution, 36, 38, 37, 39);  //para trás
Stepper motor2 = Stepper(stepsPerRevolution, 40, 42, 41, 43);
Stepper motor3 = Stepper(stepsPerRevolution, 44, 46, 45, 47);  //para trás
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

//Ultrassonico
#define alertPin 22

//Constantes das cores
#define COR_PRETO 0
#define COR_BRANCO 1
#define COR_AZUL 2
#define COR_VERDE 3
#define COR_VERMELHO 4
#define COR_INDETERMINADA 5
#define COR_CINZA 6

int valAnterior1;
int valAnterior2;

int red1, green1, blue1;
int red2, green2, blue2;


void setup() {
  pinMode(alertPin, INPUT);


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

  Timer1.initialize(10000);
  Timer1.setPeriod(10000);
  Timer1.attachInterrupt(readSensor);
  /*attachInterrupt(digitalPinToInterrupt(PinOUT1), readSensor, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PinOUT2), readSensor, CHANGE);*/
}

int corSensor1 = 0;
int corSensor2 = 0;
int state_move = 100;

void readSensor() {
  leituraSensores();
  corSensor1 = leituraCorSensor1();
  corSensor2 = leituraCorSensor2();
}


void loop() {

  if (digitalRead(alertPin) == LOW) {

    if ((corSensor1 == COR_BRANCO && corSensor2 == COR_BRANCO) || (corSensor1 == COR_PRETO && corSensor2 == COR_PRETO) || (corSensor1 == COR_AZUL && corSensor2 == COR_AZUL)) {
      state_move = 0;
    } else if ((valAnterior1 == 0 && valAnterior2 == 0 && corSensor1 == COR_VERDE && corSensor2 == COR_BRANCO) || (valAnterior1 == 0 && valAnterior2 == 0 && corSensor2 == COR_VERDE && corSensor1 == COR_BRANCO)) {
      state_move = 0;
    } else if ((valAnterior1 ==1 && valAnterior2 == 1 && corSensor1 == COR_BRANCO && corSensor2 == COR_PRETO) || (valAnterior1 ==1 && valAnterior2 == 1 && corSensor2 == COR_BRANCO && corSensor1 == COR_PRETO) ){
      state_move = 0;
    } else if (corSensor1 == COR_VERMELHO && corSensor2 == COR_VERMELHO) {
      state_move = 100;
    } else if ((corSensor1 == COR_BRANCO && corSensor2 == COR_PRETO) || (corSensor1 == COR_BRANCO && corSensor2 == COR_AZUL)) {
      state_move = 5;
    } else if ((corSensor2 == COR_BRANCO && corSensor1 == COR_PRETO) || (corSensor2 == COR_BRANCO && corSensor1 == COR_AZUL)) {
      state_move = 4;
    } else if ((corSensor1 == COR_BRANCO && corSensor2 == COR_VERDE)) {
      state_move = 7;
    } else if ((corSensor2 == COR_BRANCO && corSensor1 == COR_VERDE)) {
      state_move = 6;
    } else if ((corSensor1 == COR_VERDE && corSensor2 == COR_VERDE)){
      state_move = 9;
    } else if ((corSensor1 == COR_CINZA && corSensor2 == COR_CINZA)){
      state_move = 10;
    } else {
      state_move = 100;
    }

  } else {

    state_move = 8;

    Serial.print("AQUI");
  }


  switch (state_move) {
    case 0:  //NORTE
      norte();
      break;
    case 1:  //SUL
      sul();
      break;
    case 2:  //LESTE
      leste();
      break;
    case 3:  //OESTE
      oeste();
      break;
    case 4:  //CURVA DIREITA
      //norte();
      for (int i = 0; i < 500; i++) {
        eixoHorario();
        delay(1);
      }
      break;
    case 5:  //CURVA ESQUERDA
      //norte();
      for (int i = 0; i < 500; i++) {
        eixoAntihorario();
        delay(1);
      }
      break;
    case 6:  //CURVA DIREITA
      //norte();
      for (int i = 0; i < 800; i++) {
        norte();
        delay(1);
      }
      for (int i = 0; i < 3100; i++) {
        eixoHorario();
        delay(1);
      }
      break;
    case 7:  //CURVA ESQUERDA
      //norte();
      for (int i = 0; i < 800; i++) {
        norte();
        delay(1);
      }
      for (int i = 0; i < 3100; i++) {
        eixoAntihorario();
        delay(1);
      }
      break;
    case 8: //desvio
      for (int i = 0; i < 3000; i++) {
        oeste();
        delayMicroseconds(100);
      }
      for (int i = 0; i < 3000; i++) {
        norte();
        delayMicroseconds(100);
      }
      for (int i = 0; i < 3000; i++) {
        leste();
        delayMicroseconds(100);
      }
      state_move = 0;
      break;
    case 9: //180°
      for (int i = 0; i < 6200; i++) {
        eixoHorario();
        delay(1);
      }
      break;
    case 10: //área de resgate
     if (digitalRead(alertPin) == LOW){
        norte();
     } else {
      oeste();
     }
    default:
      pararMotores();
      break;
  }
}  //fim do loop
