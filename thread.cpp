/*
An example program using threads in C++
This example was taken from a book: 
Modern Operating Systems 4th Edition (Figure 2-15), 
Andrew S. Tanenbaum & Herbert Bos, Pearson, 2015

This code was written and tested using https://www.onlinegdb.com 
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMBER_OF_THREADS 10
void *print_hello_world (void *tid) 
{
/* This function prints the thread's identifier and then exits. */ 
    printf ("Hello World. Greetings from thread %p\n", tid);
    pthread_exit (NULL);
} 
int main (int argc, char *argv[]) 
{
  
/* The main program creates 10 threads and then exits. */ 
    pthread_t threads[NUMBER_OF_THREADS];
    int status, i;

    for (i = 0; i < NUMBER_OF_THREADS; i++)
    {
        printf ("Main here. Creating thread %d\n", i);
        status = pthread_create (&threads[i], NULL, print_hello_world, (void *) i);
        if (status != 0)
	    {
            printf ("Oops. pthread create returned error code %d\n", status);
            exit (-1);
        }
    }
    exit (NULL);
}
