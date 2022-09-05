int getNth(Node* head,int in)
{
  Node* curr=head;
  while(in > 0)
  {
    curr=curr->next;
    in--;
  }
  return curr->val;
}
