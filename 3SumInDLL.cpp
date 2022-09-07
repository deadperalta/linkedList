void 3sum(Node* head,int x)
{
  Node* tail=head;
  while(tail->next)
  {
    tail=tail->next;
  }
  
  Node* i=head;
  while(i != tail)
  {
    Node* j=i->next;
    Node* k=tail;
    
    while(j != k && k->next != j)
    {
      if(k->data + j->data + i->data == x)
      {
        cout<<i->data<<" "<<j->data<<" "<<k->data<<" "<<endl;
        
        j=j->next;
        k=k->prev;
      }
      else if(i->data + j->data + k->data > x)
      {
        k=k->prev;
      }
      else
      {
        j=j->next;
      }
    }
    i=i->next;
  }
  return;
}
  
