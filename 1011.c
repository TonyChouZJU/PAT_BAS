#include<stdlib.h>
#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int a[n],b[n];
	long c[n];
	for(int i = 0; i != n; ++i)
		scanf("%d%d%d",a+i,b+i,c+i);
	for(int i = 0; i != n; ++i){
		printf("Case #%d",i);
		if(a+b>c)
			printf("true");
		else
			printf("false");
	}

}
