/*
�ָ������˵Ľ����¼����ͳ��˫����ʤ��ƽ�������������Ҹ���˫���ֱ��ʲô���Ƶ�ʤ�����

�����ʽ��

�����1�и���������N��<=105������˫������Ĵ��������N�У�ÿ�и���һ�ν������Ϣ�����ס���˫��ͬʱ�����ĵ����ơ�C�������ӡ���J������������B������������1����ĸ����׷�����2�������ҷ����м���1���ո�

�����ʽ��

�����1��2�зֱ�����ס��ҵ�ʤ��ƽ�������������ּ���1���ո�ָ�����3�и���������ĸ���ֱ����ס��һ�ʤ�����������ƣ��м���1���ո�����ⲻΨһ�����������ĸ����С�Ľ⡣

����������
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
���������
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
