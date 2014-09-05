/*
正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。

现给定A、DA、B、DB，请编写程序计算PA + PB。

输入格式：

输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。

输出格式：

在一行中输出PA + PB的值。

输入样例1：
3862767 6 13530293 3
输出样例1：
399
输入样例2：
3862767 1 13530293 8
输出样例2：
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
