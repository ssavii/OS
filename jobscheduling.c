#include <stdio.h>

int main() {
int i,j,np,at[50],et[50],wt[50],tat[50],k=0,p[50],t; float avg_wt,avg_tat;
int choice; do{
printf("\nMENU\n1.FCFS\n2.SHORTEST JOB FIRST\n3.EXIT\n"); printf("Enter your choice\n");
scanf("%d",&choice); switch(choice){
case 1:
printf("Enter the number of processes\n"); scanf("%d",&np);
for(i=0;i<np;i++){
printf("Enter the arrival time\n"); scanf("%d",&at[i]);
printf("Enter the execution time\n"); scanf("%d",&et[i]);
}

wt[0]=0; tat[0]=et[0]; avg_wt=wt[0]; avg_tat=tat[0]; k=et[0];

for(i=1;i<np;i++){ wt[i]=k-at[i]; k=k+et[i]; tat[i]=et[i]+wt[i]; avg_wt+=wt[i]; avg_tat+=tat[i];
}

avg_wt=avg_wt/np; avg_tat=avg_tat/np;

printf("\nProcess\tArrival time\t Execution time\t Waiting time\t Turnaround time\n"); for(int i=0;i<np;i++){
printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,at[i],et[i],wt[i],tat[i]); }

printf("The average waiting time : %0.1f\n",avg_wt); printf("The average turn around time : %0.1f",avg_tat); break;

case 2:
printf("Enter the number of processes\n"); scanf("%d",&np);
for(i=0;i<np;i++){
printf("Enter the execution time\n"); scanf("%d",&et[i]);
p[i]=i+1; }
for(int i=0;i<np;i++){ for(int j=0;j<np-1;j++){
if(et[j]>et[j+1]){

t=et[j]; et[j]=et[j+1]; et[j+1]=t;
t=p[j]; p[j]=p[j+1]; p[j+1]=t;

} }
} wt[0]=0;
tat[0]=et[0]; avg_wt=wt[0]; avg_tat=tat[0]; k=et[0];
for(int i=1;i<np;i++){ wt[i]=k;
k+=et[i]; }
for(i=1;i<np;i++){ tat[i]=et[i]+wt[i]; avg_wt+=wt[i]; avg_tat+=tat[i];
}

avg_wt=avg_wt/np; avg_tat=avg_tat/np;

printf("\nProcess\t Execution time\t Waiting time\t Turnaround time\n"); for(int i=0;i<np;i++){
printf("P%d\t\t%d\t\t%d\t\t%d\n",p[i],et[i],wt[i],tat[i]); }

printf("The average waiting time : %0.1f\n",avg_wt); printf("The average turn around time : %0.1f",avg_tat); break;

case 3: return 0; }
}while(choice!=3);

//waiting time = turnaround time - burst time
//wating time = burst time of previous processes - arrival time of current process //Turnaround time = Burst time + Waiting time


}
