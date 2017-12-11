#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd, l;
    char string[100], buffer[100];
    char *fifo = "myfifo";	

    mkfifo(fifo, 0600);
		
    while(l < 10){   
    fgets(string, 100, stdin);
    l = strlen(string);
    fd = open(fifo, O_RDWR);
    write(fd, string, sizeof(string));
    read(fd, buffer, 100);
    printf("%s\n", buffer);
    close(fd);	
    }

    unlink(fifo);

    return 0;
}
