# robotica
Códigos usados na programação e configuração do robô competitivo da OBR estadual 2024, EVA 2.0

Lógica do código:
Lógica dos Sensores de Cor e Infravermelho:

Sensores de Cor:
- O sensor de cor lê três valores: Vermelho, Verde e Azul.
- Se os três valores estiverem acima de 25, a cor lida é **preto**.
- Se os três valores estiverem abaixo de 10, a cor lida é **branco**.
- Se o valor mais baixo lido for o Vermelho, a cor lida é **vermelho**.
- Se o valor mais baixo lido for o Verde, a cor lida é **verde**.
- Se o valor mais baixo lido for o Azul, a cor lida é **azul**.

  Observações:
  - Azul e Branco contam como Branco.
  - Vermelho e Preto contam como Preto.
  - Verde conta como Verde.

Sensor Infravermelho:
- O sensor infravermelho lê valores de intensidade de luz refletida:
  - Preto: Alta absorção de luz (baixa leitura de retorno).
  - Branco: Baixa absorção de luz (alta leitura de retorno).

  Uso nas Interseções:
  - O sensor infravermelho complementa os sensores de cor para identificar de forma precisa se o robô está sobre uma linha preta, branca ou se está em uma interseção.

---

Lógica de Andar:

1. Prioridade para o Sensor Ultrassônico:
   - O loop começa verificando se a distância lida pelo sensor ultrassônico é igual ou inferior a 8 cm.
   - Se for igual ou abaixo de 8 cm, as rodas devem iniciar o movimento de desvio, que consiste em:
     - Parar, virar para Oeste, depois para Norte, Leste, Parar novamente.
     - Após isso, recomeçar o loop para procurar novas informações.

2. Lógica do Seguidor de Linha:o
   - Caso ambos os sensores de cor leiam Branco: O robô avança em linha reta, pois está centralizado entre as bordas brancas da linha preta.
   - Caso o sensor esquerdo leia Preto e o sensor direito leia Branco: O robô deve virar levemente à esquerda para recentralizar a linha preta entre os sensores.
   - Caso o sensor direito leia **Preto** e o sensor esquerdo leia Branco: O robô deve virar levemente à direita para recentralizar a linha preta entre os sensores.

---

Lógica para Interseções com Sensor Infravermelho:

1. Identificação de Interseções:
   - O sensor infravermelho é utilizado para confirmar se o robô está sobre uma interseção ao detectar um valor de Preto consistente junto com as leituras dos sensores de cor.

2. Ativação da Tomada de Decisão (Sensor Verde):
   - Quando o sensor de cor detecta Verde, a lógica de interseção é ativada.
   - O sensor infravermelho é utilizado para verificar se o robô está de fato em uma interseção, diferenciando entre uma linha contínua preta e uma área preta de interseção.
   -  Para intersecções, o robô deverá utilizar um sistema de variáveis que armazena os valores de leitura atuais e anteriores para determinar para qual caminho ele deverá ir.

3. Situações de Interseção:

   - Situação 1:
     - Valor Atual:
       - Sensor Esquerdo = Verde
       - Sensor Direito = Verde
       - Infravermelho = Preto
     - Ação: Dar volta e meia no próprio eixo e seguir em frente.

   - Situação 2:
     - Valor Atual:
       - Sensor Esquerdo = Branco
       - Sensor Direito = Verde
       - Infravermelho = Preto
     - Ação: Virar para a direita.

   - Situação 3:
     - Valor Atual:
       - Sensor Esquerdo = Verde
       - Sensor Direito = Branco
       - Infravermelho = Preto
     - Ação: Virar para a esquerda.

   - Situação 4:
     - Valor Atual:
       - Sensor Esquerdo = Preto
       - Sensor Direito = Preto
       - Infravermelho = Preto
     - Valor Anterior:
       - Sensor Esquerdo = Branco
       - Sensor Direito = Branco
     - Ação: Ir para frente.


   - Situação 6:
     - Valor Atual:
       - Sensor Esquerdo = Branco
       - Sensor Direito = Preto
       - Infravermelho = Preto
     - Valor Anterior:
       - Sensor Esquerdo = Branco
       - Sensor Direito = Branco
     - Ação: Ir para frente.


   - Situação 7:
     - Valor Atual:
       - Sensor Esquerdo = Preto 
       - Sensor Direito = Branco
       - Infravermelho = Preto
     - Valor Anterior:
       - Sensor Esquerdo = Branco
       - Sensor Direito = Branco
     - Ação: Ir para frente.


   - Situação 8:
     - Valor Atual:
       - Sensor Esquerdo = Verde
       - Sensor Direito = Branco
       - Infravermelho = Preto
     - Valor Anterior:
       - Sensor Esquerdo = Preto
       - Sensor Direito = Preto
     - Ação: Ir para frente.


   - Situação 9:
     - Valor Atual:
       - Sensor Esquerdo = Branco
       - Sensor Direito = Verde
       - Infravermelho = Preto
     - Valor Anterior:
       - Sensor Esquerdo = Preto
       - Sensor Direito = Preto
     - Ação: Ir para frente.
