#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
void main(){
int id;
	key_t key; //create object key_t
	char *shm; //create a shared memory of type char
	key=4356; //assign a key for the shared memory to share with the other file
	id=shmget(key,32,0666);//shmget(key_t key, size_t size, int shmflg) 0666 for read and write for all users rw-rw-rw 110-110-110
	if(id<0)	//if the id is negative then exit with status 1
		exit(1);
		
	shm=shmat(id,NULL,0);//*shmat(int shmid, const void *shmaddr, int shmflg);
	
	printf("String shared %s\n",shm);
	
	printf("insert new string to share :\n");
	
	scanf("%s",shm);//take input
	sleep(10);//wait ten secs
	*shm='*';//send a signal to the server to overrride 
	shmdt(shm);//detach from the shared memory without completely removing the segment
	exit(0);
	
	
	
	}
