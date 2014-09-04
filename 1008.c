/*一个数组A中存在N个整数，在不允许使用另外数组的情况下
*将每个整数循环向右移M个位置
*pat basic practise 1008
*/

#include<stdlib.h>
#include<stdio.h>
void shift_one(int B[],int len_B){
	int last = *(B+len_B-1);
	int tmp;
	for(int i = len_B-1; i != 0; --i)
		*(B+i) = *(B+i-1);
	*B = last;
}
void cycle_shift(int A[],int len_A,int offset){
	for(int i = 0 ; i != offset; ++i)
		shift_one(A,len_A);
	for(int i = 0 ; i != len_A; ++i)
		if(i==0)
			printf("%d",*(A+i));
		else
			printf(" %d",*(A+i));
}
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	int a[N];
	for(int i = 0; i != N; ++i)
		scanf("%d",a+i);
	cycle_shift(a,N,M);
}
