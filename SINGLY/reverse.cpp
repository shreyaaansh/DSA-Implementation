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
    cout<<endl;
}



Node *revListNav(Node *head)
{
    vector <int> arr;
    for(Node *curr = head; curr!= NULL; curr = curr -> next)
    {
        arr.push_back(curr -> data);
    }
    for(Node *curr = head; curr!= NULL; curr = curr -> next)
    {
        curr -> data = arr.back();
        arr.pop_back();
    }
    return head;
}


Node *revListEff(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    while(curr != NULL)
    {
        Node *next =curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

//---------reverse in size of  kth group----------
Node *reversek(Node *head, int k)
{
    Node *curr = head , *prevFirst = NULL;
    bool isFirstPass = true;
    while(curr != NULL)
    {
        Node *first = curr, *prev = NULL;
        int count = 0;
        while(curr != NULL && count < k)
        {
            Node *next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(isFirstPass)
        {
            head = prev;
            isFirstPass = false;
        }
        else
        {
            prevFirst -> next = prev;
        }
        prevFirst = first;
    }
    return head;
}


int main (){
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	head->next->next->next->next=new Node(50);
    head->next->next->next->next->next=new Node(60);
    head->next->next->next->next->next-> next = new Node(70);
	printlist(head);
	head = reversek(head,3);
    printlist(head);
    
    return 0;
}