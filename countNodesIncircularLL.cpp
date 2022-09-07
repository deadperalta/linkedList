int nodes(Node* ll)
{
  Node* temp=head;
  int res=0;
  
  do
  {
    tenp=temp->next;
    res++;
  } while(temp != head);
  return res;
}
