/*1. Sequência de Fibonacci
Crie um programa que, dado um número inteiro n, retorne os primeiros n números da
sequência de Fibonacci.
Exemplo de entrada:
n = 6
Exemplo de saída:
[0, 1, 1, 2, 3, 5]*/
    
#include <stdio.h>
#include <stdlib.h>

// Função para gerar e imprimir os primeiros n números da sequência de Fibonacci
void fibonacci(int n) {
    // Definindo as duas primeiras variáveis da sequência
    int t1 = 0, t2 = 1, nextTerm;

    // Caso n seja 0 ou negativo, a sequência não é válida
    if (n <= 0) {
        printf("Por favor, insira um numero maior que 0.\n");
        return;
    }

    printf("Sequencia de Fibonacci com os primeiros %d numeros: \n", n);

    // Imprime os primeiros números da sequência (0 e 1)
    printf("%d, %d", t1, t2);

    // Gera os próximos números da sequência
    for (int i = 3; i <= n; i++) {
        nextTerm = t1 + t2;  // Soma os dois números anteriores
        printf(", %d", nextTerm); // Exibe o próximo número
        t1 = t2;  // Atualiza o t1 para o t2
        t2 = nextTerm;  // Atualiza o t2 para o próximo número
    }

    printf("\n"); // Linha final após a impressão da sequência
}

int main(void) {
    int n;

    // Solicita ao usuário que insira o valor de n
    printf("Digite o numero de termos da sequencia de Fibonacci: ");
    scanf("%d", &n);

    // Chama a função para gerar e exibir a sequência de Fibonacci
    fibonacci(n);

    return 0;
}
