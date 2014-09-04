/*
*输入第一行正整数K，第二行给出K个互不相同的待验证的正整数
*输出，每个测试用例的输出占一行，按从大到小的输出关键数字
*pat basic practise
*/

#include<stdlib.h>
#include<stdio.h>
#define MAX 3500		//估计可能达到的数组上界
int isIncover(int cover[],int tofind){
	if(cover[tofind])
		return 1;
	else
		return 2;
}
void find_key(int a[],int len){
	int cover[MAX]={0};//initialize to 0
	int sorted[MAX]={1};
	int tmp;

	for(int i = 0; i != len; ++i){
		tmp = *(a+i);
		while(tmp != 1){
			if(tmp%2)
				tmp = (3*tmp+1)/2;	
			else
				tmp = tmp/2;
			cover[tmp]=1;
		}
	}

	for(int i = 0; i != len; ++i){
		tmp = *(a+i);
		sorted[tmp]=isIncover(cover,tmp);
	}

	int first = 1;
	for(int i = MAX-1; i != 0; --i){
		if(sorted[i]==2)
			if(first){
				first = 0;
				printf("%d",i);
				}
			else
				printf(" %d",i);
	}

				
	
}
int main(){
	int K;
	scanf("%d",&K);
	int b[K];
	for(int i = 0; i != K; ++i)
		scanf("%d",b+i);
	find_key(b,K);
}
