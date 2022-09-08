int len(Node* head)
{
  int count=0;
  while(head)
  {
    count++;
    head=head->next;
  }
  return count;
}
Node* reverseInKsizeGroup(Node* head,int k)
{
  if(len(head) < k)
  {
    return head;
  }
  
  int c=k-1;
  Node* prev=NULL;
  Node* curr=head;
  
  while(k--)
  {
    Node* next-curr->next;
    curr->next=prev;
    curr->prev=next;
    curr=curr->prev;
  }
  head->next=reverseInKsizeGroup(head->next,k);
  return curr;
}
