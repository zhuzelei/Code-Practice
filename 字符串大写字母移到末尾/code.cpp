//����˼·������ð�������˼�룬������д��ĸ��Сд��ĸǰ��ʱ��������Сд��ĸ�Ի�λ�� 

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
