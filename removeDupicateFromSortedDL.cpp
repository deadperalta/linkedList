void removeDup(Node* head)
{
  Node* curr=head;
  Node* prev=head;
  while(curr)
  {
    if(curr->next && curr->next->data == curr->data)
    {
      while(curr->next && curr->next->data == curr->data)
      {
        curr=curr->next;
      }
      prev->next=curr->next;
      prev=curr->next;
    }
    curr=curr->next;
  }
  return head;
}
