/*
����Ҫ�����A/B������A�ǲ�����1000λ����������B��1λ������������Ҫ�������Q������R��ʹ��A = B * Q + R������

�����ʽ��

������1�������θ���A��B���м���1�ո�ָ���

�����ʽ��

��1�����������Q��R���м���1�ո�ָ���

����������
123456789050987654321 7
���������
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
	//ע�����Ϊ5 8 ������� 
	if(size_A==1)
		printf("%d %d",(*A-'0')/B,(*A-'0')%B);
	else
		print(A,size_A,B);
}
