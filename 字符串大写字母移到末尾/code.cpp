//解题思路：运用冒泡排序的思想，遇到大写字母在小写字母前面时，将他和小写字母对换位置 

#include <iostream>
using namespace std;

int main()
{
	string str;
	while(cin>>str)
	{
		for(int i=0; i < str.length(); i++)
		{
			for(int j=0; j < str.length()-i-1; j++)
			{
				if( (str[j] >= 'A' && str[j] <= 'Z') && (str[j+1] < 'A' || str[j+1] > 'Z') )
				{
					char buff = str[j];
					str[j] = str[j+1];
					str[j+1] = buff;
				}
			}
		}
		
		for(int i=0; i < str.length(); i++)
		{
			cout<<str[i];
		}
		cout<<endl;
	}
} 
