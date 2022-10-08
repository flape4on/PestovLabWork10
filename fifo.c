#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#define NAMEDPIPE_NAME "Pestov"
#define BUFSIZE 30

int main (int argc, char ** argv)
{
        int fd, len;
        char buf[BUFSIZE];

        if ( mkfifo(NAMEDPIPE_NAME, 0777) )
        {
                fprintf(stderr, "Error in mkfifo!");
                return 1;
        }
        printf("%s is created\n", NAMEDPIPE_NAME);

        if ( (fd = open(NAMEDPIPE_NAME, O_RDONLY)) <= 0 )
        {
                fprintf(stderr, "Error in open!");
                return 1;
        }
        printf("%s is opened\n", NAMEDPIPE_NAME);
        do
        {
                memset(buf, '\0', BUFSIZE);
                if ( (len = read(fd, buf, BUFSIZE-1)) <= 0 )
                {
                        printf("END! ");
                        close(fd);
                        remove(NAMEDPIPE_NAME);
                        return 0;
                }
                printf("Incomming message (%d): %s\n", len, buf);
        }
        while ( 1 );
}
