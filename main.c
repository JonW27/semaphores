#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>



int main(int argc, char **argv){
  int f;
  if(argc > 1){
    if(strcmp(argv[1], "-c") == 0){
      if(semget(24601, 1, IPC_CREAT | IPC_EXCL) == -1){
        printf("Semaphore already exists.\n");
      }
      else{
        f = semget(24601, 1, IPC_CREAT); // I looked at ftok, but I don't see how its better
        semctl(f, 0, SETVAL, argv[2]);
      }
    }
    else if(strcmp(argv[1], "-v") == 0){
      printf("Semaphore value is %d\n",semctl(f, 0, GETVAL));
    }
    // the following statement doesn't always work
    else if(strcmp(argv[1], "-r") == 0){
      semctl(f, 0, IPC_RMID);
    }
  }
  return 0;
}
