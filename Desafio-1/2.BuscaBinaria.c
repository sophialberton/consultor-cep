/*2. Implementação de Algoritmo de Busca Binária
Implemente um algoritmo de busca binária que, dado um número inteiro alvo e uma lista de
números inteiros ordenada de forma crescente, retorne o índice da primeira ocorrência do
número na lista. Caso o número não esteja presente, retorne -1.
Regras:
● O algoritmo deve utilizar a estratégia de busca binária (divisão da lista em partes
menores).
● A entrada será sempre uma lista já ordenada.
Exemplo de entrada:
Lista: [5, 12, 18, 23, 45, 70, 89]
Alvo: 23
Exemplo de saída:
3*/

#include <stdio.h>
#include <stdlib.h>

// Função de busca binária
// Retorna o índice da primeira ocorrência do número alvo na lista ordenada
// Caso o número não seja encontrado, retorna -1
int buscaBinaria(int lista[], int tamanho, int alvo) {
    int esquerda = 0, direita = tamanho - 1, meio;

    // Enquanto a parte da lista que estamos buscando não se tornar vazia
    while (esquerda <= direita) {
        meio = esquerda + (direita - esquerda) / 2; // Calcula o meio da lista

        // Se o elemento alvo for encontrado no meio da lista
        if (lista[meio] == alvo) {
            return meio; // Retorna o índice da primeira ocorrência
        }

        // Se o alvo é menor que o valor no meio, a busca vai para a metade esquerda
        if (lista[meio] > alvo) {
            direita = meio - 1;
        }
        // Se o alvo é maior que o valor no meio, a busca vai para a metade direita
        else {
            esquerda = meio + 1;
        }
    }

    return -1; // Caso o número não seja encontrado
}

int main(void) {
    int lista[] = {5, 12, 18, 23, 45, 70, 89}; // Lista de números ordenada
    int alvo, resultado;
    int tamanho = sizeof(lista) / sizeof(lista[0]); // Calcula o tamanho da lista

    // Solicita ao usuário o número alvo que deseja procurar
    printf("Digite o número alvo a ser buscado: ");
    scanf("%d", &alvo);

    // Chama a função de busca binária e armazena o resultado
    resultado = buscaBinaria(lista, tamanho, alvo);

    // Exibe o resultado
    if (resultado != -1) {
        printf("O número %d foi encontrado na posição %d da lista.\n", alvo, resultado);
    } else {
        printf("O número %d não foi encontrado na lista.\n", alvo);
    }

    return 0;
}


