//如果存在重复的数据，那么最小差值必然为0，那么只需要统计有多少重复的数据对即可
//如果没有重复的数据，因为map添加后自动排序，那么即可比较前后两个，找到最小的差值并统计满足这个差值的数据对个数
//最大差值其实就是最大值和最小值之差，对数即为他们俩的个数之积 
#include <iostream>
#include <map>
using namespace std;

int main()
{
	int num;
	while(cin>>num)
	{
		int flag = 0; // 用来记录是否存在重复的数据 
		map<int,int> inputMap;
		map<int,int>::iterator ite;
		
		for(int i=0; i < num; i++)
		{
			int data;
			cin>>data;
			ite = inputMap.find(data);
			if(ite != inputMap.end())
			{
				ite->second ++;
				flag = 1;
			}
			else
			{
				inputMap[data] = 1;
			}
		}
		
		//计算最小差值对数 
		int min = 0; int MinDiff = -1;
		//如果存在重复
		if(flag)
		{
			for(ite = inputMap.begin(); ite != inputMap.end(); ite++)
			{
				if(ite->second != 1)
				{
					int count = ite->second;
					min += (count*(count-1))/2;
				}
			}
		} 
		else
		{
			map<int,int>::iterator ite2 = ++inputMap.begin();
			for(ite = inputMap.begin(); ite2 != inputMap.end(); ite++,ite2++)
			{
				int k = ite2->first - ite->first;
				if(MinDiff == -1 || k < MinDiff)
				{
					MinDiff = k;
					min = 1;
				}
				else if(k == MinDiff)
				{
					min++;
				}
			}
		}
		
		//计算最大差值
		int max =  inputMap.begin()->second * (--inputMap.end())->second;
		
		cout<<min<<" "<<max<<endl;
	}
} 
