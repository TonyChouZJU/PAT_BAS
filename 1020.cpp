/*
�±����й���������ѽ�ʱ�Ե�һ�ִ�ͳʳƷ����ͬ��������಻ͬ��ζ���±����ָ������������±��Ŀ���������ۼۡ��Լ��г�����������������������Ի�õ���������Ƕ��١�

ע�⣺����ʱ����ȡ��һ���ֿ�档���������������������ģ�����������3���±����������ֱ�Ϊ18��15��10��֣����ۼ۷ֱ�Ϊ75��72��45��Ԫ������г������������ֻ��20��֣���ô��������������Ӧ��������ȫ��15��ֵ�2���±����Լ�5��ֵ�3���±������ 72 + 45/2 = 94.5����Ԫ����

�����ʽ��

ÿ���������1������������ÿ�����������ȸ���һ��������1000��������N��ʾ�±������������Լ�������500�������Ϊ��λ����������D��ʾ�г���������������һ�и���N��������ʾÿ���±��Ŀ�����������Ϊ��λ�������һ�и���N��������ʾÿ���±������ۼۣ�����ԪΪ��λ�������ּ��Կո�ָ���

�����ʽ��

��ÿ�������������һ�������������棬����ԪΪ��λ����ȷ��С�����2λ��

����������
3 20
18 15 10
75 72 45
���������
94.50
�ύ����
*/
//֮ǰһֱ��case������  �ĳ�double�Ϳ�����  
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector> 

using namespace std;
typedef struct node List;
struct node{
	double vol;
	double price;	
};
bool compare_cake(const List &L1,const List &L2){
	double avg1,avg2;
	avg1 = L1.price/L1.vol;
	avg2 = L2.price/L2.vol;
	return avg1 > avg2;
}
int main(){
	int N,D;
	cin >> N >>D;
	List mcake[N];
	int left_s =D;
	double earn_s = 0;
	for(int i = 0; i != N; ++i)
		cin >> (mcake+i)->vol;
	for(int i = 0; i != N; ++i)
		cin >> (mcake+i)->price;
	sort(mcake,mcake+N,compare_cake);
	for(int i = 0; i != N; ++i){
		if(left_s ==0)
			break;
		if((mcake+i)->vol<=left_s){
			earn_s += (mcake+i)->price;
			left_s -= (mcake+i)->vol;
		}
		else{
			earn_s +=left_s*(mcake+i)->price/(mcake+i)->vol;
			left_s =0;
		}
	}
	printf("%.2lf",earn_s);
}
