void LLtoCircular(Node* head)
{
  Node* temp=head;
  while(temp->next)
  {
    temp=temp->next;
  }
  temp->next=head;
}
