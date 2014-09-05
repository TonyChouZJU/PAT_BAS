#include<iostream>
#include<string>

using namespace std;

int main(){
	string s;
	cin >>s;
	char c;
	int first = 0;
	int N[10]={0};
	for(string::iterator iter_s = s.begin(); iter_s != s.end(); ++iter_s)
		++N[*iter_s-'0'];
	for(int j = 0; j != 10; ++j){
		if(*(N+j)){
		if(first)
			cout<<endl;
		cout << j << ":" <<*(N+j);
		first = 1;
	}
	}
			

}
