#include<stdio.h>
typedef struct process
{
            int id,at,bt,st,ft,pr;
            float wt,tat;
}process;
process p[10],p1[10],temp;
void main()
{

            int i,n,ts,ch,j,x;
            printf("\nEnter the no. of process: ");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                        printf("\nEnter the arrival time for process P%d: ",i);
                        scanf("%d",&p[i].at);
                        p[i].id=i;
            }
            for(i=1;i<=n;i++)
            {
                        printf("\nEnter the burst time for process P%d: ",i);
                        scanf("%d",&p[i].bt);
            }
            printf("\nInputs given by the user are:\n");
printf("==============================================================");
            printf("\nProcess\tAT\tBT");
            for(i=1;i<=n;i++)
                        printf("\nP%d\t%d\t%d",p[i].id,p[i].at,p[i].bt);
printf("\n============================================================");
            p[1].st=p[1].at;
            for(i=2;i<=n;i++)
                        p[i].st=p[i-1].st+p[i-1].bt;
            p[1].ft=p[1].bt;
            for(i=2;i<=n;i++)
                        p[i].ft=p[i-1].ft+p[i].bt;
            printf("\nGant Chart is as follows:\n\n");
            printf("%d->P%d->%d",p[1].st,p[1].id,p[1].ft);
            for(i=2;i<=n;i++)
                        printf("->P%d->%d",p[i].id,p[i].ft);
            printf("\n");
            for(i=1;i<=n;i++)
            {
                        p[i].tat=p[i].ft-p[i].at;
                        p[i].wt=p[i].tat-p[i].bt;
                        p[0].tat=p[0].tat+p[i].tat;
                        p[0].wt=p[0].wt+p[i].wt;
            }
            p[0].tat=p[0].tat/n;
            p[0].wt=p[0].wt/n;
            printf("\n\n-------------------TABLE----------------------------------\n");
            printf("\nProcess\tAT\tBT\tFT\tTAT\t\tWT");
            for(i=1;i<=n;i++)
                        printf("\nP%d\t%d\t%d\t%d\t%f\t%f",p[i].id,p[i].at,p[i].bt,p[i].ft,p[i].tat,p[i].wt);
            printf("\n\n-----------------------------------------------------------");
            printf("\nAverage Turn Around Time: %f",p[0].tat);
            printf("\nAverage Waiting Time: %f",p[0].wt);
}