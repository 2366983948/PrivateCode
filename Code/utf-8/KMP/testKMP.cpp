#include"KMP.h"
#include<iostream>
using namespace std;

int main()
{
    string pattern = "ab";
    KMP kmp(pattern);
    vector<int> result = kmp.findMatches("ababab");
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
