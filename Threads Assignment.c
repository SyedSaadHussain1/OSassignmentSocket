#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int data[1000];
int size=100;

void *Addition(void *number)
{
    int starting=(int)number;
    int end=starting+size;
    int sum=0;
    for (int i=starting;i<end;i++)
        sum=sum+data[i];
    return ((void*)sum);
}


int main()
{
    int sum=0;
    int status[10];
    pthread_t threads[10];
    for (int i=0;i<1000;i++)
        data[i]=i;

    for (int i=0;i<10;i++)
        pthread_create(&threads[i],NULL,Addition,(void*)(i*size));

    for (int i=0;i<10;i++)
         pthread_join(threads[i],(void**)&status[i]);

    for (int i=0;i<10;i++)
        sum=sum+status[i];

    printf("THE SUM IS=%d",sum);


    return 0;
}
