#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;
 
    key = 123;
 
    if ((shmid = shmget(key, 27, IPC_CREAT | 0666)) < 0){
      perror("shmget");
	  exit(1);
	}
 
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1){
      perror("shmat");
	  exit(1);
 	}

    s = shm;
 
    for (c = 'a'; c <= 'z'; c++){
        *s++ = c;
	}
	while(*shm != '#'){
		sleep(1);
	}

    exit(0);
}
