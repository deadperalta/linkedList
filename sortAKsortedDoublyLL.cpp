void ksorted(Node* head)
{
  priority_queue<int,vector<int>,greater<int>>q;
  Node* curr=head;
  int i=0;
  while(curr && i<=k)
  {
    q.push(curr->data);
    curr=curr->next;
  }
  Node* change=head;
  
  while(curr)
  {
    change->data=q.top();
    q.pop();
    
    change=change->next;
    if(curr)
    {
      q.push(curr->data);
      curr=curr->next;
    }
  }
}
