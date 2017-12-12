#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd, i=0;
    char string[100], buffer[100];
    char *fifo = "myfifo";	

    mkfifo(fifo, 0600);
    fd = open(fifo, O_WRONLY);		

    while(i < 10){   
    fgets(string, 100, stdin);
    write(fd, string, sizeof(string));
    i++;
    }

    close(fd);
    unlink(fifo);

    return 0;
}
