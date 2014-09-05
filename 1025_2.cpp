/*
给定一个常数K以及一个单链表L，请编写程序将L中每K个结点反转。例如：给定L为1→2→3→4→5→6，K为3，则输出应该为3→2→1→6→5→4；如果K为4，则输出应该为4→3→2→1→5→6，即最后不到K个元素不反转。

输入格式：

每个输入包含1个测试用例。每个测试用例第1行给出第1个结点的地址、结点总个数正整数N(<= 105)、以及正整数K(<=N)，即要求反转的子链结点的个数。结点的地址是5位非负整数，NULL地址用-1表示。

接下来有N行，每行格式为：

Address Data Next

其中Address是结点地址，Data是该结点保存的整数数据，Next是下一结点的地址。

输出格式：

对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。

输入样例：
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
输出样例：
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/
//本程序只有case 5运行超时，应该是寻找节点的时候问题 
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
typedef struct node List;
struct node{
	string add;
	int data;
	string next;	
};

int main(){
	string sta;
	int N,K;
	string Add,Next;
	int Data;
	cin >>sta >> N >> K ;
	vector<List> L;
	vector<List> new_L;
	List tmp_L;
	int cnt(0);//链表上节点的个数 
	for(int i = 0;i != N;++i){
		cin >> Add >> Data >> Next;
		tmp_L.add = Add;
		tmp_L.data = Data;
		tmp_L.next = Next;
		L.push_back(tmp_L);	
	}
	
	for(vector<List>::iterator iter_L =L.begin(); iter_L != L.end(); ++iter_L)
		if((*iter_L).add == sta)
			new_L.push_back(*iter_L);
		
	for(vector<List>::size_type size_new = 0; new_L[size_new].next!="-1";++size_new){
		for(vector<List>::iterator iter_L = L.begin(); iter_L!=L.end(); ++iter_L)
			if((*iter_L).add == new_L[size_new].next){
			new_L.push_back(*iter_L);
			break;
		}
	}
	cnt = new_L.size(); 
	int t = cnt / K; 
	for(int i = 0; i< t; ++i){
		vector<List>::iterator iter_rf = new_L.begin()+i*K;
		vector<List>::iterator iter_rl = new_L.begin()+i*K+K;
		reverse(iter_rf,iter_rl);
	}
	
	
	for(vector<List>::iterator ii = new_L.begin(); ii != new_L.end()-1; ++ii)
		cout << (*ii).add<<" " <<(*ii).data <<" "<< (*(ii+1)).add<<endl;
		cout << (*(new_L.end()-1)).add<<" " <<(*(new_L.end()-1)).data <<" "<< "-1";
}
