/*
��Pi��ʾ��i�����������θ�����������M <= N <= 104�������PM��PN������������

�����ʽ��

������һ���и���M��N������Կո�ָ���

�����ʽ��

�����PM��PN������������ÿ10������ռ1�У�����Կո�ָ�������ĩ�����ж���ո�

����������
5 27
���������
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
�ύ����
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
	int prime[N];	
	while(count!=N){
		if(Isprime(i)){
			count++;
			if(count >= M)
				prime[count]=i;
		}
			
		++i;
	}
	print(prime,M,N);
			
}
