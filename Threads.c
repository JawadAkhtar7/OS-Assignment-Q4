#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int array[1000];
int chunk_size=100;
// Add Function (Thread by Thread)
void * add (void *arg)
{
    int start=(int)arg;
    int end=start+chunk_size;
    int sum=0;
    for(int i=0;i<end;i++)
    {
        sum=sum+array[i];
    }
    return((void*)sum);
}

int main()
{
    // Inititalaize Array
    for(int i=0;i<1000;i++)
    {
        array[i]=i;
    }
    pthread_t thread_t[10];
    int status_t[10];
    // Create Threads
    for(int i=0;i<10;i++)
    {
        pthread_create (&thread_t[i],NULL,add,(void*)(i*chunk_size));
    }
    // Join threads
    for(int i=0;i<10;i++)
    {
        pthread_join (thread_t[i],(void**) & status_t[i]);    
    }
    // Store Returned Thread's Sum
    int sum=0;
    for(int i=0;i<10;i++)
    {
        sum=sum+status_t[i];
    }
    //Print sum
    printf("Sum is: %d",sum);
    return 0;
}

