#include <Stepper.h>

// Número de passos necessários para completar uma revolução
const int stepsPerRevolution = 2048;

// Inicialização dos motores de passo
//IN1 - IN3 - IN2 - IN4
Stepper stepperName = Stepper(stepsPerRevolution, 24, 26, 25, 27);
Stepper stepperName2 = Stepper(stepsPerRevolution, 28, 30, 29, 31);
Stepper stepperName3 = Stepper(stepsPerRevolution, 34, 36, 35, 37);
Stepper stepperName4 = Stepper(stepsPerRevolution, 38, 40, 39, 41);

void setup() {
  // Configura a velocidade dos motores
  stepperName.setSpeed(22);
  stepperName2.setSpeed(22);
  stepperName3.setSpeed(22);
  stepperName4.setSpeed(22);
}

void loop() {
  // Número de passos a serem dados por iteração (ajuste conforme necessário)
  const int stepsToMove = 1;

  // Executa os passos dos motores simultaneamente
  for (int i = 0; i < stepsPerRevolution; i += stepsToMove) {
    stepperName.step(stepsToMove);
    stepperName2.step(stepsToMove);
    stepperName3.step(stepsToMove);
    stepperName4.step(stepsToMove);
    
  }
}
