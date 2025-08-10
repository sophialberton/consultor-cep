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
#include <string.h>

// Função para comparar dois números, usada na função qsort()
int compare(const void *a, const void *b)
{
    // Compara dois números float
    if (*(float *)a > *(float *)b)
        return 1; // Se o primeiro número é maior, retorna 1
    if (*(float *)a < *(float *)b)
        return -1; // Se o primeiro número é menor, retorna -1
    return 0;      // Se os números são iguais, retorna 0
}

// Função para realizar a busca binária
int busca_binaria(float lista[], int n, float alvo)
{
    int inicio = 0, fim = n - 1;

    // Loop de busca binária
    while (inicio <= fim)
    {
        // Calcula o meio da lista
        int meio = inicio + (fim - inicio) / 2;

        // Verifica se o elemento do meio é o alvo
        if (lista[meio] == alvo)
        {
            return meio; // Retorna o índice do alvo
        }

        // Se o valor do meio é menor que o alvo, move o início para a direita
        if (lista[meio] < alvo)
        {
            inicio = meio + 1;
        }
        else
        {
            // Se o valor do meio é maior que o alvo, move o final para a esquerda
            fim = meio - 1;
        }
    }
    return -1; // Retorna -1 se não encontrar o alvo
}

int main()
{
    char input[1024];       // Buffer para armazenar a entrada do usuário
    float lista[100], alvo; // Lista de números e o alvo para busca
    int n = 0;              // Contador para o número de elementos na lista

    // Solicita ao usuário para digitar os números separados por espaços
    printf("Digite os numeros separados por espacos e em ordem crescente(pressione Enter quando terminar): ");
    fgets(input, sizeof(input), stdin); // Lê a entrada do usuário como uma string

    // Percorre a string de entrada e extrai os números
    char *token = strtok(input, " \n"); // Divida a string por espaços e quebras de linha
    while (token != NULL)
    {
        // Tenta converter a string para um número float
        if (sscanf(token, "%f", &lista[n]) == 1)
        {        // Verifica se é um número de ponto flutuante
            n++; // Incrementa o contador de números
        }
        else
        {
            // Se não for um número válido, exibe mensagem de erro e termina o programa
            printf("Erro! Voce deve digitar apenas numeros. Tente novamente.\n");
            return 1;
        }
        token = strtok(NULL, " \n"); // Obtém o próximo número
    }

    // Verifica se a lista está em ordem crescente
    int lista_crescente = 1;
    for (int i = 0; i < n - 1; i++)
    {
        // Se encontrar um número maior que o próximo, a lista não está em ordem crescente
        if (lista[i] > lista[i + 1])
        {
            lista_crescente = 0; // Marca a lista como não crescente
            break;
        }
    }

    // Se a lista não estiver em ordem crescente, ordena ela
    if (!lista_crescente)
    {
        printf("Voce nao escreveu a lista em ordem crescente, mas tudo bem! Dessa vez eu deixo em crescente pra voce!\n");
        qsort(lista, n, sizeof(float), compare); // Ordena a lista
        // Exibe a lista ordenada sem casas decimais se o número for inteiro
        printf("Lista em ordem crescente: ");
        for (int i = 0; i < n; i++)
        {
            if (lista[i] == (int)lista[i])
            {                                 // Verifica se o número é inteiro
                printf("%d ", (int)lista[i]); // Exibe como número inteiro
            }
            else
            {
                printf("%.2f ", lista[i]); // Exibe como número decimal
            }
        }
        printf("\n");
    }

    // Solicita o número alvo para a busca binária
    printf("Digite o numero alvo para a busca binaria: ");
    // Verifica se o número alvo digitado é válido
    while (scanf("%f", &alvo) != 1)
    {
        // Se o usuário digitar algo que não é um número válido
        printf("Erro! Voce deve digitar um numero valido. Tente novamente: ");
        while (getchar() != '\n') // Limpa o buffer de entrada
            ;
    }

    // Realiza a busca binária
    int resultado = busca_binaria(lista, n, alvo);

    // Exibe o resultado da busca binária
    if (resultado != -1)
    {
        // Se o alvo for um número inteiro
        if (alvo == (int)alvo)
        {
            printf("O numero %.0f foi encontrado no indice %d.\n", alvo, resultado);
        }
        else
        {
            // Se o alvo for um número decimal
            printf("O numero %.2f foi encontrado no indice %d.\n", alvo, resultado);
        }
    }
    else
    {
        // Se o alvo não foi encontrado
        if (alvo == (int)alvo)
        { // Se o alvo for um número inteiro
            printf("O numero %.0f nao foi encontrado na lista.\n", alvo);
        }
        else
        {
            // Se o alvo for um número decimal
            printf("O numero %.2f nao foi encontrado na lista.\n", alvo);
        }
    }

    return 0; // Finaliza o programa
}
