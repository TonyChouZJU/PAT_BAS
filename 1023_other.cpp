#include <iostream>
#include <vector>
#include <string>
using namespace std;
void swap(char *a,char *b)
{
  char temp = *a;
  *a = *b;
  *b = temp;
}
int main()
{
  vector<int> a;
  for(int i=0;i<10;i++)
  {
    int temp;
    cin >> temp;
    a.push_back(temp);
  }
  string b;
  for(int i=0;i<10;i++)
  {
    char temp = i + '0';
    b = b.append(a[i],temp);
  }
  //cout << a.size();
  if(b[0] == '0')  //第一个为0时,直接寻找，用最近的一个数与之交换
  {
    int i = 0;
    while(b[i] == '0')
    {
      i++;
    }
    swap(b[0],b[i]);
  }
  cout << b << endl;
  //system("pause");
  return 0;
}
