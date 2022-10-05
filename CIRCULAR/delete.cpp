#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node (int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head)
{
    if(head==NULL)
        return ;
        cout<<head -> data<< " ";
    for(Node *p = head-> next ; p!= head; p = p -> next)
        cout<<p -> data<< " ";
    
}

Node *delHead_naive(Node *head)
{
    if(head == NULL) return NULL;
    if(head->next == head)
    {
        delete head;
        return NULL;
    }
    Node *curr = head;
    while(curr ->next != head)
        curr = curr -> next;
    curr -> next = head -> next;
    delete head;
    return (curr-> next);
}


//------------EFFICIENT-----------------
Node *delHead(Node *head)
{   
    if(head == NULL) return NULL;
    if(head -> next == head)
    {
        delete head;
        return NULL;
    }

    head -> data =head ->next -> data;
    Node *temp = head -> next;
    head -> next = head -> next -> next;
    delete temp;
    return head;
}

Node *delKth(Node *head, int k)
{
    if(head == NULL) return head;
    if(k==1)
        return delHead(head);
    Node *curr = head;
    for (int i=0; i,k-2; i++)
        curr = curr -> next;
    Node *temp = curr ->next;
    curr -> next = curr -> next -> next;
    delete temp; 
    return head;
}

int main(){
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    head -> next -> next -> next -> next = head; 
    printlist(head);
    head = delKth(head,2);
    printlist(head);

    return 0;
}