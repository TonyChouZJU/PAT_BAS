/*
输入两个非负10进制整数A和B(<=230-1)，输出A+B的D (1 < D <= 10)进制数。

输入格式：

输入在一行中依次给出3个整数A、B和D。

输出格式：

输出A+B的D进制数。

输入样例：
123 456 8
输出样例：
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
