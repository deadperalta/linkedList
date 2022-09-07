void pairSum(Node* head,int x)
{
  Node* end=head;
  
  while(end->next)
  {
    end=end->next;
  }
  
  Node* start=head;
  
  while(start != end)
  {
    if(start->data + end->data == x)
    {
      cout<<start->data<<" "<<end->data<<endl;
      start=start->next;
      end=end->next;
    }
    else if(start->data + end->data < x)
    {
      start=start->next;
    }
    else
    {
      end=end->prev;
    }
  }
  return;
}
