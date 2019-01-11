// 输入一组整数, 给出一个目标数, 如果目标数为该整数组中的两个数之和, 则返回这个数的下标
// 如果有多个数匹配, 则返回第一个匹配结果
#include<iostream>
#include<vector>
#include<hash_map>

using namespace std;
using namespace __gnu_cxx;

void ShowVec(vector <int>&vecList)
{
	for (vector <int>::iterator it = vecList.begin(); it != vecList.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}

// 循环遍历这个数组两次, 算法时间复杂度为O(n^2), 空间复杂度为O(1)
// 对于同第第一个数和第二个数相同的情况需要舍弃, 如1 2 3 4四个数, 目标数为2, 则1+1返回0 0不正确
void TwoSumIndices1(vector <int>&vecList, int targetNumber, int &index1, int &index2)
{
	int knum; 

	for (int i = 0; i < vecList.size(); i++)
	{
		int  knum = targetNumber - vecList[i];

		for (int j = 0; j < vecList.size(); j++)
		{
			if (knum == vecList[j] && j != i)
			{
				index1 = i;
				index2 = j;
				return;
			}
		}
	}
}

// 使用哈希表存储整数组的副本, 用目标数减去整数组中的一个数所得的第二个数在哈希表中查找
// 算法时间复杂度为O(n), 空间复杂度也为O(n)
// 查找成功返回第一个相匹配的两个数的下标
// 对于同第第一个数和第二个数相同的情况需要舍弃, 如1 2 3 4四个数, 目标数为2, 则1+1返回0 0不正确
void TwoSumIndices2(vector <int>&vecList, int targetNumber, int &index1, int &index2)
{
	hash_map<int, int> m;
	int knum;

	for (int i = 0; i < vecList.size(); i++)
	{
		m[vecList[i]] = i;
	}

	for (int i = 0; i < vecList.size(); i++)
	{
		knum = targetNumber - vecList[i];
		
		if (m.count(knum) && m[knum] != i)
		{
			index1 = i;
			int j = m[knum];
			index2 = j;
			return;
		}
	}
}

int main()
{
	vector <int> intVec;
	int size, temp, tnum, index1 = 0, index2 = 0;
	
	cout<<"Please input the size of array:";
	cin>>size;
	cout<<"Please input an array of integers: ";
	for (int i = 0; i < size; i++)
	{
		cin>>temp;
		intVec.push_back(temp);
	}

	cout<<"The integer arrays you input is: ";
	ShowVec(intVec);
	
	cout<<"Please input the target number which is the sum of two integers in the array:";
	cin>>tnum;
	
	// TwoSumIndices1(intVec, tnum, index1, index2);
	TwoSumIndices2(intVec, tnum, index1, index2);

	if (index1 == 0 && index2 == 0)
	{
		cout<<"Failure!"<<endl;
	}
	else
	{
		cout<<"The result is: "<<index1<<" "<<index2<<endl;
	}

	return 0;
}
