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
//������ֻ��case 5���г�ʱ��Ӧ����Ѱ�ҽڵ��ʱ������ 
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
	int cnt(0);//�����Ͻڵ�ĸ��� 
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
