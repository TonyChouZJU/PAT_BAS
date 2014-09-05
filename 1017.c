/*
本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。

输入格式：

输入在1行中依次给出A和B，中间以1空格分隔。

输出格式：

在1行中依次输出Q和R，中间以1空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3
*/

#include<stdlib.h>
#include<stdio.h>
void print(char s[],int len,int chushu){
	int i;
	int R;
	int tmp_s;
	tmp_s = 0;
	R = 0;
	for(i = 0 ; i != len; ++i){
		tmp_s = *(s+i)-'0';
		if(i==0&&tmp_s<chushu){
			R = tmp_s;
			continue;
		}
		R = R*10 + tmp_s;
		printf("%d",R/chushu);
		R = R%chushu;	
	}	
	printf(" %d",R);
}
int main(){
	char A[1000];
	int B;
	int size_A;
	scanf("%s%d",A,&B);
	size_A = strlen(A);
	//注意输出为5 8 这种情况 
	if(size_A==1)
		printf("%d %d",(*A-'0')/B,(*A-'0')%B);
	else
		print(A,size_A,B);
}
