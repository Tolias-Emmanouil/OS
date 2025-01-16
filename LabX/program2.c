#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main()
{
int p[2];
pid_t pid;
char msg[] = "Hello world from parent";
char buffer[100];
pipe(p);

pid = fork();

if (pid == 0){
	close(p[1]);
	read(p[0], buffer, sizeof(buffer));
	printf( "Received from parent: %s\n", buffer);
	close(p[0]);
}
else {
	close(p[0]);
	write(p[1], msg, strlen(msg) + 1);
	close(p[1]);
	wait(NULL);
}

return 0;
}
