/*
读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：每个测试输入包含1个测试用例，格式为

  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩
其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。
*/
#include<stdlib.h>
#include<stdio.h>

#define LEN sizeof(struct grade_list)
typedef struct grade_list *List;

struct grade_list{
		char name[11];
		char stu_no[11];
		int grade;
		List Next;
};

void print_max_min(List L){
	int min = 101;
	int max = -1;
	List min_P,max_P;
	while(L != NULL){
		if(L->grade <= min){
			min = L->grade;
			min_P = L;
		}
		if(L->grade >= max){
			max = L->grade;
			max_P = L;
		}
		L = L->Next;
	}
	printf("%s %s\n",max_P->name,max_P->stu_no);
	printf("%s %s\n",min_P->name,min_P->stu_no);
}
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	List Head=NULL;
	List L1, L2;
	for(int i = 0; i != n; ++i){
		L1 = (List)malloc(LEN);
		if(Head == NULL)
			Head = L1;
		else
			L2->Next = L1;
		scanf("%s %s %d",L1->name,L1->stu_no,&L1->grade);
		L1->Next = NULL;
		L2 = L1;
	}
	print_max_min(Head);
}
