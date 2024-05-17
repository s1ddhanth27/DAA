#include <stdio.h>
void printArray(int a[],int n){
	for(int i = 0; i<n ; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

void sort(int start_time[],int end_time[],int id[],int n){
	int temp;
	for(int i=0;i<n;i++){
		for(int j =i+1;j<n;j++){
			if(end_time[j]<end_time[i]){
				temp = end_time[j];
		        end_time[j] = end_time[i];
		        end_time[i] = temp;
		
		        temp = start_time[j];
		        start_time[j] = start_time[i];
		        start_time[i] = temp;
		        
		        temp = id[j];
		       	id[j] = id[i];
		        id[i] = temp;
			}
		}
	}
}
void printMaxActivities(int s[], int f[],int id[], int n)
{
	int i, j;
	printf("Following activities are selected\n");
	i = 0;
	printf("%d ", id[i]);

	for (j = 1; j < n; j++) {
		if (s[j] >= f[i]) {
			printf("%d ", id[j]);
			i = j;
		}
	}
}

int main()
{
	int s[] = {3,0,5,1,8,5};
	int f[] = {4,6,7,2,9,9};
	int id[] ={1,2,3,4,5,6};
	
	int n = sizeof(s) / sizeof(s[0]);
	sort(s,f,id,n);
	printf("Sorted start times: ");
	printArray(s,n);
	printf("Sorted end times: ");
	printArray(f,n);
	
	printMaxActivities(s, f,id, n);
	return 0;
}