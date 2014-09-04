#include<stdlib.h>
#include<stdio.h>

int main(){
	int a[1000],b[1000];
	int i=0;
	char c;
	do{
		scanf("%d%d",a+i,b+i);
		++i;
	}while((c=getchar())!='\n');
//	printf("%d",i);
	if(*b==0){
		printf("0");
		return 0;
	}
	for(int j = 0; j != i; ++j){
		if(*(b+j)){
			if(j)
			printf(" ");
			printf("%d %d",a[j]*b[j],b[j]-1);
		}
	}


}
