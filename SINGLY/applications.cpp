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
    }cout<<endl;
}

void Middle_naive(Node *head){
    if(head == NULL)
        return ;
    int count;
    Node *curr;
    for(curr = head; curr!=NULL; curr = curr -> next)
        count++;
    curr = head;
    for(int i =0 ; i<count/2; i++)
        curr = curr -> next;
    cout<<curr -> data;
}

void Middle_efficient(Node *head)
{
    if(head == NULL)
        return;
    Node *fast = head, *slow = head;
    while(fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    cout<<slow -> data;
}

void NthfromEnd(Node *head, int n)
{
    int len = 0;
    for(Node *curr = head ; curr != NULL; curr = curr -> next)
        len++;
    if(len < n)
        return;
    Node *curr = head;
    for(int i=1 ; i< (len -n +1); i++)
        curr = curr -> next;
    cout<<(curr -> data)<<" ";
}


void NthfromEndPointer(Node *head, int n)
{
    if (head == NULL)
        return;
    Node *first = head;
    for(int i = 0;i<n ; i++)
    {
        if(first == NULL)
            return;
            first = first -> next;
    }
    Node *second = head;
    while (first != NULL){
        second = second -> next;
        first = first -> next;
    }
    cout<<(second -> data); 
}

Node* removeDuplicates(Node* head)
{
	Node *temp = head, *prev = head;

	while (temp != NULL) {
		if (temp->data != prev->data) {
			prev->next = temp;
			prev = temp;
		}
		temp = temp->next;
	}
	if (prev != temp)
		prev->next = NULL;
	return head;
}

Node* push(Node* head, int new_data)
{
	Node* new_node = new Node(new_data);
	new_node->next = head;
	head = new_node;
	return head;
}

int main (){
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(20);
	head->next->next->next=new Node(50);
	head->next->next->next->next=new Node(50);
    head->next->next->next->next->next=new Node(60);
	printlist(head);
	

    return 0;
}
