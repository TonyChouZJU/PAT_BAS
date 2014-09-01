/*输入一个自然数n,n<10^100
*输出n的各位数字之和的每一位
*/

#include<stdlib.h>
#include<stdio.h>

static char *py[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
void print(int s){
	if(s/10==0)
		printf("%s",*(py+s%10));
	else{
		print(s/10);
		printf(" %s",*(py+s%10));
//		print(s/10);
	}
}
int main(){
	char c;
	int sum=0;
	while((c=getchar())!='\n')
		sum+=c-'0';
	print(sum);
}
