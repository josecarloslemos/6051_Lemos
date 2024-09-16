#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PALAVRA 100 // Tamanho máximo da palavra
#define MAX_ERROS 6     // Número máximo de erros permitidos

// Função para limpar a tela
void limpar_tela() {
    #ifdef _WIN32
        system("cls");  // Limpa a tela no Windows
    #else
        system("clear"); // Limpa a tela em sistemas Unix
    #endif
}

// Função para desenhar a forca
void desenhar_forca(int erros) {
    printf("  ___\n");
    printf("  |     |\n");
    printf("  |     %c\n", (erros > 0) ? 'O' : ' '); // Cabeça
    printf("  |    %c%c%c\n", (erros > 2) ? '/' : ' ', (erros > 1) ? '|' : ' ', (erros > 3) ? '\\' : ' '); // Braços
    printf("  |    %c %c\n", (erros > 4) ? '/' : ' ', (erros > 5) ? '\\' : ' '); // Pernas
    printf("  |\n");
    printf("_|_\n\n");
}

// Função para obter a palavra secreta
void obter_palavra_secreta(char *palavra) {
    printf("Jogador 1, digite a palavra secreta: ");
    scanf("%s", palavra);
}

// Função para adivinhar a letra
int adivinhar_letra(char letra, const char *palavra_secreta, char *palavra_adivinhada) {
    int acertou = 0;
    for (int i = 0; i < strlen(palavra_secreta); i++) {
        if (palavra_secreta[i] == letra) {
            palavra_adivinhada[i] = letra; // Atualiza a palavra adivinhada
            acertou = 1;
        }
    }
    return acertou;
}

// Função principal do jogo
void jogar() {
    char palavra_secreta[MAX_PALAVRA];
    char palavra_adivinhada[MAX_PALAVRA];
    char letras_erradas[MAX_ERROS + 1] = {0}; // +1 para o terminador nulo
    char letra;
    int erros = 0;

    obter_palavra_secreta(palavra_secreta); // Lê a palavra secreta

    // Inicializa a palavra adivinhada com underscores
    memset(palavra_adivinhada, '_', strlen(palavra_secreta));
    palavra_adivinhada[strlen(palavra_secreta)] = '\0'; // Termina a string

    while (erros < MAX_ERROS && strcmp(palavra_adivinhada, palavra_secreta) != 0) {
        limpar_tela();
        desenhar_forca(erros);
        printf("Palavra: %s\n", palavra_adivinhada);
        printf("Letras erradas: %s\n", letras_erradas);

        printf("Jogador 2, digite uma letra: ");
        scanf(" %c", &letra); // Lê uma letra

        // Verifica se a letra já foi adivinhada
        if (strchr(letras_erradas, letra) || strchr(palavra_adivinhada, letra)) {
            printf("Você ja adivinhou essa letra. Tente outra.\n");
            continue;
        }

        // Tenta adivinhar a letra
        if (!adivinhar_letra(letra, palavra_secreta, palavra_adivinhada)) {
            letras_erradas[erros] = letra; // Adiciona a letra errada
            letras_erradas[erros + 1] = '\0'; // Adiciona terminador nulo
            erros++;
        }
    }

    // Finaliza o jogo
    limpar_tela();
    desenhar_forca(erros);
    if (strcmp(palavra_adivinhada, palavra_secreta) == 0) {
        printf("Parabens! Adivinhou a palavra: %s\n", palavra_secreta);
    } else {
        printf("Perdeu! A palavra era: %s\n", palavra_secreta);
    }
}

// Função principal
int main() {
    char resposta;
    do {
        jogar(); // Inicia o jogo
        printf("Jogar novamente? (S/N): ");
        scanf(" %c", &resposta);
    } while (resposta == 'S' || resposta == 's');

    printf("Obrigado por jogar!\n");
    return 0;
}