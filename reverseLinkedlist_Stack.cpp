#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    int data;
    struct Node* link;
}node;

node *head = NULL; // head node to keep track of linkedlist

/* Driver functions */
void insert(int data, int pos);
void Reverse();
void print();

int main()
{
    insert(25, 1);
     print();
    insert(8, 2);
     print();
    insert(12, 3);
     print();
    insert(100, 1);
    print();
    Reverse();
    print();

    return 0;
}

// pos = 1 : first node (after head of course)
void insert(int data, int pos) {
    //node *tmp = (node*)malloc(sizeof(node));
    node *tmp = new node;
    tmp->data = data;

    if(pos == 1) {
          tmp->link = head;
          head = tmp;
          return ;
    }
    /* Else : traverse to pos */
    // pos -2 : in consideration : head, link of prev. node is where we stop
    node *traverse = head;
    for(int i = 0; i < pos - 2; ++i) {
        if(traverse != NULL) {
            traverse = traverse->link;
        } else {
            cout << "Wrong position /n";
            return;
        }
    }
    tmp->link = traverse->link;
    traverse->link = tmp;

}

void Reverse() {
    stack<node*> Stack;
    node *traverse = head;
    /* Pushing to the stack */
    while(traverse != NULL) {
        Stack.push(traverse);
        traverse = traverse->link;
    }

    /* Popping from the stack */
    node *tmp = Stack.top();
    head = tmp;
    Stack.pop();
    while(!Stack.empty()) {
        tmp->link = Stack.top();
        Stack.pop();
        tmp = tmp->link;
    }
    tmp->link = NULL;
}

void print() {
    node *traverse = head;
    cout << "list nodes : ";
    while(traverse != NULL) {
        cout << traverse->data << ", ";
        traverse = traverse->link;
    }
    cout << "\n ---------------- \n\n";
}
