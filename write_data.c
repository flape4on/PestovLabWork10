#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
	int data_processed;
	int file_pipes[2];
	const char message[] = "The Laboratory Work of Pestov\n";
	char buffer[BUFSIZ + 1];
	pid_t pid;
	char* program_args[] = {"read_data", buffer, NULL};
	
	memset(buffer, '\0', sizeof(buffer));
	if (pipe(file_pipes)==0)
	{
		pid = fork();
		if (pid == 0)
		{
			sprintf(buffer, "%d", file_pipes[0]);
			execv("./read_data", program_args);
		}
		else
		{
			data_processed = write(file_pipes[1], message, strlen(message));
			printf("I'm parent process of Pestov with pid=%d.\n", getpid());
			printf("I wrote %d bytes of message!\n", data_processed);
			sleep(1);
		}
	}
	return EXIT_SUCCESS;
}
