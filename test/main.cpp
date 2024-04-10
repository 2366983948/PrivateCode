#include<bits/stdc++.h>
#include "../Code/utf-8/RBTRee/RBTree.hpp"
using namespace std;

int main(){
    RBTree<int> tree;
    tree.Insert(1);
    tree.Insert(5);
    tree.Insert(0);
    tree.Insert(3);
    tree.Insert(-1);
    tree.Display(); 
    tree.DisplayData(); 
    return 0;
}