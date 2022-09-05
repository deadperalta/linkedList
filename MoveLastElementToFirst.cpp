Node* moveLastToFirst(Node* head)
{
  Node* curr=head;
  Node* prev=NULL;
  
  while(curr)
  {
    prev=curr;
    curr=curr->next;
  }
  
  prev->next=NULL;
  curr->next=head;
  head=curr;
  
  return head;
}
