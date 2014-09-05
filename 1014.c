/*
大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：

输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。

输出格式：

在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。

输入样例：
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
输出样例：
THU 14:04
提交代码
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
