### Integrantes/Funções:
<ul>
  <li>Cláudio Dias Alves (10403569): Responsável pela clonagem e salvamento do repositório
  <li>Guillermo Kuznietz (10410134): Responsável pelo desenvolvimento do código
  <li>Gabriel Nogueira (10409493): Responsável pela documentação
</ul>

# 1. Compilar o programa
``` git clone git@github.com:<url_do_seu_repositorio> ```

![Captura de tela 2024-03-11 075047](https://github.com/soyclaudiodias/sistemas_operacionais/assets/113221142/8219cabc-74e5-4495-ac61-ec790f23d3f0)

# 2. Executar o programa
``` ./exercicio1.c ```

![Captura de tela 2024-03-11 075047](https://github.com/soyclaudiodias/sistemas_operacionais/assets/113221142/8219cabc-74e5-4495-ac61-ec790f23d3f0)

# 3. Análise do resultado
<p align="justify">
Nosso programa usa se um pipe (um jeito muito bom de fazer dois processos se comunicarem no sistema UNIX) para que o processo pai possa receber informações do processo filho. Primeiro, criamos um pipe e depois dividimos o processo em dois: pai e filho. O filho aumenta um número em 15 e manda essa informação pelo pipe. Depois de mandar, ele termina. O pai espera o filho terminar, lê a informação do pipe e então termina também.

Quando rodar o programa, deve aparecer no terminal:
><br>Entrei no Filho!
<br>CHILD: value = 20
<br>FATHER: value = 20

Isso mostra que o número que o filho mudou chegou certinho até o pai.
</p>
