#include <bits/stdc++.h>

using namespace std;
class bst
{
     int v;
     bst *left, *right;

 public :
    bst();
    bst(int);
    bst* insrt(bst *, int);
    void in_order(bst *);
    void pre_order(bst *);
};
bst :: bst(): v(0), left(nullptr), right(nullptr){};
bst :: bst(int v){
    this->v = v;
    left = right = nullptr;
};
bst* bst :: insrt(bst *root , int v) {
    if(!root) return new bst(v);

    if(v > root->v) {
        root -> right = insrt(root->right , v);

    } else {
        root->left = insrt(root->left , v);
    }
    return root;
}
void bst :: pre_order(bst *root) {
    if(!root) return;

    cout << root->v;
    pre_order(root->left);
    pre_order(root->right);
}
void bst :: post_order(bst *root) {
    if(!root) return;

    pre_order(root->left);
    pre_order(root->right);
    cout << root->v;
}
void bst :: in_order(bst *root) {
    if(!root) return;

    in_order(root->left);
    cout << root->v << " ";
    in_order(root->right);
}
int main()
{
    int n;
    cin >> n;
    int rt;
    cin >> rt;
    bst b, *root = nullptr;

    root = b.insrt(root , rt);
    for(int i = 1; i < n; i++) {
        int node;
        cin >> node;
        b.insrt(root , node);
    }
    b.in_order(root);
    return 0;
}
