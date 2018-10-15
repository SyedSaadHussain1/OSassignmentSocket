#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>


int main()
{
    int sum=0;
    int reader[10];

    int pipe1[2];
    int pipe2[2];
    int pipe3[2];
    int pipe4[2];
    int pipe5[2];
    int pipe6[2];
    int pipe7[2];
    int pipe8[2];
    int pipe9[2];
    int pipe10[2];

    int a[1000];
    {
        for (int i=0;i<1000;i++)
            a[i]=1;
    }
    int cpid=fork();
    if (cpid==0)
    {

        for (int i=0;i<100;i++)
            sum=sum+a[i];
        pipe(pipe1);
        write(pipe1[1],&sum,sizeof(int));
        close(pipe1[1]);
        exit(0);
    }
    else
        int cpid2=fork();

    if (cpid2==0)
    {

        for (int i=100;i<200;i++)
             sum=sum+a[i];
        pipe(pipe2);
        write(pipe2[1],&sum,sizeof(int));
        close(pipe2[1]);
        exit(0);
    }
    else
        int cpid3=fork();

    if (cpid3==0)
        {

        for (int i=200;i<300;i++)
            sum=sum+a[i];
        pipe(pipe3);
        write(pipe3[1],&sum,sizeof(int));
        close(pipe3[1]);
        exit(0);
        }
    else
        int cpid4=fork();

    if (cpid4==0)
    {

        for (int i=300;i<400;i++)
            sum=sum+a[i];
        pipe(pipe4);
        write(pipe4[1],&sum,sizeof(int));
        close(pipe4[1]);
        exit(0);
    }
   else
        int cpid5=fork();


    if (cpid5==0)
    {

        for (int i=400;i<500;i++)
            sum=sum+a[i];
        pipe(pipe5);
        write(pipe5[1],&sum,sizeof(int));
        close(pipe5[1]);
        exit(0);
    }
    else
        int cpid6=fork();

    if (cpid6==0)
        {

        for (int i=500;i<600;i++)
            sum=sum+a[i];
        pipe(pipe6);
        write(pipe6[1],&sum,sizeof(int));
        close(pipe6[1]);
        exit(0);
    }
    else
        int cpid7=fork();

    if (cpid7==0)
        {

        for (int i=600;i<700;i++)
            sum=sum+a[i];
        pipe(pipe7);
        write(pipe7[1],&sum,sizeof(int));
        close(pipe7[1]);
        exit(0);
    }
    else
        int cpid8=fork();
    if (cpid8==0)
    {
        for (int i=700;i<800;i++)
            sum=sum+a[i];
        pipe(pipe8);
        write(pipe8[1],&sum,sizeof(int));
        close(pipe8[1]);
        exit(0);
    }
    else
        int cpid9=fork();

    if (cpid9==0)
        {
        for (int i=800;i<900;i++)
            sum=sum+a[i];
        pipe(pipe9);
        write(pipe9[1],&sum,sizeof(int));
        close(pipe9[1]);
        exit(0);
    }
    else
        int cpid10=fork();
    if (cpid10==0)
        {
        for (int i=900;i<1000;i++)
            sum=sum+a[i];
        pipe(pipe10);
        write(pipe10[1],&sum,sizeof(int));
        close(pipe10[1]);
        exit(0);
    }

    for (int i=0;i<10;i++)
        wait(&cpid);

    read(pipe1[0],reader[0],sizeof(int));
    read(pipe2[0],reader[1],sizeof(int));
    read(pipe3[0],reader[2],sizeof(int));
    read(pipe4[0],reader[3],sizeof(int));
    read(pipe5[0],reader[4],sizeof(int));
    read(pipe6[0],reader[5],sizeof(int));
    read(pipe7[0],reader[6],sizeof(int));
    read(pipe8[0],reader[7],sizeof(int));
    read(pipe9[0],reader[8],sizeof(int));
    read(pipe1[0],reader[9],sizeof(int));


    int grandsum=0;
    for (int i=0;i<10;i++)
        grandsum=grandsum+reader[i];

    printf("THE SUM IS=%d",grandsum);
}
