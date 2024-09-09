int leituraCorSensor1() {
  if (blue1 > 30 && red1 > 30 && green1 > 350) {
    //Serial.println("Sensor 1: Preto");
    return COR_PRETO;
    //valAnterior1 = 0;
  } else if (blue1 <= 10 && red1 <= 10 && green1 <= 10) {
    //Serial.println("Sensor 1: Branco");
    return COR_BRANCO;
    //valAnterior1 = 1;
  } else if (blue1 < red1 && blue1 < green1) {
    //Serial.println("Sensor 1: Preto");
    return COR_PRETO;
  } else if (green1 <= red1 && green1 <= blue1) {
    //Serial.println("Sensor 1: Verde");
    return COR_VERDE;
    //valAnterior1 = 2;
  } else if (red1 < blue1 && red1 < green1 && red1 < 100) {
    //Serial.println("Sensor 1: Vermelho"); 
    return COR_VERMELHO;
  } else {
    return COR_INDETERMINADA;
  }
}

int leituraCorSensor2() {
  if (blue2 > 30 && red2 > 30 && green2 > 30) {
    //Serial.println(" Sensor 2: Preto");
    return COR_PRETO;
    //valAnterior2 = 0;
  } else if (blue2 <= 10 && red2 <= 10 && green2 <= 10) {
    //Serial.println(" Sensor 2: Branco");
    return COR_BRANCO;
    //valAnterior2 = 1;
  } else if (blue2 < red2 && blue2 < green2) {
    //Serial.println(" Sensor 2: Preto");
    return COR_PRETO;
  } else if (green2 <= red2 && green2 <= blue2) {
    //Serial.println("Sensor 2: Verde");
    return COR_VERDE;
    //valAnterior2 = 2;
    } else if (red2 < blue2 && red2 < green2 && red2 < 100) {
    //Serial.println("Sensor 2: Vermelho"); 
    return COR_VERMELHO;
  } else {
    return COR_INDETERMINADA;
  }
}


void leituraSensores() {
  // Leitura do sensor 1
  digitalWrite(PinS21, LOW);
  digitalWrite(PinS31, LOW);
  red1 = pulseIn(PinOUT1, LOW);
  //Serial.print("Sensor 1 - R: ");
  //Serial.println(red1);
  //delay(15);

  digitalWrite(PinS21, HIGH);
  digitalWrite(PinS31, HIGH);
  green1 = pulseIn(PinOUT1, LOW);
  //Serial.print(" G: ");
  //Serial.println(green1);
  //delay(15);

  digitalWrite(PinS21, LOW);
  digitalWrite(PinS31, HIGH);
  blue1 = pulseIn(PinOUT1, LOW);
  //Serial.print(" B: ");
  //Serial.println(blue1);
  //delay(15);

  // Leitura do sensor 2
  digitalWrite(PinS22, LOW);
  digitalWrite(PinS32, LOW);
  red2 = pulseIn(PinOUT2, LOW);
  //Serial.print("Sensor 2 - R: ");
  //Serial.print(red2);
  //delay(15);

  digitalWrite(PinS22, HIGH);
  digitalWrite(PinS32, HIGH);
  green2 = pulseIn(PinOUT2, LOW);
  //Serial.print(" G: ");
  //Serial.print(green2);
  //delay(15);

  digitalWrite(PinS22, LOW);
  digitalWrite(PinS32, HIGH);
  blue2 = pulseIn(PinOUT2, LOW);
  //Serial.print(" B: ");
  //Serial.println(blue2);
  //delay(15);

  int cor1 = leituraCorSensor1();
  int cor2 = leituraCorSensor2();
}
