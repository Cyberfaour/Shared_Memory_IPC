# Shared_Memory_IPC

This repository contains two C programs, server.c and client.c, that demonstrate how to use shared memory using the System V IPC mechanism in Linux.

The server.c program creates a shared memory segment and waits for a message to be written to it by the client program. Once the message is received, the server prints it and waits for the client to override the shared memory segment with a new message.

The client.c program prompts the user to enter a message and writes it to the shared memory segment created by the server program. Once the message is written, the client waits for 10 seconds and then overrides the shared memory segment with a new message. The server program then prints the new message received from the client.

### To compile the programs, run the following commands:

  (`gcc server.c -o server
  gcc client.c -o client`)
  
### To run the programs, open two terminal windows and execute the following commands in each:

#### In terminal 1:

(`./server`)

#### In terminal 2:
(`./client`)


The programs should now be running and you can enter messages to be shared between the two programs.

Note that these programs are provided as examples only and should not be used in production environments without appropriate modifications and error handling.

For more information on shared memory and the System V IPC mechanism, refer to the Linux manual pages for shmget, shmat, shmdt, and shmctl.

  
