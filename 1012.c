/*
����һϵ�����������밴Ҫ������ֽ��з��࣬���������5�����֣�

A1 = �ܱ�5����������������ż���ĺͣ�
A2 = ����5������1�����ְ�����˳����н�����ͣ�������n1-n2+n3-n4...��
A3 = ��5������2�����ֵĸ�����
A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ��
A5 = ��5������4��������������֡�
�����ʽ��

ÿ���������1������������ÿ�����������ȸ���һ��������1000��������N��������N��������1000�Ĵ�����������������ּ��Կո�ָ���

�����ʽ��

�Ը�����N��������������ĿҪ�����A1~A5����һ����˳����������ּ��Կո�ָ�������ĩ�����ж���ո�

������ĳһ�����ֲ����ڣ�������Ӧλ�������N����

��������1��
13 1 2 3 4 5 6 7 8 9 10 20 16 18
�������1��
30 11 2 9.7 9
��������2��
8 1 2 4 5 6 7 9 16
�������2��
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
	//������͵�ֵ����Ϊ0 
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
