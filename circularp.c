#include <stdio.h>
int main() {

    // Variaveis
    char nome[10][50];
    int tempoP[10], restante[10], espera[10], turnaround[10];
    int n = 0, quantum, opcao;
    int tempo, concluidos, exec;
    float total_espera, total_turnaround;

    printf("Entre com o quantum: ");
    scanf("%d", &quantum);

    // Menu principal
    do {
        printf("\n1 - Inserir\n2 - Mostrar\n3 - Round Robin\n4 - Sair\n");
        printf("\nEscolha sua opcao: ");
        scanf("%d", &opcao);

        // Inserir processo
        if (opcao == 1) {
            printf("\nNome do processo: ");
            scanf("%s", nome[n]);
            printf("Tempo de processamento: ");
            scanf("%d", &tempoP[n]);
            restante[n] = tempoP[n];
            n++;
            printf("-----------------------------\n");
        }

        // Mostrar processos
        else if (opcao == 2) {
            printf("\nProcesso\tTempo\n");
            for (int i = 0; i < n; i++)
                printf("%s\t\t%d\n", nome[i], tempoP[i]);
        }

        // Executar Round Robin
        else if (opcao == 3) {
            tempo = 0;
            concluidos = 0;
            total_espera = 0;
            total_turnaround = 0;

            for (int i = 0; i < n; i++) {
                restante[i] = tempoP[i];
                espera[i] = 0;
                turnaround[i] = 0;
            }

            while (concluidos < n) {
                for (int i = 0; i < n; i++) {
                    if (restante[i] > 0) {
                        if (restante[i] < quantum)
                            exec = restante[i];
                        else
                            exec = quantum;

                        tempo += exec;
                        restante[i] -= exec;

                        if (restante[i] == 0) {
                            turnaround[i] = tempo;
                            espera[i] = turnaround[i] - tempoP[i];
                            concluidos++;
                        }
                    }
                }
            }

            // Exibir resultados
            for (int i = 0; i < n; i++) {
                printf("\nProcesso: %s\n", nome[i]);
                printf("Tempo de Espera: %d\n", espera[i]);
                printf("Tempo de Resposta: %d\n", turnaround[i]);
                total_espera += espera[i];
                total_turnaround += turnaround[i];
            }

            printf("\nEspera: %2.f\n", total_espera);
            printf("Resposta: %2.f\n", total_turnaround);
            printf("Tempo medio espera (tme): %2.f\n", total_espera / n);
            printf("Tempo medio retorno (tmr): %2.f\n", total_turnaround / n);
        }

        // Sair
        else if (opcao == 4) {
            printf("Saindo...\n");
        }

        else {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 4);

    return 0;
}
