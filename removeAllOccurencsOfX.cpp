void removeOccurenceOfX(Node* head,int x)
{
  Node* prev=NULL;
  Node* curr=head;
  
  while(curr)
  {
    if(curr->data == x)
    {
      curr=curr->next;
    }
    else
    {
      if(prev == NULL)
      {
        head=curr;
        curr->prev=prev;
      }
      else
      {
        prev->next=curr;
        curr->prev=prev;
      }
      prev=curr;
    }
    curr=curr->next;
  }
}
