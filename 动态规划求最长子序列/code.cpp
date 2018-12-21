#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	while(cin>>str)
	{
		string str2 = str;
		reverse(str2.begin(),str2.end());
		
		//动态规划求最长公共子序列 
		int Matrix[str.length()+1][str2.length()+1];
		for(int i=0;i < str.length()+1; i++)
		{
			for(int j=0; j < str2.length()+1; j++)
			{
				if(i == 0 || j == 0)
				{
					Matrix[i][j] = 0;
				} 
				else if(str[i] == str2[j])
				{
					Matrix[i][j] = Matrix[i-1][j-1]+1;
				}
				else if(str[i] != str2[j])
				{
					Matrix[i][j] = max(Matrix[i-1][j],Matrix[i][j-1]);
				}
				
				//cout<<Matrix[i][j]<<" ";
			}
		} 
		
		int maxLen = Matrix[str.length()][str2.length()];
		cout<<str.length()-maxLen<<endl;
	}
	return 0;
}
