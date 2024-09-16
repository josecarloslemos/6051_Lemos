#include <stdio.h>

int main()
{

    float x = 0.0f;
    float y = 0.0f;
    
   // 1 intruduza o numero 1
    printf("intruduza o primeiro numero: ");
    scanf("%f",&x);

    //2.intruduza o numero 2

    printf("intruduza o primeira numero ");
    scanf("%f",&y);

    float soma = 0.0f;
    float produto = 0.0f;
    float diferenca = 0.0f;
    float quociente = 0.0f;

    // 3.correr funçôes

    soma = x + y;
    produto = x * y;
    diferenca = x - y;
    quociente = x / y;

    // 4. resultados

    printf("soma: %f\n", soma);
    printf("produto: %f\n",produto);
    printf("diferenca: %f\n", diferenca);
    printf("quociente: %f\n", quociente);

    return 0;
    }

