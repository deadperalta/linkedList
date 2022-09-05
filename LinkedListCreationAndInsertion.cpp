#include<bits/stdc++.h>
class Node {
  Node* next;
  int val;
  
  public:
  
  Node(int val)
  {
    this.val=val;
  }
};

void insertNode(Node* &head,int val)
{
  Node* temp=new Node(val);
  if(head == NULL)
  {
    head=temp;
    return;
  }
  Node* curr=head;
  while(curr)
  {
    curr=curr->next;
  }
  curr->next=temp;
}

void insertAtHead(Node* &head,int val)
{
  Node* temp=new Node(val);
  temp->next=head;
  head=temp;
}
void insertAfterNode(Node* &head,int prevNode,int val)
{
  Node* temp=new Node(val);
  
  Node* curr=head;
  
  while(curr->next && curr->next->data != prevNode)
  {
    curr=curr->next;
  }
  curr=curr->next;
  
  Node* nxt=curr->next;
  curr->next=temp;
  temp->next=nxt;
}

int main()
{
  Node* head=new Node(1);
  insertNode(head,2);
  insertNode(head,3);
  insertNode(head,4);
  insertAtHead(head,0);
  insertAfterNode(head,3,8);
}
