/*
fazer codigo exemplo com ciclos
*/
#include <stdio.h>

int main()
{
    int temperatura = 0;

    // 1. introduzir a temperatura inicial
    printf("introduza a temperatura: ");
    scanf("%d", &temperatura);

    // 2. enquanto a temperatura for superior a 40, continua a pedir para introduzir a temperatura
    // simulação de temperatura, atraves do taclado.
    while (temperatura >40)
    {
        printf("introduza a temperatura:");
        scanf("%d", &temperatura);
    }

    return 0;
}