#include<bits/stdc++.h>
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

void printlist(Node *head){
        Node *curr=head;
        while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
        }
}

Node *delHead(Node *head)
{
    if(head== NULL)
        return NULL;
    else
    {
        Node *temp = head ->next;
        delete head;
        return temp;
    }
}

Node *delTail(Node *head)
{
    if(head== NULL)
    return NULL;
    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *curr = head;
    while(curr->next->next != NULL)
        curr = curr -> next;
    delete (curr-> next);
    curr->next=NULL;
    return head;
}

int main(){
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    printlist(head);

    head = delTail(head);
    printlist(head);


    return 0;
}