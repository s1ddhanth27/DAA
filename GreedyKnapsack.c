#include<stdio.h>
void printArray(float x[],int w[],int n){
	for(int i =0;i<n;i++){
		printf("%f ",x[i]);
	}
	printf("\n");
	for(int i =0;i<n;i++){
		if(x[i]>0){
			printf("%d ",w[i]);
		}
	}
	printf("\n");
}
void greedyKnapsack(int p[],int w[],int m,float x[],int n){
    int i;
    float temp;
    float ratio[50];
    for(i=0;i<n;i++){
    	ratio[i] = p[i]/w[i];
	}
	for(i=0;i<n;i++){
		for(int j =i+1;j<n;j++){
			if(ratio[j]>ratio[i]){
				temp = ratio[j];
		        ratio[j] = ratio[i];
		        ratio[i] = temp;
		
		        temp = w[j];
		        w[j] = w[i];
		        w[i] = temp;
		
		        temp = p[j];
		        p[j] = p[i];
		        p[i] = temp;
			}
		}
	}
    for(i=0;i<n;i++){
        x[i] = 0;
    }
    float CCofKS = m;
    float CP = 0;
    for(i = 0;i < n;i++){
        if(w[i] > CCofKS){
            break;
        }
        else{
        	x[i] = 1;
        	CCofKS = CCofKS - w[i];
        	CP = CP + p[i];
		}
    }
    if (i < n){
        x[i] = CCofKS/w[i];
        CP = CP + p[i]*x[i];
    }
    printf("Max Profit :%f\n",CP);
    printf("The solution vector X :");
    printArray(x,w,n);
}
int main(){
    int p[] = {6,2,1,8,3,5};
    float x[10];
    int w[] = {6,10,9,5,1,3};
    int m = 16;
    int n = 6; 
    greedyKnapsack(p,w,m,x,n);   
}


