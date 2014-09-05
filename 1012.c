/*
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。
输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

输出格式：

对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出“N”。

输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：
30 11 2 9.7 9
输入样例2：
8 1 2 4 5 6 7 9 16
输出样例2：
N 11 2 N 9
*/

#include<stdlib.h>
#include<stdio.h>
void print(long long AA,int blank){
	if(AA)
		printf("%lld",AA);
	else
		printf("N");
	if(blank)
		printf(" ");
}
int main(){
	long long A,yu;
	char c;
	int N;
	int flag=1;
	double count3=0;
	//交错求和的值可能为0 
	int count2 =0;
	long long A1,A2,A3,A5;
	double A4=0.0;
	A1=A2=A3=A5=0;
	scanf("%d",&N);
	do{
		scanf("%lld",&A);
		if(A<0){
			A1 = A2 =A3= A4=A5=0;
			break;
		}
		yu = A%5;
		//printf("%d\n",yu);
		switch(yu){
			case 0:
				if(A%2==0)	A1+=A;break;
			case 1:
				{A2+=flag*A; flag = -flag;++count2;};break;
			case 2:
				++A3;break;
			case 3:
				{A4+=A;++count3;};break;
			case 4:
				if(A > A5) A5 =A;break;
			default:
				A1 = A2 =A3= A4=A5=0;break;
		}
	}while((c=getchar())!='\n');
	//printf("%f %f\n",A4,count3);
	print(A1,1);
	if(count2)
	printf("%d ",A2); 
	else
	printf("N ");
	print(A3,1);
	if(count3)
	printf("%.1lf ",A4/count3);
	else
	printf("N ");
	print(A5,0);
}
