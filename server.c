#include<sys/shm.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

void main(){
	int id;
	key_t key;
	char *shm,*buffer;
	key=4356;
	id=shmget(key,32,IPC_CREAT |0666);
	if(id<0)
		exit(1);
	shm=shmat(id,NULL,0);
	buffer=shm;
	printf("Input a Message to share: ");
	scanf("%s",buffer);//buffer will be equal to the inserted data at the server
	
	sleep(10);//wait ten secs
	
	printf("Client overrided SHM with: %s",buffer);// recieve new shm data received from the client
	
	while(*shm!='*')// if shm is not overrriden yet wait ten secs just incase there is a delay in communication
		sleep(1);
	shmdt(shm);//detach shared memory
	shmctl(id,IPC_RMID,NULL);//remove the shared memory
	exit(0);
	
}
