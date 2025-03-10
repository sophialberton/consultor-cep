/*5. Simulação de Saque em Caixa Eletrônico
Implemente um programa que receba um valor monetário inteiro e retorne a quantidade
mínima de notas e moedas necessárias para compor esse valor. O programa deve sempre
priorizar as notas de maior valor primeiro.
Notas e moedas disponíveis:
● Notas: 100, 50, 20, 10, 5, 2
● Moedas: 1
Regras:
● O valor sempre será inteiro e positivo.
● Deve-se minimizar a quantidade de cédulas e moedas utilizadas.
Exemplo de entrada:
valor = 130
Exemplo de saída:
1 nota de 100
1 nota de 20

1 nota de 10*/

#include <stdio.h>

int main() {
    int valor;
    char repetir;

    do {
        // Solicita o valor monetário ao usuário
        printf("Digite o valor do saque: ");
        scanf("%d", &valor);

        // Verifica se o valor é válido
        if (valor <= 0) {
            printf("Valor invalido. O valor deve ser positivo.\n");
            return 1;
        }

        // Notas disponíveis
        int notas[] = {100, 50, 20, 10, 5, 2};
        int n_notas = sizeof(notas) / sizeof(notas[0]);

        // Moeda disponível
        int moeda = 1;

        // Laço para calcular as notas
        for (int i = 0; i < n_notas; i++) {
            if (valor >= notas[i]) {
                int qtd_notas = valor / notas[i]; // Calcula a quantidade de notas
                valor %= notas[i]; // Atualiza o valor restante após o saque
                printf("%d nota(s) de %d\n", qtd_notas, notas[i]);
            }
        }

        // Caso haja valor restante em moeda
        if (valor > 0) {
            printf("%d moeda(s) de %d\n", valor / moeda, moeda);
        }

        // Pergunta se o usuário quer repetir o programa
        printf("Repetir programa? (s/n): ");
        getchar();  // Limpa o buffer do teclado
        scanf("%c", &repetir);

        // Verifica a resposta do usuário
        switch (repetir) {
            case 's':
            case 'S':
                break;  // Repetir o programa
            case 'n':
            case 'N':
                printf("Programa finalizado.\n");
                return 0;  // Finaliza o programa
            default:
                printf("Opcao invalida. Programa finalizado.\n");
                return 1;  // Finaliza o programa
        }

    } while (repetir == 's' || repetir == 'S');  // Se a resposta for 's', o programa se repete

    return 0;
}
