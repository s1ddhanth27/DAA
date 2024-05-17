#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
	char JobId;
	int dead;
	int profit;
}Jobs;

int compare(const void* a,const void* b){
	Jobs *temp1 = (Jobs*)a;
	Jobs *temp2 = (Jobs*)b;
	return(temp2->profit-temp1->profit);
}

int min(int a,int b){
	return a < b ? a : b;
}
int main(){
	
	Jobs arr[]={
		{'a',3,20},
		{'b',1,15},
		{'c',2,25},
		{'d',3,60},
		{'e',2,45}
	};
	int n = sizeof(arr)/sizeof(arr[0]);
	char result[n];
	bool slot[n];
	qsort(arr,n,sizeof(Jobs),compare);
	
	for(int i = 0 ; i < n ; i++){
		slot[i] = false;
	}	
	
	for(int i = 0 ; i < n ; i++){
		for(int j = min(n,arr[i].dead);j>=0;j--){
			if(slot[j] == false){
				result[j] = i;
				slot[j] = true;
				break;
			}
		}
	}
	
	printf("The jobs in order for maximum profit are:");
	for(int i = 0 ; i < n ; i++){
		if(slot[i]){
			printf("%c ",arr[result[i]].JobId);
		}
	}	
	
}
