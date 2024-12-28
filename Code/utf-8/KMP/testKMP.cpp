#include"KMP.h"
#include<iostream>
using namespace std;

int main()
{
    string pattern = "aaaab";
    KMP kmp(pattern);
    vector<int> result = kmp.findMatches("aaabaaaab");
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
