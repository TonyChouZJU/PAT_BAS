/*
给定数字0-9各若干个。你可以以任意顺序排列这些数字，但必须全部使用。目标是使得最后得到的数尽可能小（注意0不能做首位）。例如：给定两个0，两个1，三个5，一个8，我们得到的最小的数就是10015558。

现给定数字，请编写程序输出能够组成的最小的数。

输入格式：

每个输入包含1个测试用例。每个测试用例在一行中给出10个非负整数，顺序表示我们拥有数字0、数字1、……数字9的个数。整数间用一个空格分隔。10个数字的总个数不超过50，且至少拥有1个非0的数字。

输出格式：

在一行中输出能够组成的最小的数。

输入样例：
2 2 0 0 0 3 0 0 1 0
输出样例：
10015558
*/

#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct node List;
struct node{
	int index;
	int value;	
};
void print(List *L,int len){
	if((L->index!=0))
		while((L->value !=0)){
			for(int i =0; i != L->value; ++i)
				printf("%d",L->index);
			++L;
		}
	else{
	printf("%d",(L+1)->index);
	for(int i = 0; i != L->value; ++i)
		printf("0");
	((L+1)->value)--;
	++L;
	//为了应对 1 1 1 1 1 1 1 1 1 1 全为1的情况 
	if(L->value ==0)
		L++;
	while((L->value !=0)){
			for(int i =0; i != L->value; ++i)
				printf("%d",L->index);
			++L;

		}
	}
		
}
bool compare_value(const List &L1,const List &L2){
	if(L2.value == 0)
	return true;
	if(L1.value ==0)
	return false;
	return L1.index <= L2.index;	
}
int main(){
	List N[10];
	for(int i = 0; i != 10; ++i){
		scanf("%d",&(N+i)->value);
		(N+i)->index = i;
	}
	sort(N,N+10,compare_value);
	/*for test
	List *tmp;
	tmp = N;
	for(int i = 0; i != 10; ++i,++tmp)
		printf("%d %d\n",tmp->index,tmp->value);
	*/
	print(N,10);
		
}
