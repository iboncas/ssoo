#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char* argv){

	pid_t pidHijo = fork();

	if (pidHijo != 0) {
		/* Proceso padre*/
		printf("[PADRE] El valor de pidHijo es %d y mi pid es %d\n", pidHijo, getpid());
		printf("[PADRE] Quedo a la espera de que finalice mi hijo.\n");
		int estado = 55;
		pid_t pidFin = wait(&estado);
		printf("[PADRE] Mi hijo ha terminado en el estado %d.\n", estado);
		printf("[PADRE] Mi hijo ha terminado correctamente: %b.\n", WIFEXITED(estado));
		printf("[PADRE] Mi hijo ha terminado con el código %d.\n", WEXITSTATUS(estado));
		printf("[PADRE] Mi hijo con el PID %d ha terminado, por lo tanto, termino yo también.\n", pidFin);
	} else {
		/* Proceso hijo */

		printf("[HIJO] Entrando en bucle infinito.\n");
		while (1) {
			printf("[HIJO] Bucle infinito, PID: %d.\n", getpid());
			sleep(1);
		}
	}

	return 0;
}
