void deleteInSorted(Node* head,int n)
{
  if(n == 1)
  {
    Node* temp=head;
    head=head->next;
    delete temp;
    return;
  }
  
  Node* curr=head;
  n--;
  while(n > 1)
  {
    curr=curr->next;
  }
  
  curr->next=curr->next->next;
  if(curr->next)
  {
    curr->next->prev=curr;
  }
}
