Node* reversal(Node* head)
{
  if(head == NULL || head->next == NULL)
  {
    return head;
  }
  Node* curr=head;
  Node* prev=NULL;
  
  while(curr)
  {
    Node* next=curr->next;
    curr->next=prev;
    curr->prev=next;
    curr=curr->prev;
  }
  return prev;
}

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
  
  Node* temp=new Node(0);
  Node* res=temp;
  
  while(a && b)
  {
    if(a->data < b->data)
    {
      res->next=a;
      a->prev=res;
      a=a->next;
      res=res->next;
    }
    else
    {
      res->next=b;
      b->prev=res;
      b=b->next;
      res=res->next;
    }
  }
  
  if(a)
  {
    res->next=a;
    a->prev=res;
  }
  if(b)
  {
    res->next=b;
    b->prev=res;
  }
  
  return temp->next;
}

Node* sort(Node* head)
{
  Node* curr=head;
  
  while(curr->next && curr->next->data > curr->data)
  {
    curr=curr->next;
  }
  
  Node* head2=curr->next;
  
  if(head2)
  {
    head2->prev=NULL;
  }
  curr->next=NULL;
  
  return merge(head,reverse(head2));
