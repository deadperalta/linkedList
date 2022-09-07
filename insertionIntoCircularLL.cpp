void insert(Node* head,Node* temp)
{
  if(head == NULL)
  {
    head=temp;
  }
  else if(head->data >= temp->data)
  {
    Node* curr=head;
    while(curr->next != head && curr->next->data > temp->data)
    {
      curr=curr->next;
    }
    curr->next=temp;
    temp->next=head;
    head=temp;
  }
  else
  {
    Node* curr=head;
    while(curr->data < temp->data)
    {
      curr=curr->next;
    }
    Node* nxt=curr->next;
    curr->next=temp;
    temp->next=nxt;
  }
  return head;
}
