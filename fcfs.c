#include <stdio.h>
#include <string.h>

struct job{
	char name[20];
	int at,bt,ct,tat,wt,st,tbt;
	
}
job[10];
int n,j,i;
float avg_tat = 0;
float avg_wt = 0;

void take_input(){
	printf("Enter The No. of Process:");
	scanf("%d",&n);
	for(i = 0;i<n;i++){
		printf("Enter The Arrival Time of the Process %d :",i);
		scanf("%d",&job[i].at);
	}
	for(i = 0;i<n;i++){
		printf("Enter The Bust Time of the Process %d :",i);
		scanf("%d",&job[i].bt);
		job[i].tbt = job[i].bt;
	}
	for(i = 0;i<n;i++){
		printf("Enter The Name of the Process %d :",i);
		scanf("%s",&job[i].name);
	}
	
}

void sort(){
	struct job temp;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(job[i].at > job[j].at){
				temp = job[i];
				job[i] = job[j];
				job[j] = temp;
			}
		}
	}
}

void process(){
	int time = job[0].at;
	for(j=0;j<n;j++){
		job[j].st = time;
		printf(" | %d %s ",job[j].st,job[j].name);
		time = time + job[j].tbt;
		job[j].ct = time;
		job[j].tat = time - job[j].at;
		job[j].wt = job[j].tat - job[j].tbt;
		printf("%d | ",time);
	}
}

void print_ouput(){
	printf("\n\n");
	printf("\n-----------------------------------------");
	printf("\n PName	At	BT	TAT	WT ");
	printf("\n-----------------------------------------");
	for(i=0;i<n;i++){
		printf("\n%s	%8d	%5d	%4d	%3d",job[i].name,job[i].at,job[i].bt,job[i].tat,job[i].wt);
		avg_tat = avg_tat + (float)(job[i].tat);
		avg_wt = (float)avg_wt + (float)(job[i].wt);
	}
	printf("\n-----------------------------------------");
	printf("\n THe Avg of the turn Around Time is %f:",avg_tat/n);
	printf("\n The Avg of the Waiting Time is %f:",avg_wt/n);
}

void main() {
	int i;
	take_input();
	sort();
	process();
	print_ouput();
	printf("\n\n");
	for(i=0;i<n;i++){
		job[i].tbt = job[i].bt = rand()%10+1;
		job[i].at = job[i].ct + 2;
	}
	process();
	print_ouput;
}
