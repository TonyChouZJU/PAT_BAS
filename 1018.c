/*
现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：

输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。

输出格式：

输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B

*/ 

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
void print_max(int *m){
	if(*m>=*(m+1)&&*m>=*(m+2)){
		if(*m==*(m+2))
			printf("B");
		else
			printf("C");
	}
	else if(*m<=*(m+1)&&*(m+1)>=*(m+2)){
			printf("J");
	}
	else
			printf("B");
		
}
int judge(char ca,char cb,int *c,int *d){
		if(ca == cb)
			return 0;
				
		if(ca == 'C'){
			if(cb == 'J')
				{++*c;return 1;}
			else
				{++*(d+2);return -1;}
		}
		else if(ca == 'J'){
			if(cb == 'C')
				{++*d;return -1;}
			else
				{++*(c+1);return 1;}
		}
		else{
			if(cb == 'C')
				{++*(c+2);return 1;}
			else 
				{++*(d+1);return -1;}
		}
		
}
int main(){
		int N;
		scanf("%d\n",&N);
		char p[N],q[N];
		int i;
		int py,pp,pf;
		int re;
		int P[3]={0};
		int Q[3]={0};
		re = py=pp=pf=0;
		//getchar();
		for(i = 0; i != N-1; ++i){
			scanf("%c %c\n",p+i,q+i); 
			re = judge(*(p+i),*(q+i),P,Q);
			if(re==1)
				++py;
			else if(re==0)
				++pp;
				else
				++pf;
		}
		printf("%d %d %d\n",py,pp,pf);
		printf("%d %d %d\n",pf,pp,py);
		
		print_max(P);
		printf(" ");
		print_max(Q);

}
