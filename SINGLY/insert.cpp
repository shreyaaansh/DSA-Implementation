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
void printlist(Node *head){
        Node *curr=head;
        while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
        }
}


Node *insertBegin(Node *head, int x)
{
    Node *temp = new Node(x);
    temp -> next = head;
    return temp;
} 



Node *insertEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    if(head == NULL)
        return temp;
    Node *curr = head;
    while(curr -> next != NULL)
        curr = curr->next;
    curr->next = temp;
    return head;
}


Node *insertPos(Node *head, int data, int pos)
{
    Node *temp = new Node(data);
    if(pos==1)
    {
        temp->next= head;
        return temp;
    }
    Node *curr = head;
    for(int i = 1;i<=pos-2 && curr!=NULL; i++)
        curr = curr->next;
    if(curr == NULL)
        return head;
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

Node *insertSorted(Node *head, int x){
    Node *temp = new Node(x);
    if(head==NULL)
        return temp;
    if(x < head -> data)
    {
        temp -> next = head;
        return temp;        
    }
    Node *curr = head;
    while(curr -> next != NULL && curr -> next -> data < x)
    {
        curr = curr -> next;
    }
    temp -> next = curr -> next;
    curr -> next = temp;
    return head;
}


int main(){
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head -> next = temp1;
    temp1 -> next = temp2;
    head = insertSorted(head, 25);
    printlist(head);
    return 0;
}