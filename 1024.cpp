/*
科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式[+-][1-9]"."[0-9]+E[+-][0-9]+，即数字的整数部分只有1位，小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。

输入格式：

每个输入包含1个测试用例，即一个以科学计数法表示的实数A。该数字的存储长度不超过9999字节，且其指数的绝对值不超过9999。

输出格式：

对每个测试用例，在一行中按普通数字表示法输出A，并保证所有有效位都被保留，包括末尾的0。

输入样例1：
+1.23400E-03
输出样例1：
0.00123400
输入样例2：
-1.2E+10
输出样例2：
-12000000000
*/
//case 4一直过不了 

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
	//得到string型的整数部分 
	string sp = s.substr(1,sE-1);
	//得到int型的指数部分 
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
