# include <stdio.h> // input e output
# include <unistd.h> // serve para fazer o fork e criar o processo filho e tambem usar a funcao getpid()

int main(){
	
	int pid;
	
	printf("Eu sou o processo original antes do FORK, meu PID é %i\n\n", getpid());
	
	pid = fork();
	
	if(pid < 0){
		printf("Criação do processo filho falhou, eu sou o PAI, meu pid = %i\n", getpid());
	}else{
		if(pid == 0){
			printf("Eu sou o processo FILHO, meu pid = %i, meu ppid = %i\n", getpid(), getppid());
		}else{
			printf("Eu sou o PAI, meu pid = %i, meu ppid = %i, pid do meu filho = %i\n", getpid(), getppid(), pid);
		}
	}
	
	
	return 0;
}

// fork cria um novo processo, chamado de processo filho
// é executado ao mesmo tempo que o processo pai
// quando um processo filho é criado ele vai continuar a execução do codigo depois do fork que o criou
// PID = ID do processo
//
// comando fork retorna um int e nao precisa de parametros
//
// valor negativo = criação do processo filho falhou
// zero = processo filho
// valor positivo = processo original, retorna o pid do filho
