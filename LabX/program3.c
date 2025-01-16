#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

pid_t pid;

pid = fork();

if (pid == 0){
	printf("Child process ID: %d. Waiting for signal\n", getpid());
	while(1){
		pause();
	}
}
else {
printf("Parent process ID: %d. Child PID: %d\n", getpid(), pid);
sleep(3);

kill(pid, SIGTERM);

wait(NULL);
printf("Child process terminated.\n");
}

return 0;

}
