#include "types.h"
#include "stat.h"
#include "user.h"

void delay(int count)
{
    int i;
    int j, k;
    int *data;

    data = (int *)malloc(sizeof(int) * 1024 * 10);
    if (data <= 0)
        printf(1, "Error on memory allocation \n");

    for (i = 0; i < count; i++)
    {
        for (k = 0; k < 5700; k++)
            for (j = 0; j < 1024 * 10; j++){
                data[j]++;
                printf(1,"");
            }
    }
}
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf(1, "Please provide number of childrens: testcase_C <number_of_childrens>\n");
        exit();
    }
    int N = atoi(argv[1]);
    int pids[N];
    int rets[N];
    int bt[N];

    int seed = 3, m = 37;
    for(int i=0;i<N;i++){
        seed = (seed*((N/2)*2+1)+19)%m+2;
        bt[i] = seed;
    }

    setbursttime(1000);

    for (int i = 0; i < N; i++)
    {
        // * Set process priority
        // * Change priority of children in different order
        //   and verify your implementations !!!
        int priority = bt[i] ;

        int ret = fork();
        if (ret == 0)
        {
            setbursttime(priority);
            delay(20);
            exit();
        }
        else if (ret > 0)
        {
            bt[i] = priority;
            pids[i] = ret;
        }
        else
        {
            printf(1, "fork error \n");
            exit();
        }
    }

    for (int i = 0; i < N; i++)
    {
        rets[i] = wait();
        rets[i] = rets[i];
    }

    printf(1, "\nAll children completed\n");
    for (int i = 0; i < N; i++)
        printf(1, "Child %d.    pid %d, BT: %d\n", i, pids[i],bt[i]);

    // printf(1, "\nExit order \n");
    // for (int i = 0; i < N; i++)
    //     printf(1, "pid %d\n", rets[i]);

    exit();
}
