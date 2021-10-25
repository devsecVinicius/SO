# include <sched.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <errno.h>
# include <pthread.h>

int main(){

    int id;
    printf("Eu sou o processo original id = %d\n", getpid());
    
    id = fork();
    if(id<0){
		printf("nao foi possivel criar um novo processo\n");
		return -1;
	}else{
		if(id==0){
			printf("Eu sou o processo filho, meu id é %d\n",getpid());
			sleep(20); 
			execl("/usr/bin/firefox","firefox", NULL); // usando o exec para sair ao inves de apenas clonar o processo pai ele criar outro processo
			printf("Processo filho encerrando!\n");
		}else{
			printf("Eu sou o processo pai, meu id é %d o id do meu filho é %d\n", getpid(), id);
			int status;
			wait(&status);// serve para esperar o sinal de morte do processo filho, para dessa forma ele nao virar um zumbi
			if(WIFEXITED(status)){
				printf("Finalizou normalmente: %d\n", WEXITSTATUS(status));
			}else if(WIFSIGNALED(status)){
				printf("Cancelado por sinal: %d\n", WTERMSIG(status));
			}
			sleep(60);
			printf("Processo pai encerrando!\n");
		}
	}

    return 0;
}
