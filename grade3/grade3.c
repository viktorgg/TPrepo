#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;
		char string[100], buffer[100];
    char *fifo = "/tmp/myfifo";	

    mkfifo(fifo, 0600);
		
		for(int i=0; i<5; i++){    
		fgets(string, 100, stdin);
		fd = open(fifo, O_RDWR);
    write(fd, string, sizeof(string));
    read(fd, buffer, 100);
    printf("%s\n", buffer);
		close(fd);
		}

    close(fd);

    unlink(fifo);

    return 0;
}
