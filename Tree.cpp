using namespace::std;
#include <iostream>
/*    
       1
      / \
    69   11
   / \    \
  3   4    31

  */
class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node(int data) {
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

bool return_value(Node *root,int target) {
	if (root == nullptr) return false;
	if (root->data == target) return true;
	return return_value(root->left, target) || return_value(root->right, target);
}

class Cow {
public:
	int a;
	int b;
	Cow(int ass, int b) {
		this->a = ass;
		this->b = b;
	}
};

int main() {
	Node *a = new Node(1);
	Node *b = new Node(69);
	Node *c = new Node(3);
	Node *d = new Node(4);
	Node *e = new Node(11);
	Node *f = new Node(31);
	
	a->left = b;
	a->right = e;
	b->left = c;
	b->right = d;
	e->right = f;
	bool ahhh = return_value(a,2);

	Cow cow1 = Cow(1,3);
	cout << &cow1 <<"muu" << cow1.a << "\n";
	cow1.a = 5;
	cout << &cow1 << "moo" << cow1.a << "\n";

	Cow* cow2 = new Cow(4, 7);
	cow2->a = 1;
	cout << cow2->a;
	return 1;
}



