#include <AFMotor.h>

// Motores dianteiros DIR e ESQ
AF_DCMotor motor1(1);
AF_DCMotor motor2(4);

// Motores traseiros DIR e ESQ
AF_DCMotor motor3(2); 
AF_DCMotor motor4(3); 

const unsigned long moveDuration = 10000; // Duração do movimento em milissegundos
const unsigned long stopDuration = 1000; // Tempo para parar os motores antes de iniciar o próximo movimento
void norte()
{
  motor1.setSpeed(90); // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(120); // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(140); // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(120); // M3 = 104 RPM(60) ; 136rpm (100)
                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void sul(){
  motor1.setSpeed(90); // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(120); // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(140); // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(120); // M3 = 104 RPM(60) ; 136rpm (100)

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void leste(){
  motor1.setSpeed(90); // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(120); // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(140); // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(120); // M3 = 104 RPM(60) ; 136rpm (100)

  motor1.run(FORWARD); //m1
  motor2.run(BACKWARD);
  motor3.run(BACKWARD); //m2
  motor4.run(FORWARD);
}

void oeste(){
  motor1.setSpeed(90); // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(120); // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(140); // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(120); // M3 = 104 RPM(60) ; 136rpm (100)

  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void nordeste(){
  motor1.setSpeed(90); // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(0); // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(0); // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(120); // M3 = 104 RPM(60) ; 136rpm (100)

  motor1.run(FORWARD); //m1
  motor2.run(RELEASE);
  motor3.run(RELEASE); //m2
  motor4.run(FORWARD);
}

void noroeste(){
  motor1.setSpeed(0); // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(120); // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(120); // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(0); // M3 = 104 RPM(60) ; 136rpm (100)

  motor1.run(RELEASE); //M1
  motor2.run(FORWARD);
  motor3.run(FORWARD); //M2
  motor4.run(RELEASE);
}

void pararMotores(){

  motor1.setSpeed(0); // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(0); // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(0); // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(0); // M3 = 104 RPM(60) ; 136rpm (100)
} 

void setup()
{
  // Define a velocidade maxima para os motores 1 e 2
  motor1.setSpeed(0); // M1 
  motor2.setSpeed(0); // M4
  motor3.setSpeed(0); // M2
  motor4.setSpeed(0); // M3

  pararMotores();

}


void loop()
{
  norte();
  delay(moveDuration);
  pararMotores();
  delay(stopDuration);


  sul();
  delay(moveDuration);
  pararMotores();
  delay(stopDuration);


  leste();
  delay(moveDuration);
  pararMotores();
  delay(stopDuration);


  oeste();
  delay(moveDuration);
  pararMotores();
  delay(stopDuration);


  nordeste();
  delay(moveDuration);
  pararMotores();
  delay(stopDuration);


  noroeste();
  delay(moveDuration);
  pararMotores();
  delay(stopDuration);

}


