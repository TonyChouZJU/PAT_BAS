/*
��������[-231, 231]�ڵ�3������A��B��C�����ж�A+B�Ƿ����C��

�����ʽ��

�����1�и���������T(<=10)���ǲ��������ĸ�����������T�����������ÿ��ռһ�У�˳�����A��B��C���������Կո�ָ���

�����ʽ��

��ÿ�������������һ���������Case #X: true�����A+B>C�����������Case #X: false��������X�ǲ��������ı�ţ���1��ʼ����

����������
4
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647
���������
Case #1: false
Case #2: true
Case #3: true
Case #4: false
*/

#include<stdlib.h>
#include<stdio.h>

int main(){	
	int T;
	scanf("%d",&T);
	//int�ܱ�ʾ�������������2^31-1����ֻ����long long 
 	long long A[T],B[T];
	long long C[T];
 	int i,j,k;
 	for(i = 0; i != T; ++i)
 		scanf("%lld%lld%lld",A+i,B+i,C+i);
	for(j = 0; j != T; ++j){
		printf("Case #%d: ",j+1);
		if(*(A+j)+*(B+j)>*(C+j))
			printf("true");
		else
			printf("false");
          	if(j != T-1)
                  	printf("\n");
	}
}
