/*
���������Ǹ�10��������A��B(<=230-1)�����A+B��D (1 < D <= 10)��������

�����ʽ��

������һ�������θ���3������A��B��D��

�����ʽ��

���A+B��D��������

����������
123 456 8
���������
1103
*/
#include<stdlib.h>
#include<stdio.h>
void print(int ele,int index){
	if(ele/index==0)
		printf("%d",ele);
	else{
		print(ele/index,index);
		printf("%d",ele%index);	
	}
}
int main(){
	int A,B,D;
	int sum;
	scanf("%d%d%d",&A,&B,&D);
	sum = A +B;
	print(sum,D);
}
