/*
*输入一个不超过1000的正整数ｎ，它为奇数时变成（3ｎ+1）的一半；为偶数时变为一半
*输出多少步后能得到1
*pat.zju.edu.cn basic_level_1001
*/

#include<iostream>

using namespace std;

int main(){
	int n;
	int count = 0;
	cin >> n;
	while(n!=1){
		n = (n % 2) ? (3*n+1)/2 :n/2;
		++count;
	}
	cout <<count;
}
