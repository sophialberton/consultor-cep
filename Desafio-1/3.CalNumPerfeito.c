/*3. Cálculo de Números Perfeitos
Um número perfeito é um número inteiro positivo que é igual à soma de todos os seus
divisores positivos, excluindo ele mesmo. Implemente um programa que verifique se um
número dado é perfeito.
Exemplo de entrada:
n = 28
Exemplo de saída:
True

Explicação:
Os divisores de 28 são: 1, 2, 4, 7, 14
Soma: 1 + 2 + 4 + 7 + 14 = 28 → Portanto, 28 é um número perfeito.*/

#include <stdio.h>

// Função para verificar se o número é perfeito
int verifica_numero_perfeito(int n) {
    int soma = 0;

    // Encontra os divisores de n e soma-os (excluindo n mesmo)
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            soma += i;
        }
    }

    // Se a soma dos divisores for igual ao número, ele é perfeito
    return soma == n;
}

int main() {
    int n;
    int resultado;  // Variável para armazenar o retorno da função scanf

    // Solicita o número para verificar se é perfeito
    printf("Digite um numero inteiro para verificar se ele é perfeito: ");
    
    // Verifica se a entrada é válida
    resultado = scanf("%d", &n);

    // Caso o usuário não tenha digitado um número inteiro válido
    if (resultado != 1) {
        printf("Erro! Voce deve digitar um numero inteiro valido.\n");
        return 1; // Encerra o programa caso a entrada não seja válida
    }

    // Verifica se o número é perfeito
    if (n <= 0) {
        printf("Numero invalido. O numero deve ser um inteiro positivo.\n");
    } else if (verifica_numero_perfeito(n)) {
        printf("True\n"); // Se o número for perfeito
    } else {
        printf("False\n"); // Se o número não for perfeito
    }

    return 0;
}
