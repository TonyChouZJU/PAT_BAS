/*
����һ������K�Լ�һ��������L�����д����L��ÿK����㷴ת�����磺����LΪ1��2��3��4��5��6��KΪ3�������Ӧ��Ϊ3��2��1��6��5��4�����KΪ4�������Ӧ��Ϊ4��3��2��1��5��6������󲻵�K��Ԫ�ز���ת��

�����ʽ��

ÿ���������1������������ÿ������������1�и�����1�����ĵ�ַ������ܸ���������N(<= 105)���Լ�������K(<=N)����Ҫ��ת���������ĸ��������ĵ�ַ��5λ�Ǹ�������NULL��ַ��-1��ʾ��

��������N�У�ÿ�и�ʽΪ��

Address Data Next

����Address�ǽ���ַ��Data�Ǹý�㱣����������ݣ�Next����һ���ĵ�ַ��

�����ʽ��

��ÿ������������˳�������ת�����������ÿ�����ռһ�У���ʽ��������ͬ��

����������
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
���������
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/

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

//������ǰ��next����һ���ڵ��add 
void m_change(vector<List>::iterator &it1,vector<List>::iterator &it2,int k){
	for(int i = 0; i != k; ++i)
		(*(it1+i)).next = (*(it1+i+1)).add;	
}
int main(){
	string sta;
	int N,K;
	string Add,Next;
	int Data;
	cin >>sta >> N >> K ;
	vector<List> L;
	vector<List> new_L;
	List tmp_L;
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
	
	for(vector<List>::size_type size_r = 0; (size_r+K) <= new_L.size()-1; 	size_r+=K){
		vector<List>::iterator iter_rf = new_L.begin()+size_r;
		vector<List>::iterator iter_rl = new_L.begin()+size_r+K;
		reverse(iter_rf,iter_rl);
		vector<List>::iterator iter_rf2 = new_L.begin()+size_r;
		vector<List>::iterator iter_rl2 = new_L.begin()+size_r+K;
		m_change(iter_rf2,iter_rl2,K);
	}
	
	
	for(vector<List>::iterator ii = new_L.begin(); ii != new_L.end(); ++ii){
		if(ii != new_L.begin())
		cout << endl;
		cout << (*ii).add<<" " <<(*ii).data <<" "<< (*ii).next;
	}
}
