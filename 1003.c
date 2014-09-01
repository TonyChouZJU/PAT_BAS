/*
*输出正确的条件为
*1.字符串仅含有P,A,T三种字符
*2.xPATx可以获得正确，x或者是空字符，或者仅由字母A组成
*3.如果aPbTc是正确的，那么aPbATca也是正确的，其中abc与x相同含义
*pat basic 1003 ——by zhoudaxia
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX 100
#define bool int
#define true 1
#define false 0
bool print(char *s,int size_s){
	int index_p,index_t;
	int sum_a,sum_p,sum_t;
	sum_a = sum_p = sum_t = 0;
	char cs;
	for(int i = 0; i != size_s; ++i){
		cs = *(s+i);
		if(cs == 'A')
			++sum_a;
		else if(cs == 'P'){
			++sum_p;
			index_p = i;}
		else if(cs == 'T'){
			++sum_t;
			index_t = i;}
		else
			return false;
	}
	
	if(sum_p!=1|sum_t!=1|index_t<index_p+2)
		return false;
	//if(strcmp(s,"PAT")==0)
	//	return true;
	if(index_p==0&&index_t==size_s-1)
		return true;
	/*if(index_p != (size_s-1-index_t)){
		//减去P之前的A以及P和T之间的一个A
		index_t -= (index_p+mid_a);
		index_p = 0;
	}*/
	int a = index_p;
	int b = index_t-index_p-1;
	int c = size_s-index_t-1;
	if(c==a*b)
		return true;
	else
		return false;
	

}

int main(){
	int n,len_s = 0;
	char c;
	char s[MAX];
	//bool yn;
	scanf("%d",&n);
	getchar();
	int result[n];
	for(int i = 0; i != n; ++i){
		gets(s);
		result[i] = print(s,strlen(s));
	//	yn ? printf("YES\n"):printf("NO\n");
	}	
	for(int i = 0; i != n; ++i){
		result[i] ? printf("YES\n"):printf("NO\n");
	}

}
