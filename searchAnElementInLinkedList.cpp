bool searchRec(Node* head,int x)
{
  if(head == NULL)
  {
    return false;
  }
  
  if(head->val == x)
  {
    return true;
  }
  return searchRec(head->left,x) or searchRec(head->right,x);
}

bool searchIter(Node* head,int x)
{
  Node* curr=head;
  
  while(curr)
  {
    if(curr->val == x)
    {
      return true;
    }
    curr=curr->next;
  }
  return false;
}
