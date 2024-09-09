void norte() {
  motor1.step(-stepsToMove); // para trás
  motor2.step(stepsToMove);
  motor3.step(-stepsToMove); // para trás
  motor4.step(stepsToMove);
    
}

void sul() {
  motor1.step(stepsToMove);
  motor2.step(-stepsToMove);
  motor3.step(stepsToMove);
  motor4.step(-stepsToMove);

}

void leste() {
  motor1.step(-stepsToMove);
  motor2.step(-stepsToMove);
  motor3.step(stepsToMove);
  motor4.step(stepsToMove);
}

void oeste() {
  motor1.step(stepsToMove);
  motor2.step(stepsToMove);
  motor3.step(-stepsToMove);
  motor4.step(-stepsToMove);
}

void nordeste() {
  motor1.step(-stepsToMove);
  motor2.step(0);
  motor3.step(0);
  motor4.step(stepsToMove);

}

void noroeste() {
  motor1.step(0);
  motor2.step(stepsToMove);
  motor3.step(-stepsToMove);
  motor4.step(0);
}

void pararMotores() {
  motor1.step(0);
  motor2.step(0);
  motor3.step(0);
  motor4.step(0);
}


void eixoHorario(){
  motor1.step(stepsToMove);
  motor2.step(stepsToMove);
  motor3.step(stepsToMove);
  motor4.step(stepsToMove);
}

void eixoAntihorario(){
  motor1.step(-stepsToMove);
  motor2.step(-stepsToMove);
  motor3.step(-stepsToMove);
  motor4.step(-stepsToMove);
}

