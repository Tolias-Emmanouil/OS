#include <stdio.h>
#include <unistd.h>

int main(void){
pid_t pid;


pid = fork();
if(pid > 0)
	printf("%d\n", pid);
pid = fork();
if(pid > 0)
	printf("%d\n", pid);
pid = fork();
if(pid > 0)
	printf("%d\n", pid);

return 0;
}
