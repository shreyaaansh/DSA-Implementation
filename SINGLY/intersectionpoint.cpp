#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int data; 
	Node* next; 
	Node (int x){
	    data=x;
	    next=NULL;
	}
}; 


//count the number of nodes from both heads c1 and c2
int getCount(Node *head)
{
    Node *curr = head;
    int count = 0;
    while(curr != NULL)
    {
        count ++;
        curr = curr -> next;
    }
    return count;
}


//move the pointer simultaneously until we reach the same node 
int _getIntersection(int d, Node* head1, Node* head2) 
{ 
    Node* current1 = head1; 
    Node* current2 = head2; 
  
    for (int i = 0; i < d; i++) { 
        if (current1 == NULL) { 
            return -1; 
        } 
        current1 = current1->next; 
    } 
  
    while (current1 != NULL && current2 != NULL) { 
        if (current1 == current2) 
            return current1->data; 
  
        current1 = current1->next; 
        current2 = current2->next; 
    } 
  
    return -1; 
}

//using hash method to find intersection
int getIntersectionHash(Node *head1, Node *head2)
{
    unordered_set<Node*> s;
    Node *curr = head1;
    while(curr != NULL){
        s.insert(curr);
        curr = curr -> next;
    }
    curr = head2;
    while(curr!= NULL){
        if(s.find(curr)!= s.end())
            return curr ->data;
        curr = curr-> next;
    }
    return -1;
}


//traverse the list from  (c1 - c2) and then after check if they are same at any certain points
int getIntersection(Node* head1, Node* head2) 
{ 
    int c1 = getCount(head1); 
    int c2 = getCount(head2); 
    int d; 
  
    if (c1 > c2) { 
        d = c1 - c2; 
        return _getIntersection(d, head1, head2); 
    } 
    else { 
        d = c2 - c1; 
        return _getIntersection(d, head2, head1); 
    }
} 



int main() 
{ 
	/* 
		Creation of two linked lists 
	
		1st 3->6->9->15->30 
		2nd 10->15->30 
	
		15 is the intersection point 
	*/

	Node* newNode; 

	Node* head1 = new Node(10); 

	Node* head2 = new Node(3); 

	newNode = new Node(6); 
	head2->next = newNode; 

	newNode = new Node(9); 
	head2->next->next = newNode; 

	newNode = new Node(15); 
	head1->next = newNode; 
	head2->next->next->next = newNode; 

	newNode = new Node(30); 
	head1->next->next = newNode; 

	head1->next->next->next = NULL; 

	cout <<getIntersection(head1, head2); 
} 

