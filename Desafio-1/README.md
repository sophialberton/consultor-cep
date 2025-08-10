# Desafio-1 - Lógica de Programação

Este repositório contém uma série de programas em C que implementam diferentes algoritmos e funcionalidades solicitados no Desafio-1. A seguir, estão os detalhes sobre cada programa implementado.

## Programas Implementados

### 1. Sequência de Fibonacci
Este programa recebe um número inteiro `n` e retorna os primeiros `n` números da sequência de Fibonacci.

**Exemplo de Entrada:**
n = 6

**Exemplo de Saída:**
[0, 1, 1, 2, 3, 5]

---

### 2. Implementação de Algoritmo de Busca Binária
Este programa implementa a busca binária para localizar um número em uma lista ordenada de números inteiros. O programa solicita ao usuário para inserir uma lista de números, verifica se estão em ordem crescente (caso contrário, ordena a lista) e então realiza a busca binária para encontrar o índice de um número alvo.

**Exemplo de Entrada:**
Lista: [5, 12, 18, 23, 45, 70, 89]  
Alvo: 23

**Exemplo de Saída:**
3

---

### 3. Cálculo de Números Perfeitos
Este programa verifica se um número fornecido pelo usuário é perfeito. Um número perfeito é um número inteiro positivo que é igual à soma de todos os seus divisores positivos (exceto ele mesmo).

**Exemplo de Entrada:**
n = 28

**Exemplo de Saída:**
True

---

### 4. Substring Palindrômica Mais Longa
Este programa encontra a maior substring palindrômica dentro de uma string fornecida pelo usuário. Uma substring palindrômica é uma sequência de caracteres que pode ser lida da mesma forma da esquerda para a direita e da direita para a esquerda.

**Exemplo de Entrada:**
"babad"

**Exemplo de Saída:**
"bab" ou "aba"

---

### 5. Simulação de Saque em Caixa Eletrônico
Este programa simula o saque em um caixa eletrônico. Ele recebe um valor monetário e retorna a quantidade mínima de notas e moedas necessárias para compor esse valor, priorizando as notas de maior valor.

**Exemplo de Entrada:**
valor = 130

**Exemplo de Saída:**
1 nota de 100  
1 nota de 20  
1 nota de 10

### Funcionalidade de Repetição
Além disso, todos os programas acima permitem que o usuário repita a execução do programa, conforme escolha, através de uma opção interativa após cada execução.

---

## Como Rodar os Programas

1. Clone o repositório:
    ```bash
    git clone https://github.com/sophialberton/Estagio-Desenvolvimento-UltraLims.git
    ```

2. Entre no diretório do projeto:
    ```bash
    cd Desafio-1
    ```

3. Compile o código:
    Para compilar qualquer programa, use o seguinte comando:
    ```bash
    gcc nome_do_programa.c -o nome_do_programa
    ```

4. Execute o programa compilado:
    ```bash
    ./nome_do_programa
    ```

---

## Como Funciona Cada Programa

### 1. Sequência de Fibonacci
A sequência de Fibonacci começa com os números 0 e 1, e cada número subsequente é a soma dos dois números anteriores. O programa pede para o usuário informar quantos números deseja visualizar dessa sequência.

### 2. Busca Binária
A busca binária é uma técnica eficiente para encontrar um elemento em uma lista ordenada. O programa primeiro verifica se a lista fornecida está em ordem crescente, e se não estiver, ordena antes de realizar a busca binária.

### 3. Números Perfeitos
O programa verifica se um número é perfeito somando todos os seus divisores positivos (exceto ele mesmo) e comparando essa soma com o número original.

### 4. Substring Palindrômica Mais Longa
Este programa encontra a maior substring de uma string fornecida que seja palindrômica. Ele utiliza uma abordagem de tentativa e erro para verificar todas as possíveis substrings e escolher a maior.

### 5. Simulação de Saque em Caixa Eletrônico
Simula o funcionamento de um caixa eletrônico, determinando a quantidade mínima de cédulas e moedas necessárias para atender a um valor informado. O programa segue a lógica de sempre priorizar as cédulas de maior valor.

---

## Requisitos
- **Compilador C**: Para compilar e executar os programas, você precisa ter um compilador C instalado, como o GCC.
- **Sistema Operacional**: Os programas podem ser executados em qualquer sistema operacional que tenha um compilador C instalado (Linux, macOS, Windows, etc.).

---

## Licença

Este projeto está licenciado sob a [Licença MIT](https://opensource.org/licenses/MIT).
