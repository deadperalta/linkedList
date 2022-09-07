//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};


// } Driver Code Ends
/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */


//Function to sort the given doubly linked list using Merge Sort.
Node* merge(Node* a,Node* b)
{
    if(a == NULL)
    {
        return b;
    }
    if(b == NULL)
    {
        return a;
    }
    
    Node* res=new Node(-1);
    Node* temp=res;
    
    while(a && b)
    {
        if(a->data < b->data)
        {
            temp->next=a;
            a->prev=temp;
            temp=temp->next;
            a=a->next;
        }
        else
        {
            temp->next=b;
            b->prev=temp;
            temp=temp->next;
            b=b->next;
        }
    }
    if(a)
    {
        temp->next=a;
        a->prev=temp;
    }
    if(b)
    {
        temp->next=b;
        b->prev=temp;
    }
    res->next->prev=NULL;
    res=res->next;
    return res;
}
Node* getMid(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    Node* slow=head;
    Node* fast=head->next;
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->next;
}
struct Node *sortDoubly(struct Node *head)
{
	if(head == NULL || head->next == NULL)
	{
	    return head;
	}
	
	Node* mid=getMid(head);
	Node* head2;
	
	head2=mid;
	mid->prev->next=NULL;
	head2->prev=NULL;
	
	return merge(sortDoubly(head),sortDoubly(head2));
}


//{ Driver Code Starts.

void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}


// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}

// } Driver Code Ends
