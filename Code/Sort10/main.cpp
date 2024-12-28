#include<iostream>
#include<vector>
#include"Sort10.h"
using namespace std;
int main()
{
	vector<int> v{4,6,1,7,2,8,9,10,3,5,8};
    Sort10::BubbleSort(v);
	for(int i=0;i<=10;i++)
	{
		cout<<v[i]<<" ";
	}
}