//��������ظ������ݣ���ô��С��ֵ��ȻΪ0����ôֻ��Ҫͳ���ж����ظ������ݶԼ���
//���û���ظ������ݣ���Ϊmap��Ӻ��Զ�������ô���ɱȽ�ǰ���������ҵ���С�Ĳ�ֵ��ͳ�����������ֵ�����ݶԸ���
//����ֵ��ʵ�������ֵ����Сֵ֮�������Ϊ�������ĸ���֮�� 
#include <iostream>
#include <map>
using namespace std;

int main()
{
	int num;
	while(cin>>num)
	{
		int flag = 0; // ������¼�Ƿ�����ظ������� 
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
		
		//������С��ֵ���� 
		int min = 0; int MinDiff = -1;
		//��������ظ�
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
		
		//��������ֵ
		int max =  inputMap.begin()->second * (--inputMap.end())->second;
		
		cout<<min<<" "<<max<<endl;
	}
} 
