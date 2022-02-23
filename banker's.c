#include<stdio.h>

void main()

{

int r,max_r[5],i,j,p,alc_mat[5][5],max_req_mat[5][5],need_mat[5][5],seq[5],n=0;

int av_r[5],alc_r[5]={0,0,0,0,0},sat_counter=0,sat_mat[5]={0,0,0,0,0},count=0,k;

printf("\nEnter the no. of R");

scanf("%d",&r);

printf("\nEnter the max resources for each");

for(i=0;i<r;i++)

scanf("%d",&max_r[i]);

printf("\nMax Resources\n");

for(i=0;i<r;i++)

printf("\t%d",max_r[i]);

printf("\nEnter the no. of processes.");

scanf("%d",&p);

printf("\nEnter the allocation matrix");

for(i=0;i<p;i++)

for(j=0;j<r;j++)

{

scanf("%d",&alc_mat[i][j]); //allocated matrix

alc_r[j]=alc_r[j]+alc_mat[i][j]; //allocated resources

}

for(i=0;i<p;i++)

{

printf("\n");

for(j=0;j<r;j++)

printf("\t%d",alc_mat[i][j]);

}

printf("\nAllocated resources\n");

for(j=0;j<r;j++)

{

printf("\t%d",alc_r[j]);

}

printf("\nEnter the max. req. matrix");

for(i=0;i<p;i++)

for(j=0;j<r;j++)

scanf("%d",&max_req_mat[i][j]); //max. req. matrix

for(i=0;i<p;i++)

{

printf("\n");

for(j=0;j<r;j++)

{

printf("\t%d",max_req_mat[i][j]);
}

}

for(i=0;i<p;i++)

for(j=0;j<r;j++)

need_mat[i][j]=max_req_mat[i][j]-alc_mat[i][j]; //need matrix

printf("\nNeed matrix");

for(i=0;i<p;i++)

{

printf("\n");

for(j=0;j<r;j++)

{

printf("\t%d",need_mat[i][j]);

}}

for(i=0;i<r;i++)

{ av_r[i]=max_r[i]-alc_r[i];

}

printf("\nAvailable resources\n");

for(i=0;i<r;i++)

printf("\t%d",av_r[i]);

while(sat_counter<p)

{

i=0;

while(i<p)

{

count=0;

if(sat_mat[i]==0)

{

for(j=0;j<r;j++)

if(need_mat[i][j]<=av_r[j])

count++;

//printf("\nCount : %d",count);

if(count==r)

{

printf("\nNeed of P%d is satisfied",i+1);

for(k=0;k<r;k++)

av_r[k]=av_r[k]+alc_mat[i][k];

printf("\nNewAvailable Resources");
for(j=0;j<r;j++)

printf("\t%d",av_r[j]);

sat_counter++;

//printf("\nSat Counter %d",sat_counter);

sat_mat[i]=1;

seq[n]=i+1;

n++;

} else

{

printf("\nNeed of P%d is not satisfied",i+1);

}

} i++;

}

}

printf("\nSequence of satisfied processes\n");

for(i=0;i<p;i++)

printf("\tP%d", seq[i]);

printf("\n");

}
