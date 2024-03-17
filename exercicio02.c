#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>

#define FIBER_STACK 1024 * 64

int shared_data = 0; // Variável compartilhada

// Função que será executada pela thread filho
int threadFunction(void* argument) {
    printf("Thread filho está encerrando e modificando shared_data\n");
    shared_data = 10; // Modifica o valor da variável compartilhada
    return 0;
}

int main() {
    void* stack;
    pid_t pid;

    // Aloca a pilha para a thread filho
    stack = malloc(FIBER_STACK);
    if (stack == 0) {
        perror("malloc: não foi possível alocar a pilha");
        exit(1);
    }

    printf("Criando thread filho\n");

    // Chama a chamada de sistema clone para criar a thread filho
    pid = clone(&threadFunction, (char*)stack + FIBER_STACK,
                SIGCHLD | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, NULL);

    if (pid == -1) {
        perror("clone");
        exit(2);
    }

    // Aguarda a thread filho finalizar
    pid = waitpid(pid, 0, 0);
    if (pid == -1) {
        perror("waitpid");
        exit(3);
    }

    // Libera a pilha
    free(stack);

    // Imprime o valor modificado de shared_data
    printf("Thread filho retornou e pilha foi liberada. \nshared_data = %d\n", shared_data);

    return 0;
}

