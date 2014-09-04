/*
*以B代表百，S代表十，12...n代表个位n
*换种格式输出给定正整数n(<1000)
*/

#include<stdlib.h>
#include<stdio.h>
void print_zero(int size_zero){
	for(int i = 0; i != size_zero; ++i)
		printf("%c",'0'+i+1);
	
}
void print_char(int high){
	for(int i = 0; i != (high/10)%10; ++i)
		printf("B");
	for(int i = 0; i != (high%10); ++i)
		printf("S");
 
}
void print(int a){
	int lower = a%10;
	int higher= a/10;
	if(higher)
	print_char(higher);
	print_zero(lower);
	
}

int main(){
	int n;
	scanf("%d",&n);
	print(n);
}
