void exchange(Node* head)
{
  
  if(head->next->next == head)
  {
    head=head->next;
  }
  Node* curr=head;
  while(curr->next->next != head)
  {
    curr=curr->next;
  }
  
  curr->next->next=head->next;
  head->next=curr->next;
  curr->next=head;
  head=head->next;
}
