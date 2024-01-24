#include <iostream>
#include <stack>
#include <vector>

using namespace std;
const int MAXSIZE=4;
/*
  push() 
  pop()
  top() 
  isEmpty() bool
  size() int
  */

//A stack is type of data structure that uses Last In First Out technique to move data in and out.

//STACK WITH STL CONTAINER

void printStackParts(stack<string> monStack) {
    while (!monStack.empty() && monStack.size() > 0) {
    string topVal= monStack.top();
    cout << topVal << endl;
    monStack.pop();
    }  
    cout << monStack.size();
}

void stlStack() {
    //Creating a stack of strings;
    stack<string>wordsStack;
    bool isEmpty = wordsStack.empty();
    cout << isEmpty << endl;
    isEmpty ? cout << "Stack is empty" << endl : cout << "Stack is not empty" <<  endl;
    while (MAXSIZE >= wordsStack.size()) {
        string myVal;
        cout << "Add a value: ";
        cin >> myVal;
        wordsStack.push(myVal);
        cout << myVal << " added to the stack, size " << wordsStack.size() << endl;
    };
    cout << "final size " << wordsStack.size() << endl;
    wordsStack.pop();
    cout << "size after pop func: " << wordsStack.size() << endl;
    wordsStack.pop();
    cout << "size after pop func: " << wordsStack.size() << endl;
    printStackParts(wordsStack);
}

//STACK WITHOU STL WITH CLASS

class MyStack{
    int list[MAXSIZE] = {};
    int top=0;
    public:
    int size() {
        return sizeof(list)/sizeof(top);
    }
    bool isEmpty(int size) {
        return size == 0 ? "true" : "false";
    }
};

void createStack() {
    MyStack monStack;
    monStack.size();
    cout << monStack.isEmpty(monStack.size()) << endl;
}

int main()
{ 
    createStack();
    return 0;
}
