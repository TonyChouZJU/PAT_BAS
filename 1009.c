#include<stdlib.h>
#include<stdio.h>

int main(){
	char s[80][80];
	char c;
	int i = 0;
	do{
		scanf("%s",s+i);
		++i;
	}while((c=getchar())!='\n');
	for(int j = 0; j != i; ++j)
		if(j)
			printf(" %s",s+i-1-j);
		else
			printf("%s",s+i-1);
}
