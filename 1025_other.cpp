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
#include<vector>
#include<algorithm>
#include<iterator>
#include<utility>
#include<stdio.h>
using namespace std;
typedef pair<int, int> P;
vector<P> coll(100000);
struct node
{
    int adress;
    int data;
    int next;
    node(int a, int b, int c) :adress(a), data(b), next(c){};
};
vector<node> vec;
int main()
{
//#ifdef ONLINE_JUDGE
//#else
//    freopen("D:\\in.txt", "r", stdin);
 //   freopen("D:\\out.txt", "w", stdout);
//#endif
    int adress, data, next;
    int n, k, first;
    while (scanf("%d%d%d", &first, &n, &k) != EOF)
    {
        int num = n;
        while (n--)
        {
            scanf("%d%d%d", &adress, &data, &next);
            P p;
            p.first = data;
            p.second = next;
            coll[adress] = p;
        }
        int index = first;
        int cnt(0);//�������ϵĽ�����
        while (index != -1)
        {
            cnt++;
            vec.push_back(node(index, coll[index].first, coll[index].second));
            index = coll[index].second;
        }
        int t = cnt / k;
        for (int i = 0; i < t; i++)
            std::reverse(vec.begin() + i*k, vec.begin() + (i + 1)*k);
        for (int i = 0; i < vec.size()-1;i++)
        {
            printf("%05d %d %05d\n", vec[i].adress, vec[i].data, vec[i + 1].adress);
        }
        printf("%05d %d %d\n", vec[vec.size() - 1].adress, vec[vec.size() - 1].data, -1);
        
    }
    return 0;
}
