#include <stdio.h>

// Função que retorna o maior dos dois números
int maior_do_que(int numero1, int numero2)
{
    if (numero1 > numero2)
    {
        return numero1;
    }
    else
    {
        return numero2;
    }
}

int main()
{
    int numero1 = 0;
    int numero2 = 0;

    printf("Introduza o primeiro número:\n");
    scanf("%d", &numero1);

    printf("Introduza o segundo número:\n");
    scanf("%d", &numero2);

    // Chama a função para obter o maior número e imprime o resultado
    int maior = maior_do_que(numero1, numero2);
    printf("O maior número é: %d\n", maior);

    return 0;
}


