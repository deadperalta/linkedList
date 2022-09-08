void removeDup(Node* head, int x)
{
  Node* prev=head;
  Node* curr=head->next;
  
  unordered_map<int,int>freq;
  
  while(curr)
  {
    int data=curr->data;
    
    if(freq[data] > 0)
    {
      curr=curr->next;
    }
    else
    {
      prev->next=curr;
      curr->prev=prev;
      
      prev=curr;
      freq[data]++;
    }
    curr=curr->next;
  }
  return head;
}
