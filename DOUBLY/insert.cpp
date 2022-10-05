#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node (int x)
    {
        data = x;
        next = prev = NULL;
    }
};

void printlist(Node *head){
        Node *curr=head;
        while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
        }
}

Node *insertBegin(Node *head,int data)
{
    Node *temp = new Node(data);
    temp -> next = head;
    if(head != NULL)
        head -> prev = temp;
    return temp;
}

Node *insertTail(Node *head, int data)
{
    Node *temp = new Node(data);
    if(head == NULL)
        return temp;
    Node *curr = head;
    while(curr -> next != NULL)
        curr = curr -> next;
    curr -> next = temp;
    temp -> prev = curr;
    return head;
}

int main(){
    Node *head = new Node(10);
    Node  *temp1 =  new Node(20);
    Node *temp2 = new Node(30);
    head -> next = temp1;
    temp1 -> prev = head;
    temp2 -> prev = temp1;
    temp1 -> next = temp2;
    printlist(head);
    cout<<endl;
    head = insertTail(head, 50);
    printlist(head);
    

    return 0;
}