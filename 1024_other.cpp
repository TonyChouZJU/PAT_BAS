#include <string>
#include <sstream>
#include <iostream>

using namespace std;

inline int string_to_int(const string& str)
{
	int ret;
	stringstream ss;
	ss << str;
	ss >> ret;
	return ret;
}

int main()
{
	string num, digits;
	int exp;

	cin >> num;
	int cut = num.find('E');
	exp = string_to_int( num.substr(cut+1) );
	digits = num[1];
	digits += num.substr(3, cut - 3);

	if (num[0] == '-')
	{
		cout << '-';
	}

	if ( exp < 0 )
	{   // digits都在0.后面
		if (exp == -1)
		{
			cout << "0." << digits << endl;
		} else
		{
			cout << "0.";
			cout.width(-exp-1);
			cout.fill('0');
			cout << 0;
			cout << digits << endl;		
		}
	} else if (exp < digits.size() - 1) 
	{   // digits在小数点两侧
		cout << digits.substr(0, exp+1);
		cout << ".";
		cout << digits.substr(exp+1);
	} else 
	{   // 没有小数点
		cout.flags(ios::left);
		cout.width(exp+1); // 要+1...
		cout.fill('0');
		cout << digits;
	}

	return 0;
}
