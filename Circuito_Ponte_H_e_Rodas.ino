#define PINO_IN1 6  // Pino responsável pelo controle no sentido horário
#define PINO_IN2 7  // Pino responsável pelo controle no sentido anti-horário
#define PINO_IN3 8  // Pino responsável pelo controle no sentido horário
#define PINO_IN4 9  // Pino responsável pelo controle no sentido anti-horário

void setup(){ 
  // Configura os pinos de controle como saída
  pinMode(PINO_IN1, OUTPUT);  // Define o pino IN1 como saída
  pinMode(PINO_IN2, OUTPUT);  // Define o pino IN2 como saída
  pinMode(PINO_IN3, OUTPUT);  // Define o pino IN3 como saída
  pinMode(PINO_IN4, OUTPUT);  // Define o pino IN4 como saída
}
  
void loop() {   
  int valor_pwm = 0;  // Variável para armazenar o valor PWM (0-255)

  // Aumenta a velocidade gradualmente de 0% a 100% no sentido horário no Motor 1
  for (valor_pwm = 0; valor_pwm < 256; valor_pwm++) {
    analogWrite(PINO_IN1, valor_pwm);  // Aplica o valor PWM no pino IN1
    delay(100);  // Espera 100 ms antes de aumentar a velocidade
  }
 
  // Diminui a velocidade gradualmente de 100% a 0% no sentido horário no Motor 1
  for (valor_pwm = 255; valor_pwm >= 0; valor_pwm--) {
    analogWrite(PINO_IN1, valor_pwm);  // Reduz o valor PWM no pino IN1
    delay(100);  // Espera 100 ms antes de diminuir mais a velocidade
  }

  // Aumenta a velocidade gradualmente de 0% a 100% no sentido anti-horário no motor 2
  for (valor_pwm = 0; valor_pwm < 256; valor_pwm++) {
    analogWrite(PINO_IN2, valor_pwm);  // Aplica o valor PWM no pino IN2
    delay(100);  // Espera 100 ms antes de aumentar a velocidade
  }
 
  // Diminui a velocidade gradualmente de 100% a 0% no sentido anti-horário
  for (valor_pwm = 255; valor_pwm >= 0; valor_pwm--) {
    analogWrite(PINO_IN2, valor_pwm);  // Reduz o valor PWM no pino IN2
    delay(100);  // Espera 100 ms antes de diminuir mais a velocidade
  } 
  // Aumenta a velocidade gradualmente de 0% a 100% no sentido anti-horário
  for (valor_pwm = 0; valor_pwm < 256; valor_pwm++) {
    analogWrite(PINO_IN3, valor_pwm);  // Aplica o valor PWM no pino IN2
    delay(100);  // Espera 100 ms antes de aumentar a velocidade
  }
 
  // Diminui a velocidade gradualmente de 100% a 0% no sentido anti-horário
  for (valor_pwm = 255; valor_pwm >= 0; valor_pwm--) {
    analogWrite(PINO_IN3, valor_pwm);  // Reduz o valor PWM no pino IN2
    delay(100);  // Espera 100 ms antes de diminuir mais a velocidade
  } 
  // Aumenta a velocidade gradualmente de 0% a 100% no sentido anti-horário
  for (valor_pwm = 0; valor_pwm < 256; valor_pwm++) {
    analogWrite(PINO_IN4, valor_pwm);  // Aplica o valor PWM no pino IN2
    delay(100);  // Espera 100 ms antes de aumentar a velocidade
  }
 
  // Diminui a velocidade gradualmente de 100% a 0% no sentido anti-horário
  for (valor_pwm = 255; valor_pwm >= 0; valor_pwm--) {
    analogWrite(PINO_IN4, valor_pwm);  // Reduz o valor PWM no pino IN2
    delay(100);  // Espera 100 ms antes de diminuir mais a velocidade
  } 
}
