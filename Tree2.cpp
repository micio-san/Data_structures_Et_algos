/*
Author: Mist Uber
*/
using namespace std;
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
      data=d;
      left= nullptr;
      right=nullptr;
    }
};

/*      7
#      / \
#     8   2
#    /   / \
#   3   1   9
*/
 int breadth_first_iteration(Node* root) {
    queue<Node*> coda;
    coda.push(root);
    vector<int> result;
    while (coda.size()>0){
        Node* front=coda.front();
        coda.pop();
        result.push_back(front->data);
        if(front->left != nullptr){
            coda.push(front->left);
        }
        if(front->right != nullptr){
            coda.push(front->right);
        }
    }
    int finalVar=0;
    for(int res: result){
        finalVar+=res;
    }
    return finalVar;
 }

 int depth_first_iteration(Node* root){
   stack<Node*> my_stack;
   vector<int> result;
   my_stack.push(root);
   while (my_stack.size()>0){
    Node* first= my_stack.top();
    my_stack.pop();
    result.push_back(first->data);
    if(first->left != nullptr) {
        my_stack.push(first->left);
    }
    if(first->right != nullptr) {
        my_stack.push(first->right);
    }
   }
    int finalVar=0;
    for(int res: result){
        finalVar+=res;
    }
    return finalVar;
 }




int main() {
    Node* A=new Node(7);
    Node* B=new Node(8);
    Node* C=new Node(3);
    Node* D=new Node(2);
    Node* E=new Node(1);
    Node* F=new Node(9);
    A->left=B;
    A->right=D;
    B->left=C;
    D->left=E;
    D->right=F;
    cout << breadth_first_iteration(A) << endl;

    cout << depth_first_iteration(A);
    delete A;
    delete B;
    delete C;
    delete D;
    delete E;
    delete F;
    return 0;
}

