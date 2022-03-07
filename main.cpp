#include <iostream>
#include <vector>
#include <stack>
#include "YHZBinTree.h"
using namespace std;

YHZBinTree *buildComplteTree(vector<int>leaveArray){
    int sizeOfTree = leaveArray.size();
    if(sizeOfTree<=0) return nullptr;
    vector<YHZBinTree *>trees;
    for (int i = 0; i < sizeOfTree; ++i) {
        YHZBinTree *tree = new YHZBinTree();
        tree->node = leaveArray[i];
        tree->right = NULL;
        tree->left = NULL;
        trees.push_back(tree);
   //     trees[i]->node = leaveArray[i];
    }
    for (int j = 0; j < (sizeOfTree-1)/2; ++j) {
        if((j+1) *2-1 < sizeOfTree){
            trees[j]->left = trees[(j+1) *2-1];
        }
        if((j+1)*2 < sizeOfTree){
            trees[j]->right = trees[(j+1) *2];
        }
    }
    return trees[0];

}
void preOrder(YHZBinTree *root){
    if (root == nullptr)
        return;
    printf("%d,",root->node);
    preOrder(root->left);
    preOrder(root->right);
}
void  preOrderNon(YHZBinTree *root){
    if (root == nullptr){
        return;
    }
    stack<YHZBinTree *>treeStack;
    YHZBinTree *pTree = root;
  //  printf("%d,",pTree->node);
  //  treeStack.push(pTree);
    while (pTree!=NULL||treeStack.size()){


      //

        if (pTree){
            printf("%d,",pTree->node);
            treeStack.push(pTree);
            pTree = pTree->left;


        } else{
          //  pTree = pTree->right;
            pTree = treeStack.top()->right;
            treeStack.pop();
        }
    }

   // while (p)

}
int main() {
    vector<int> treeData = {1,2,3,4,5,6,7};
    YHZBinTree* tree =  buildComplteTree(treeData);
    preOrderNon(tree);
    return 0;
}
