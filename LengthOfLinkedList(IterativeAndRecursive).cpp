int lenRec(Node* head)
{
  if(head == NULL)
  {
    return 0;
  }
  
  return 1+len(head->next);
}

int lenIter(Node* head)
{
  int len=0;
  
  Node* curr=head;
  
  while(curr)
  {
    curr=curr->next;
    len++;
  }
  return len;
}
