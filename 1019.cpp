#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void kaprekar_sort(int a)
{
	int n[4];
	int rn[4];
	int a_big, a_small, a_new=1;
	while(a_new!= 6174 && a_new!=0){
	n[0] = a%10;
	n[1] = (a/10)%10;
	n[2] = (a/100)%10;
	n[3] = a/1000;
	sort(n,n+4);
	a_big = n[3]*1000 + n[2]*100 + n[1]*10 + n[0];
	a_small = n[0]*1000 + n[1]*100 + n[2]*10 + n[3];
	a_new = a_big - a_small;
	cout << n[3] << n[2] << n[1] << n[0] <<" - " 
		<< n[0] << n[1] <<n[2] <<n[3] <<" = ";
	a = a_new;
	rn[0] = a_new%10;
	rn[1] = (a_new/10)%10;
	rn[2] = (a_new/100)%10;
	rn[3] = a_new/1000;
	if(a_new == 0)
	cout << "0000" <<endl;
	else	
	cout  << rn[3] <<rn[2] <<rn[1] <<rn[0] <<endl;
	}
}

int main()
{
	int num;
	cin >>num;
	kaprekar_sort(num);	
}

