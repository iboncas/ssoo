#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char* argv){	
	int pidHijo = 55;

	if (argc >= 2) {
		pidHijo = argv[1];
	}

	printf("[HIJO] El valor de pidHijo es %d y mi pid es %d\n", pidHijo, getpid());
	printf("[HIJO] Espero 5 segundos.\n");
 	sleep(5);
	printf("[HIJO] Termino.\n");

	exit(0);

}
