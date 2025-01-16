#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
FILE *fp;
pid_t pid;

pid = fork();
if(pid == 0)
{
	fp = fopen("program4results.txt", "a");
	fprintf(fp, "Child proces ID: %d\n", getpid());
	fclose(fp);
}
else
{
	wait(NULL);
	fp = fopen("program4results.txt", "a");
	fprintf(fp, "Parent process ID: %d\n", getpid());
	fclose(fp);
}

return 0;
}
