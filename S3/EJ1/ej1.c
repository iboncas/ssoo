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
		char str[50];
		sprintf(str, "%d", pidHijo);
		execlp("/home/debian/ssoo/S3/EJ1/hijo", "hijo", str, NULL);

		/* printf("[HIJO] El valor de pidHijo es %d y mi pid es %d\n", pidHijo, getpid());
		printf("[HIJO] Espero 5 segundos.\n");
		sleep(5);
		printf("[HIJO] Termino.\n");

		exit(0);*/
	}

	return 0;
}
