void deleteLL(Node* head)
{
  Node* curr=head;
  Node* next=NULL;
  
  while(curr)
  {
    next=curr->next;
    delete curr;
    curr=next;
  }
}
