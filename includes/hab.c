#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int min, int max){
	return rand()%(max-min+1)+min;
}

int main(){
	int n,i,j;
	scanf("%d", &n);
	int hab[n][n];
	srand(time(NULL));
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(i==j){
				hab[i][j]=-1;
			}
			else{
				hab[i][j]=random(0,1);
				hab[j][i]=!hab[i][j];
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(hab[i][j]==-1)
				printf("- ");
			else
				printf("%d ", hab[i][j]);
		}
		printf("\n");
	}
}