/*
令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
提交代码
*/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void print(int *ele,int first,int last){
	int num = last - first +1;
	int i;
	for(i = 0; i != num; ++i){
	if(i%10)
		printf(" ");
	printf("%d",*(ele+i+first));
	if(i%10==9)
		printf("\n");
	}
}
int Isprime(int a){
	int i;
	if(a==2|a==3)
		return 1;
	for(i = 2; i < sqrt(a)+1; ++i)
		if(a%i==0)
			return 0;
	return 1;
} 
int main(){
	int M,N;
	int i,count;
	count = 0;
	i = 2;
	scanf("%d%d",&M,&N);
	int *prime = new int[N];	
	while(count!=(N-M+1)){
		if(Isprime(i))
			count++;
		if(count >= M)
			prime[count]=i;
		++i;
	}
	print(prime,M,N);
			
}
