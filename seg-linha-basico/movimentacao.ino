void norte()
{
  motor1.setSpeed(90); // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(120); // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(120); // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(120); // M3 = 104 RPM(60) ; 136rpm (100)
                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void sul(){
  motor1.setSpeed(90); // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(120); // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(120); // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(120); // M3 = 104 RPM(60) ; 136rpm (100)

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void leste(){
  motor1.setSpeed(90); // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(120); // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(120); // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(120); // M3 = 104 RPM(60) ; 136rpm (100)

  motor1.run(FORWARD); //m1
  motor2.run(BACKWARD);
  motor3.run(BACKWARD); //m2
  motor4.run(FORWARD);
}

void oeste(){
  motor1.setSpeed(90); // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(120); // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(120); // M2 = 100 RPM(60) ; 176rpm (100)
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

void correcaoEsquerda(){
  motor1.setSpeed(90); // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(120); // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(120); // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(120); // M3 = 104 RPM(60) ; 136rpm (100)

  motor1.run(RELEASE); //m1
  motor2.run(FORWARD); //m4
  motor3.run(RELEASE); //m2
  motor4.run(FORWARD); //m3

}

void correcaoDireita(){
  motor1.setSpeed(90); // M1 = 80 RPM(60) ; 100RPM(70) ; 128rpm (100)
  motor2.setSpeed(120); // M4 = 64 RPM(60) ; 100RPM(93) ; 156rpm (100)
  motor3.setSpeed(120); // M2 = 100 RPM(60) ; 176rpm (100)
  motor4.setSpeed(120); // M3 = 104 RPM(60) ; 136rpm (100)

  motor1.run(FORWARD); //m1
  motor2.run(RELEASE); //m4
  motor3.run(FORWARD); //m2
  motor4.run(RELEASE); //m3
}