void desviar() {
  pararMotores();
  delay(800);

  // Vira para a esquerda
  oeste();
  delay(3100);
  pararMotores();
  delay(500);

  norte();
  delay(5000);

  // Vira para a direita (posição inicial)
  leste();
  delay(3100);
  pararMotores();
  delay(1000);
}