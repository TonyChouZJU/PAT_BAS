/*
��ѧ�������ǿ�ѧ��������ʾ�ܴ���С�����ֵ�һ�ַ���ķ�����������������ʽ[+-][1-9]"."[0-9]+E[+-][0-9]+�������ֵ���������ֻ��1λ��С������������1λ�������ּ���ָ�����ֵ������ż�ʹ������Ҳ�ض���ȷ������

���Կ�ѧ�������ĸ�ʽ����ʵ��A�����д������ͨ���ֱ�ʾ�����A������֤������Чλ����������

�����ʽ��

ÿ���������1��������������һ���Կ�ѧ��������ʾ��ʵ��A�������ֵĴ洢���Ȳ�����9999�ֽڣ�����ָ���ľ���ֵ������9999��

�����ʽ��

��ÿ��������������һ���а���ͨ���ֱ�ʾ�����A������֤������Чλ��������������ĩβ��0��

��������1��
+1.23400E-03
�������1��
0.00123400
��������2��
-1.2E+10
�������2��
-12000000000
*/
//case 4һֱ������ 

#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
string print(string p,int shift){
	string::size_type p_dot;
	p_dot = p.find('.');
	if(p_dot == -1){
		if(atoi(p.c_str())==0)
			return "0";	
		if(shift>0)
		p.append(shift,'0');
		else
		{
			p.append(1,'.');
			p_dot = p.size()-1;
			for(int i = 0; i != (-shift); ++i){
					//cout << p.size()<< p[p.size()-1] <<p[p.size()-2] <<endl;
				swap(p[p_dot],p[p_dot-1]);
				if(p[0]=='.')
					p.insert(0,"0");
				else
					p_dot--;
			}
		}
	}
	else{
		if(shift>0)
		for(int i =0; i!=shift; ++i){
			swap(p[p_dot],p[p_dot+1]);
			p_dot++;
			if(i==shift-1)
				p.erase(p_dot);
			if(p[p.size()-1]=='.')			
				p.append("0"); 

		}
		else
		for(int i = 0; i != (-shift); ++i){
			swap(p[p_dot],p[p_dot-1]);
			
			if(p[0]='.')
				p.insert(0,"0");
			else	
				p_dot--;
		}
	}
	return p;
}

int main(){
	string s;
	cin >>s;
	string::size_type sE,s_sign;
	sE = s.find("E");
	s_sign = sE + 1;
	//�õ�string�͵��������� 
	string sp = s.substr(1,sE-1);
	//�õ�int�͵�ָ������ 
	int e;
	string se(s,s_sign);
	e = atoi(se.c_str());
	if(s[0]=='-')
	cout <<"-";
	if(e ==0)
	cout <<sp;
	else 
	cout << print(sp,e);
	
		
}
