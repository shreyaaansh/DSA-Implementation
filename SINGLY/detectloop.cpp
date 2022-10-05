#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}

bool isLoop(Node *head)
{
    Node *temp = new Node(0);
    Node *curr = head;
    while( curr!= NULL){
        if( curr -> next == NULL)
            return false;
        if(curr -> next == temp)
            return true;
        Node *curr_next = curr -> next;
        curr -> next = temp;
        curr = curr_next;
    }
    return false;
}

//----------------floyd cycle detection-------------when both the pointers meet then there will be a loop detection.
bool isLoopFloyd(Node *head)
{
    Node *slow_p = head, *fast_p = head;
    while(fast_p != NULL && slow_p != NULL){
        slow_p = slow_p -> next;
        fast_p = fast_p -> next -> next;
        if(slow_p == fast_p)
            return true;
    }
    return false;
}

//---------loop detection and removal------
void detectloopremoval(Node *head)
{
    Node *slow = head, *fast = head;
    while(fast != NULL && fast ->next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast)
        {
            break;
        }
    }
    if(slow != fast)
    {
        return;
    }
    slow = head;
    while(slow -> next != fast -> next)
    {
        slow = slow -> next;
        fast = fast -> next;
    }
    fast -> next = NULL;
}

//---given only pointer delete a node---
void deleteNodeOnlypointer(Node *ptr)
{
    Node *temp = ptr -> next;
    ptr -> data = temp -> data;
    ptr -> next = temp -> next;
    delete temp;
}
int main() 
{ 
	Node *head=new Node(10);
	head->next=new Node(20);
	Node *ptr=new Node(30);
	head->next->next=ptr;
	head->next->next->next=new Node(40);
	head->next->next->next->next=new Node(25);
	printlist(head);
	deleteNodeOnlypointer(ptr);
	printlist(head);
    return 0;
}