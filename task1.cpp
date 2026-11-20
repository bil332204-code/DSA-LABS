//name: Bilal Ahmed
//reg no: 573512
//section: BSCS-15D
//this is lab 10 task 1 where we doing bst deletion
#include <iostream>
using namespace std;



//this is node struct, every node have data and left right pointer
//height is not use here but we keep it bcz same struct use in next task also
struct Node {
    int data;
    Node *left, *right;
    int height;
};
//this func make a new node, left right is null and height is 1 bcz it is leaf
Node* newNode(int value) {
    Node* n = new Node;
    n->data = value;
    n->left = n->right = nullptr;
    n->height = 1;
    return n;
}
//inorder means first left then root then right, so in bst it print in sorted order
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
//this is main delete func, it find the value and remove it and give back the new root
Node* deleteBst(Node* root,int value){

    //if root is null so tree is empty or value not there, so nothing to do just return null
    if(root==nullptr) return nullptr;

    //value is small so it will be in left side, go left and attach whatever come back
    if(value<root->data)
    {
        root->left=deleteBst(root->left,value);
    }
    //value is big so go to right side, same thing like left
    else if(value>root->data)
    {
        root->right=deleteBst(root->right,value);
    }
    //if not small not big that mean we found the node which we want to delete
    else{
        //no child so its leaf, just delete it and give null to parent
        if(root->left==nullptr&&root->right==nullptr){
            delete root;
            return nullptr;
        }
        //only right child is there so we delete node and right child come at its place
        else if(root->left==nullptr){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        //only left child is there so same thing, left child take its place
        else if(root->right==nullptr){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //two child case is little tricky, we find smallest in right side (successor)
        //then copy its value in root and delete that successor from right side
        else{
            Node* successor=root->right;
            //keep going left bcz smallest is always at most left
            while(successor->left!=nullptr){
                successor=successor->left;
            }
            root->data=successor->data;
            root->right=deleteBst(root->right,successor->data);
        }
    }
    //return root so parent pointer stay connect properly
    return root;
}
//this delete all node at end so no memory leak happen
void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}
//insert func, small value go left big value go right, same value we just ignore
Node* insertBST(Node* root, int value) {
    if (root == nullptr)
        return newNode(value);

    if (value < root->data)
        root->left = insertBST(root->left, value);
    else if (value > root->data)
        root->right = insertBST(root->right, value);

    return root;
}
//this just print msg and tree, if tree empty it print (empty)
void printTree(const string& msg, Node* root) {
    cout << msg << ": ";
    if (root == nullptr) cout << "(empty)";
    else inorder(root);
    cout << endl;
}
int main(){

    Node* root = nullptr;

    //first we make the tree with these value which given in lab
    int keys[] = {50, 30, 70, 20, 40, 60, 80, 65};
    for (int k : keys)
        root = insertBST(root, k);
    printTree("Initial tree (inorder)", root);
    //20 is leaf so it is no child case
    root = deleteBst(root, 20);
    printTree("After deleting 20 (leaf)", root);

    //60 have only one child which is 65
    root = deleteBst(root, 60);
    printTree("After deleting 60 (one child)", root);

    //50 is root and have two child, 65 will come in its place
    root = deleteBst(root, 50);
    printTree("After deleting 50 (two children)", root);
    cout << "New root is: " << root->data << endl;

    //100 is not in tree so tree should be same as before
    root = deleteBst(root, 100);
    printTree("After deleting 100 (missing key)", root);

    //now try delete from empty tree, it should not crash
    Node* emptyTree = nullptr;
    emptyTree = deleteBst(emptyTree, 10);
    printTree("Delete 10 from empty tree", emptyTree);

    //tree with only one node, after delete root should be nullptr
    Node* single = newNode(5);
    single = deleteBst(single, 5);
    printTree("Delete 5 from one-node tree", single);
    cout << "Root is nullptr: " << (single == nullptr ? "yes" : "no") << endl;

    //free all remaining node before program end
    freeTree(root);
    root = nullptr;
    return 0;
}