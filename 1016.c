/*
������A�ġ�DA��Ϊ1λ���������֡�����Ϊ��A������DA��ɵ�������PA�����磺����A = 3862767��DA = 6����A�ġ�6���֡�PA��66����ΪA����2��6��

�ָ���A��DA��B��DB�����д�������PA + PB��

�����ʽ��

������һ�������θ���A��DA��B��DB���м��Կո�ָ�������0 < A, B < 1010��

�����ʽ��

��һ�������PA + PB��ֵ��

��������1��
3862767 6 13530293 3
�������1��
399
��������2��
3862767 1 13530293 8
�������2��
0

*/

#include<stdlib.h>
#include<stdio.h>
int find_P(int ele,int toFind){
	int higher,lower;
	int sum;
	sum = 0;
	do{
		lower = ele%10;
		ele = ele/10;
		if(lower == toFind)
			sum = 10*sum +toFind;			
	}while(ele!=0);
	return sum;
}
int main(){
		int A,DA,B,DB;
		int PA,PB;
		scanf("%d%d%d%d",&A,&DA,&B,&DB);
		PA = find_P(A,DA);
		PB = find_P(B,DB);
		printf("%d",PA+PB);
}
