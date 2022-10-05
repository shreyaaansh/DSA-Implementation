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

// --------------NAIVE METHOD-----------------
Node *insertBegin(Node *head, int x)
{
    Node *temp = new Node(x);
    if(head == NULL)
        temp -> next = head;
    else
    {
        Node *curr = head;
        while (curr -> next != head)
            curr = curr -> next;
        curr -> next = temp;
        temp -> next = head;
    }
    return temp;
}

Node *insertEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    if(head == NULL)
    {
        temp -> next = temp;
        return temp;
    }
    else
    {
        Node *curr = head;
        while(curr -> next != head)
            curr = curr->next;
        curr -> next= temp;
        temp -> next = head;
        return head;
    }
}

//--------------EFFICIENT-------------------
Node *insertEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    if(head == NULL)
    {
        temp -> next = temp;
        return temp;
    }
    else
    {
        temp -> next = head -> next;
        head -> next = temp;
        int t = temp->data;
        temp-> data = head -> data;
        head -> data = t;
        return temp;

    }
}

int main(){
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    head -> next -> next -> next -> next = head;
    head = insertBegin(head ,15);
    printlist(head);


    return 0;
}