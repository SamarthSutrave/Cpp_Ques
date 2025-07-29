#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
}; 
class List{
  
    Node* head;
    Node* tail;

    public:
    List(){
        head = tail= NULL;
        cout<<"linked list";
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }else{
            newNode-> next = head;
            head = newNode;
        }
    }
    void push_back(int val){
        Node* newNode = new Node(val);
         if(head== NULL){
            head = tail = newNode;
         }
         else{
            tail-> next = newNode;
            tail = newNode;
         }
    }

    void pop_front(int val){
        if(head == NULL){
         cout<<"Linked list is empty";
        }
        else{
            Node* temp = head;
            head = head->next;
            temp -> next = NULL;
        }

    }

    void printll () {
        Node* temp = head ;
        while (temp!=NULL){
            cout<<temp -> data<<" -> ";
            temp = temp -> next;
        }
        cout<<"NuLL" <<endl;
    }
};
int main(){
List l1;
l1.push_front(1);
l1.push_front(2);
l1.push_back(40);
l1.push_front(3);
l1.push_front(4);
l1.push_front(5);

l1.printll();
    return 0;
}