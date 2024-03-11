#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid;
    int value = 5;

    pipe(pipefd);
    pid = fork();

    if (pid == 0) { /* child process */
		printf("Entrei no filho!\n");
        close(pipefd[0]);
        value += 15;
        write(pipefd[1], &value, sizeof(value));
        close(pipefd[1]);
		printf("CHILD: value = %d\n", value); /* LINE A */
        return 0;
    } else if (pid > 0) { /* parent process */
        wait(NULL);
        close(pipefd[1]);
        read(pipefd[0], &value, sizeof(value));
        close(pipefd[0]);
        printf("PARENT: value = %d\n", value); /* LINE A */
        return 0;
    }
}
