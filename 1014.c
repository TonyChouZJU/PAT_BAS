/*
����̽����Ħ˹�ӵ�һ����ֵ�������������Լ��ɣ� 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm��������̽�ܿ�������ˣ���������ֵ�����ʵ���Ͼ���Լ���ʱ�䡰������ 14:04������Ϊǰ�����ַ����е�1����ͬ�Ĵ�дӢ����ĸ����Сд�����֣��ǵ�4����ĸ'D'�����������ģ���2����ͬ���ַ���'E'�����ǵ�5��Ӣ����ĸ������һ����ĵ�14����ͷ������һ���0�㵽23��������0��9���Լ���д��ĸA��N��ʾ�����������ַ�����1����ͬ��Ӣ����ĸ's'�����ڵ�4��λ�ã���0��ʼ�������ϣ������4���ӡ��ָ��������ַ��������������Ħ˹����õ�Լ���ʱ�䡣

�����ʽ��

������4���зֱ����4���ǿա��������ո��ҳ��Ȳ�����60���ַ�����

�����ʽ��

��һ�������Լ���ʱ�䣬��ʽΪ��DAY HH:MM�������С�DAY����ĳ���ڵ�3�ַ���д����MON��ʾ����һ��TUE��ʾ���ڶ���WED��ʾ��������THU��ʾ�����ģ�FRI��ʾ�����壬SAT��ʾ��������SUN��ʾ�����ա���Ŀ���뱣֤ÿ�����Դ���Ψһ�⡣

����������
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
���������
THU 14:04
�ύ����
*/

#include<stdlib.h>
#include<stdio.h>
char *week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
void print_hour(char h){
	if(h>='0'&&h<='9')
		printf("%d:",h-'0');
	else
		printf("%d:",h-'A'+10);	
}
int getmatch_index(char str1[],char str2[]){
	int len1,len2,min_len;
	int i,j;
	char ch;

	len1 = strlen(str1);
	len2 = strlen(str2);
	min_len = (len1<len2?len1:len2);
	for(i = 0; i != min_len; ++i)
			if(*(str1+i)==*(str2+i)){
				ch = *(str1+i);
				if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
					return i%60;
			}
}
char getmatch(char str1[],char str2[],int no){
	int len1,len2,min_len;
	int i ,matched;
	len1 = strlen(str1);
	len2 = strlen(str2);
	//store the matched char
	matched = 0;
	min_len = (len1<len2 ? len1 : len2);
	char ms[min_len];
	for(i = 0; i != min_len; ++i){
			if(*(str1+i)==*(str2+i)){
				if((*(str1+i)>='A')&&(*(str1+i)<='G')&&matched==0){
				*(ms+matched+1) = *(str1+i);
				++matched;
				}
				else if((*(str1+i)>='A')&&(*(str1+i)<='N')){
					*(ms+matched+1) = *(str1+i);
				++matched;	
				}
			}
				
		}	
		return ms[no];
			
}
int main(){
	char s1[61],s2[61],s3[61],s4[61];
	char match1,match3;
	int match2;
	gets(s1);gets(s2);gets(s3);gets(s4);
	match1 = getmatch(s1,s2,1);
	match2 = getmatch(s1,s2,2);
	match3 = getmatch_index(s3,s4);
	printf("%s ",*(week+match1-'A'));
	print_hour(match2);
	if(match3/10==0)
		printf("0");
	printf("%d",match3);
	
	
}
