#include <AFMotor.h>

// Motores dianteiros DIR e ESQ
AF_DCMotor motor1(1);
AF_DCMotor motor2(4);

// Motores traseiros DIR e ESQ
AF_DCMotor motor3(2);
AF_DCMotor motor4(3);

const unsigned long moveDuration = 1000;  // Duração do movimento em milissegundos
const unsigned long stopDuration = 1000;  // Tempo para parar os motores antes de iniciar o próximo movimento

#define PinOUT1 34  // Definição do Pino OUT do sensor 1 na entrada digital 7
#define PinS01 26   // Definição do Pino S0 do sensor 1 na entrada digital 26
#define PinS11 27   // Definição do Pino S1 do sensor 1 na entrada digital 27
#define PinS21 28   // Definição do Pino S2 do sensor 1 na entrada digital 28
#define PinS31 29   // Definição do Pino S3 do sensor 1 na entrada digital 29

#define PinOUT2 35  // Definição do Pino OUT do sensor 2 na entrada digital 6
#define PinS02 30   // Definição do Pino S0 do sensor 2 na entrada digital 30
#define PinS12 31   // Definição do Pino S1 do sensor 2 na entrada digital 31
#define PinS22 32   // Definição do Pino S2 do sensor 2 na entrada digital 32
#define PinS32 33   // Definição do Pino S3 do sensor 2 na entrada digital 33

int red1, green1, blue1;  // Variáveis para o sensor 1
int red2, green2, blue2;  // Variáveis para o sensor 2

void norte() {
  motor1.setSpeed(90);   // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(120);  // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(140);  // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(120);  // M3 = 104 RPM(60) ; 136rpm (100)

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void sul() {
  motor1.setSpeed(90);   // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(120);  // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(140);  // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(120);  // M3 = 104 RPM(60) ; 136rpm (100)

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void leste() {
  motor1.setSpeed(90);   // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(120);  // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(140);  // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(120);  // M3 = 104 RPM(60) ; 136rpm (100)

  motor1.run(FORWARD);  //m1
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);  //m2
  motor4.run(FORWARD);
}

void oeste() {
  motor1.setSpeed(90);   // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(120);  // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(140);  // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(120);  // M3 = 104 RPM(60) ; 136rpm (100)

  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void nordeste() {
  motor1.setSpeed(90);   // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(0);    // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(0);    // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(120);  // M3 = 104 RPM(60) ; 136rpm (100)

  motor1.run(FORWARD);  //m1
  motor2.run(RELEASE);
  motor3.run(RELEASE);  //m2
  motor4.run(FORWARD);
}

void noroeste() {
  motor1.setSpeed(0);    // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(120);  // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(120);  // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(0);    // M3 = 104 RPM(60) ; 136rpm (100)

  motor1.run(RELEASE);  //M1
  motor2.run(FORWARD);
  motor3.run(FORWARD);  //M2
  motor4.run(RELEASE);
}

void pararMotores() {

  motor1.setSpeed(0);  // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(0);  // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(0);  // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(0);  // M3 = 104 RPM(60) ; 136rpm (100)
}


void setup() {


  Serial.begin(9600);  // Inicia o monitor Serial com velocidade de 9600

  // Define a velocidade maxima para os motores 1 e 2
  motor1.setSpeed(0);  // M1
  motor2.setSpeed(0);  // M4
  motor3.setSpeed(0);  // M2
  motor4.setSpeed(0);  // M3

  pararMotores();


  pinMode(PinOUT1, INPUT);  // Definição do PinOUT1 como sendo um pino de entrada
  pinMode(PinS21, OUTPUT);  // Definição do Pino S2 do sensor 1 como sendo um pino de saída
  pinMode(PinS31, OUTPUT);  // Definição do Pino S3 do sensor 1 como sendo um pino de saída

  pinMode(PinOUT2, INPUT);  // Definição do PinOUT2 como sendo um pino de entrada
  pinMode(PinS22, OUTPUT);  // Definição do Pino S2 do sensor 2 como sendo um pino de saída
  pinMode(PinS32, OUTPUT);  // Definição do Pino S3 do sensor 2 como sendo um pino de saída

  Serial.println("AA");

  norte();
}

int state = 0;
int timeX = 5;

void loop() {



  if (timeX > 5) {
    timeX = 0;
    switch (state) {
      case 0:
        Serial.println("NORTE");
        norte();
        state = 1;
        break;
      case 1:
        Serial.println("SUL");
        sul();
        state = 2;
        break;
      case 2:
        Serial.println("LESTE");
        leste();
        state = 3;
        break;
      case 3:
        Serial.println("OESTE");
        oeste();
        state = 0;
        break;
    }
  }

  timeX+=1;

  /*norte();
  sul();
  leste();
  oeste();
  nordeste();*/


  // Leitura do sensor 1
  digitalWrite(PinS21, LOW);
  digitalWrite(PinS31, LOW);
  red1 = pulseIn(PinOUT1, LOW);
  Serial.print("Sensor 1 - R: ");
  Serial.print(red1);
  //delay(15);

  digitalWrite(PinS21, HIGH);
  digitalWrite(PinS31, HIGH);
  green1 = pulseIn(PinOUT1, LOW);
  Serial.print(" G: ");
  Serial.print(green1);
  //delay(15);

  digitalWrite(PinS21, LOW);
  digitalWrite(PinS31, HIGH);
  blue1 = pulseIn(PinOUT1, LOW);
  Serial.print(" B: ");
  Serial.println(blue1);
  //delay(15);

  // Leitura do sensor 2
  digitalWrite(PinS22, LOW);
  digitalWrite(PinS32, LOW);
  red2 = pulseIn(PinOUT2, LOW);
  Serial.print("Sensor 2 - R: ");
  Serial.print(red2);
  //delay(15);

  digitalWrite(PinS22, HIGH);
  digitalWrite(PinS32, HIGH);
  green2 = pulseIn(PinOUT2, LOW);
  Serial.print(" G: ");
  Serial.print(green2);
  //delay(15);

  digitalWrite(PinS22, LOW);
  digitalWrite(PinS32, HIGH);
  blue2 = pulseIn(PinOUT2, LOW);
  Serial.print(" B: ");
  Serial.println(blue2);
  //delay(15);

  cores();  // chamada da função cores() para ambos sensores
  delay(1000);
}

void cores() {
  // Função para o sensor 1
  Serial.print("Sensor 1 - Cor: ");
  if (blue1 > 25 && red1 > 25 && green1 > 25) {
    Serial.println("Preto");
  } else if (blue1 < 10 && red1 < 10 && green1 < 10) {
    Serial.println("Branco");
  } else if (blue1 < red1 && blue1 < green1) {
    Serial.println("Azul");
  } else if (green1 < red1 && green1 < blue1) {
    Serial.println("Verde");
  } else if (red1 < blue1 && red1 < green1 && red1 < 100) {
    Serial.println("Vermelho");
  }

  // Função para o sensor 2
  Serial.print("Sensor 2 - Cor: ");
  if (blue2 > 25 && red2 > 25 && green2 > 25) {
    Serial.println("Preto");
  } else if (blue2 < 10 && red2 < 10 && green2 < 10) {
    Serial.println("Branco");
  } else if (blue2 < red2 && blue2 < green2) {
    Serial.println("Azul");
  } else if (green2 < red2 && green2 < blue2) {
    Serial.println("Verde");
  } else if (red2 < blue2 && red2 < green2 && red2 < 100) {
    Serial.println("Vermelho");
  }
}
