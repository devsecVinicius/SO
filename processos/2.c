# include <stdio.h>
# include <unistd.h>

int main(){
	
	fork();
	fork();
	fork();
	
	printf("\nOlá, eu sou o processo = %i", getpid());

	return 0;
}
