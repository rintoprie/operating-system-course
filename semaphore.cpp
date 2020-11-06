/*
Example of Semaphore in C++
Taken from: https://www.geeksforgeeks.org/use-posix-semaphores-c/

Explanation:
The POSIX system in Linux presents its own built-in semaphore library. To use it, we have to :
1. Include semaphore.h
2. Compile the code by linking with -lpthread -lrt (gcc) or with -pthread (g++)
To lock a semaphore or wait we can use the sem_wait function.
To release or signal a semaphore, we use the sem_post function.
A semaphore is initialised by using sem_init(for processes or threads) or sem_open (for IPC).

When it runs:
3 threads are being created, one 2 seconds after the first one.
But the first thread will sleep for 4 seconds after acquiring the lock.
Thus the second thread will not enter immediately after it is called, it will enter 4 – 2 = 2 secs after it is called.

See the differences when sem_wait() and sem_post() is commented
*/
#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
#include <ctime>
#include <iostream>

using namespace std;

sem_t mutex; 

void* thread(void* arg)
{
    time_t result;
    long id=(long)arg;

    sem_wait(&mutex);                           // Lock a semaphore or wait 
    result = time(nullptr);

    cout << "\nEntered... " << id << "\n";

    //critical section
    sleep(4);

    result = time(nullptr);
    cout << "\nExiting... " << id << "\n";
    sem_post(&mutex);                           // Release or signal a semaphore
} 

int main() 
{
    sem_init(&mutex, 0, 1);                     // Initialize semaphore
    pthread_t t1,t2, t3;
    pthread_create(&t1,NULL,thread,(void*)0);   // Create thread 0
    sleep(2);
    pthread_create(&t2,NULL,thread,(void*)1);   // Create thread 1
    sleep(2);
    pthread_create(&t3,NULL,thread,(void*)2);   // Create thread 2
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    sem_destroy(&mutex);

    return 0; 
} 
