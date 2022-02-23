#include <stdio.h>

int main() {
int n_frames,i,j,k,pages[30],frames[10],page_hit,page_fault,n_pages,avail; printf("Enter the number of pages\n");
scanf("%d",&n_pages);

printf("Enter pages in sequence\n"); for(i=0;i<n_pages;i++){
scanf("%d",&pages[i]); }
printf("Enter the number of frames\n"); scanf("%d",&n_frames); for(i=0;i<n_frames;i++){
frames[i]=-1; }
printf("reference string\tpage frames\n\n"); page_hit=0;
j=0; for(i=0;i<n_pages;i++){

printf("\t%d\t",pages[i]); avail=0; for(k=0;k<n_frames;k++){
if(frames[k]==pages[i]){ page_hit++; printf("\t\t***page hit***"); avail=1;
} }
if(avail==0){ frames[j]=pages[i]; page_fault++; j=(j+1)%n_frames; for(k=0;k<n_frames;k++){ printf("\t%d",frames[k]);
} }

printf("\n"); }
printf("\nTotal page hits = %d",page_hit); printf("\nTotal page faults = %d",page_fault); float hr;
hr=(float)page_hit/page_fault; printf("\nHit ratio = %f",hr);


return 0; }
