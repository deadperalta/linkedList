bool isLoop(Node* head)
{
  Node* fast-head;
  Node* slow=head;
  
  while(fast && fast->next)
  {
    slow=slow->next;
    fast=fast->next->next;
    
    if(slow == fast)
    {
      return true;
    }
  }
  return false;
}
