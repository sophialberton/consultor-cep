/*4. Substring Palindrômica Mais Longa
Implemente um programa que, dada uma string, encontre a maior substring palindrômica
dentro dela.
Regras:
● Uma substring palindrômica é uma sequência de caracteres que pode ser lida da
mesma forma da esquerda para a direita e da direita para a esquerda.
● Caso haja múltiplas substrings de mesmo tamanho, retorne qualquer uma delas.
Exemplo de entrada:
"babad"
Exemplo de saída:
"bab"`` ou "aba"`*/

#include <stdio.h>
#include <string.h>

// Função para verificar se uma string é um palíndromo
int eh_palindromo(char str[], int inicio, int fim) {
    while (inicio < fim) {
        if (str[inicio] != str[fim]) {
            return 0; // Não é um palíndromo
        }
        inicio++;
        fim--;
    }
    return 1; // É um palíndromo
}

// Função para encontrar a maior substring palindrômica
void maior_palindromo(char str[]) {
    int n = strlen(str);
    int maior_inicio = 0, maior_tamanho = 1;

    // Itera sobre todas as possíveis substrings
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // Verifica se a substring é um palíndromo
            if (eh_palindromo(str, i, j)) {
                int tamanho = j - i + 1;
                if (tamanho > maior_tamanho) {
                    maior_tamanho = tamanho;
                    maior_inicio = i; // Armazena o início da maior substring
                }
            }
        }
    }

    // Exibe a maior substring palindrômica
    for (int i = maior_inicio; i < maior_inicio + maior_tamanho; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    char str[100];

    // Solicita ao usuário que digite a string
    printf("Digite a string para encontrar a maior substring palindromica: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove o caractere de nova linha, se houver

    // Chama a função para encontrar a maior substring palindrômica
    maior_palindromo(str);

    return 0;
}


