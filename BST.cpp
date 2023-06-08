#include<bits/stdc++.h>
using namespace std;

class BST{
    int data;
    BST *left, *right;
    public:
    BST(){
        data = 0;
        left = right = NULL;
    }
    BST(int val){
        data = val;
        left = right = NULL;
    }

    BST* insert(BST* root,int val){
        if(!root){
            return new BST(val);
        }
        if(val>root->data){
            root->right = insert(root->right,val);
        }

        else if(val<root->data){
            root->left = insert(root->left,val);
        }
        return root;
    }

    void Inorder(BST* root){
        if(!root){
            return;
        }
        if(root->left) Inorder(root->left);
        cout << root->data<< " ";
        if(root->right) Inorder(root->right);
    }

    vector<int> longest(BST* root){
       if(!root){
        vector<int> temp = {};
        return temp;
       } 
       vector<int> leftpath = longest(root->left);
       vector<int>rightpath = longest(root->right);
       if(leftpath.size()>rightpath.size()){
        leftpath.push_back(root->data);
       }
       else rightpath.push_back(root->data);

       return (leftpath.size()> rightpath.size()?leftpath:rightpath); 
    }

    void mirror(BST* root){
        if(!root) return;
        else{
            BST* temp;
            mirror(root->left);
            mirror(root->right);
            temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
    }

};

int main(){
    BST b, *root =NULL;
    root =  b.insert(root, 20);
    b.insert(root, 30);
    b.insert(root, 40);
    b.insert(root, 50);
    b.insert(root, 0);
    b.insert(root, 2);
    cout << "Inorder" << endl;
    b.Inorder(root);
    cout << endl;
    vector<int> v = b.longest(root);
    for(int i=0;i<v.size();i++) cout <<v[i]<<" ";
    cout << endl;
    cout << v.size() << endl;
    b.mirror(root);
    b.Inorder(root);
    return 0;
}