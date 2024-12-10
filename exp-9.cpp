#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 


#define SHM_SIZE 1024 // Size of the shared memory segmentint main() { key_t key = ftok("shmfile", 65); // Generate a unique key for the shared


// Create a new shared memory segment (or get the identifier of anexisting one)
if (shmid == -1) {
perror("shmget"); 
exit(EXIT_FAILURE);
 
}

// Attach the shared memory segment to the process address space char *shm_ptr = (char*)shmat(shmid, NULL, 0);if
(shm_ptr == (char*)(-1)) {
perror("shmat"); 
exit(EXIT_FAILURE);
}

// Write data to the shared memory strcpy(shm_ptr, "Hello, shared memory!");

// Detach the shared memory segment from the processif (shmdt(shm_ptr) == -1) {
perror("shmdt"); 
exit(EXIT_FAILURE);
}

printf("Data written to shared memory: %s\n", shm_ptr);

// Optional: Remove the shared memory segmentif (shmctl(shmid, IPC_RMID, NULL) == -1) {
perror("shmctl"); 
exit(EXIT_FAILURE);
}

return 0;
}
