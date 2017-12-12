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
		fd = open(fifo, O_RDWR);
		
		while(i < 10){ 
  
    read(fd, buffer, 100);
    printf("%s\n", buffer);
		i++;
		}

		close(fd);   

    return 0;
}
