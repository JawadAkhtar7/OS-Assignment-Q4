#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

 int main()
{
    int s=0;
    int k;
    
    // 2D Array to Store The SUM
    int array[10][2];
    // for loop for 10 Processes
    for(int i=0;i<10;i++)
    {
        // Pipe the Values Stored in the ROW of the Array
        pipe(array[i]);
        // 10 Variables for 10 Processes
    int cpid1,cpid2,cpid3,cpid4,cpid5,cpid6,cpid7,cpid8,cpid9,cpid10;
        // Child Process 1 
        cpid1=fork();
        if(cpid1==0)
        {
            int sum1;
            for(int i=1;i<=100;i++)
            {
                sum1=sum1+i;
            }
            write(array[0][1],&sum1,sizeof(sum1));
            close(array[0][1]);
        }
        else
        {
            wait(NULL);
           read(array[0][0],&k,sizeof(k));
            s=s+k;
            close(array[0][0]);
        
        // For Child Process 2
        cpid2=fork();
        if(cpid2==0)
        {
            int sum2;
            for(int i=100;i<=200;i++)
            {
                sum2=sum2+i;
            }
            write(array[1][1],&sum2,sizeof(sum2));
            close(array[1][1]);
        }
        else
        {
            wait(NULL);
            read(array[1][0],&k,sizeof(k));
            s=s+k;
            close(array[1][0]);
        
        // For Child Process 3
        cpid3=fork();
        if(cpid3==0)
        {
            int sum3;
            for(int i=200;i<=300;i++)
            {
                sum3=sum3+i;
            }
            write(array[2][1],&sum3,sizeof(sum3));
            close(array[2][1]);
        }
        else
        {
            wait(NULL);
            read(array[2][0],&k,sizeof(k));
            s=s+k;
            close(array[2][0]);
            
            // For Child Process 4
        cpid4=fork();
        if(cpid4==0)
        {
            int sum4;
            for(int i=300;i<=400;i++)
            {
                sum4=sum4+i;
            }
            write(array[3][1],&sum4,sizeof(sum4));
            close(array[3][1]);
        }
        else
        {
            wait(NULL);
            read(array[3][0],&k,sizeof(k));
            s=s+k;
            close(array[3][0]);
            
            // For Child Process 5
        cpid5=fork();
        if(cpid5==0)
        {
            int sum5;
            for(int i=400;i<=500;i++)
            {
                sum5=sum5+i;
            }
            write(array[4][1],&sum5,sizeof(sum5));
            close(array[4][1]);
        }
        else
        {
            wait(NULL);
            read(array[4][0],&k,sizeof(k));
            s=s+k;
            close(array[4][0]);
            
            // For Child Process 6
        cpid6=fork();
        if(cpid6==0)
        {
            int sum6;
            for(int i=500;i<=600;i++)
            {
                sum6=sum6+i;
            }
            write(array[5][1],&sum6,sizeof(sum6));
            close(array[5][1]);
        }
        else
        {
            wait(NULL);
            read(array[5][0],&k,sizeof(k));
            s=s+k;
            close(array[5][0]);
            
            // For Child Process 7
        cpid7=fork();
        if(cpid7==0)
        {
            int sum7;
            for(int i=600;i<=700;i++)
            {
                sum7=sum7+i;
            }
            write(array[6][1],&sum7,sizeof(sum7));
            close(array[6][1]);
        }
        else
        {
            wait(NULL);
            read(array[6][0],&k,sizeof(k));
            s=s+k;
            close(array[6][0]);
            
            // For Child Process 8`
        cpid8=fork();
        if(cpid8==0)
        {
            int sum8;
            for(int i=700;i<=800;i++)
            {
                sum8=sum8+i;
            }
            write(array[7][1],&sum8,sizeof(sum8));
            close(array[7][1]);
        }
        else
        {
            wait(NULL);
            read(array[7][0],&k,sizeof(k));
            s=s+k;
            close(array[7][0]);
            
            // For Child Process 9
        cpid9=fork();
        if(cpid9==0)
        {
            int sum9;
            for(int i=800;i<=900;i++)
            {
                sum9=sum9+i;
            }
            write(array[8][1],&sum9,sizeof(sum9));
            close(array[8][1]);
        }
        else
        {
            wait(NULL);
            read(array[8][0],&k,sizeof(k));
            s=s+k;
            close(array[8][0]);
            
            // For Child Process 10
        cpid10=fork();
        if(cpid10==0)
        {
            int sum10;
            for(int i=900;i<=1000;i++)
            {
                sum10=sum10+i;
            }
            write(array[9][1],&sum10,sizeof(sum10));
            close(array[9][1]);
        }
        else
        {
            wait(NULL);
            read(array[9][0],&k,sizeof(k));
            s=s+k;
            close(array[9][0]);
            printf("Sum of first 1000 Natural Numbers is: %d ",s);
        }
        }
        }
        }
        }
        }
        }
        }
        }
        }
    }
return 0;
}
