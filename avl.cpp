#include<bits/stdc++.h>
using namespace std;

class tree{
    public:
    int data;
    tree* left, *right;
    int height;
    tree(int key){
        data = key;
        left = right = NULL;
        height = 0;
    }
};


int height(tree* root){
    if(!root) return 0;
    return root->height;
}
int balance(tree* root){
    if(!root) return 0;
    return height(root->left) - height(root->right);
}

tree* rr(tree* root){
    tree* mid = root->left;
    tree* temp = mid->right;
    mid->right = root;
    root->left = temp;

    mid->height = max(height(mid->left), height(mid->right))+1;
    root->height = max(height(root->left), height(root->right))+1;
    return mid;

}
tree* lr(tree* root){
    tree* mid = root->right;
    tree* temp = mid->left;
    mid->left = root;
    root->right = temp;

    mid->height = max(height(mid->left), height(mid->right))+1;
    root->height = max(height(root->left), height(root->right))+1;
    return mid;
}

tree* insert(tree* root, int key){
    if(!root) {
        return new tree(key);
    }
    if(key<root->data){
        root->left = insert(root->left, key);
    } 
    else if(key>root->data){
        root->right = insert(root->right, key);
    }
    else return root;

    int bal = balance(root);

    if(bal<-1 and key<root->data){
        root->right = rr(root);
        return lr(root);
    }
    if(bal<-1 and key>root->data){
        return lr(root);
    }
    if(bal>1 and key>root->data){
        root->left = lr(root);
        return rr(root);
    }
    if(bal>1 and key<root->data){
        return rr(root);
    }
    return root;
}
tree* del(tree* root, int key){

    if(!root){
        return NULL;
    }
    if(key<root->data){
        root->left=del(root->left,key);
    }

    else if(key>root->data){
        root->right=del(root->right,key);
    }
    else if(key==root->data){
        if(!root->left)
            return root->right;
        else if(!root->right)
            return root->left;
    }

    root->height=max(height(root->left),height(root->right))+1;

    int bal=balance(root);

    if(bal<-1 && key<root->data){
        root->right=rr(root);
        return lr(root);
    }
    
    if(bal<-1 && key>root->data){
        return lr(root);
    }

    
    if(bal>1 && key>root->data){
        root->left=lr(root);
        return rr(root);
    }

    if(bal>1 && key<root->data){
        return rr(root);
    }

    return root;

}

void inorder(tree* root){
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    tree* root = new tree(21);
    root=insert(root,15);
    root=insert(root,6);
    root=insert(root,8);
    root=insert(root,45);
    inorder(root);
    root = del(root,15);
    inorder(root);

    return 0;
}