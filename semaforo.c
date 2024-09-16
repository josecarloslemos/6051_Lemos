#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t parar = 0; // Variável para controlar a parada

// Função de tratamento de sinal
void tratar_sinal(int sinal) {
    parar = 1; // Define a variável para parar o semáforo
}

// Função para exibir o semáforo vermelho
void semaforo_vermelho() {
    printf("Semaforo VERMELHO\n");
    sleep(10);
}

// Função para exibir o semáforo verde
void semaforo_verde() {
    printf("Semaforo VERDE\n");
    sleep(5);
}

// Função para exibir o semáforo amarelo
void semaforo_amarelo() {
    printf("Semaforo AMARELO\n");
    sleep(3);
}

// Função principal do semáforo
void semaforo() {
    while (!parar) {
        semaforo_vermelho();
        semaforo_verde();
        semaforo_amarelo();
    }
}

int main() {
    // Configura o tratamento do sinal de interrupção (Ctrl+C)
    signal(SIGINT, tratar_sinal); 

    printf("Semaforo iniciado. Pressione Ctrl+C para parar.\n");
    semaforo();
    printf("Semaforo parado.\n");
    return 0;
}