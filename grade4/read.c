#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int shmid;
    key_t key;
    char *shm, *s;
 
    key = 123;
 
    if ((shmid = shmget(key, 27, 0666)) < 0){
       perror("shmget");
       exit(1);
 	}

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1){
       perror("shmat");
 	   exit(1);
	}

    for (s = shm; *s != '\0'; s++){
		putchar(*s);
    	putchar('\n');
    }
	
	*shm = '#';
	
	shmctl(shmid, IPC_RMID, NULL);	

    exit(0);
}
