/*
��������0-9�����ɸ��������������˳��������Щ���֣�������ȫ��ʹ�á�Ŀ����ʹ�����õ�����������С��ע��0��������λ�������磺��������0������1������5��һ��8�����ǵõ�����С��������10015558��

�ָ������֣����д��������ܹ���ɵ���С������

�����ʽ��

ÿ���������1������������ÿ������������һ���и���10���Ǹ�������˳���ʾ����ӵ������0������1����������9�ĸ�������������һ���ո�ָ���10�����ֵ��ܸ���������50��������ӵ��1����0�����֡�

�����ʽ��

��һ��������ܹ���ɵ���С������

����������
2 2 0 0 0 3 0 0 1 0
���������
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
	//Ϊ��Ӧ�� 1 1 1 1 1 1 1 1 1 1 ȫΪ1����� 
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
