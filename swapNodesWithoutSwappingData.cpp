void swap(Node* head,int x,int y)
{
  Node* prevx=NULL;
  Nodd* currx=head;
  
  while(currx && currx->data = x)
  {
    prevx=currx;
    currx=currx->next;
  }
  
  Node* prevy=NULL;
  Nodd* curry=head;
  
  while(curry && curry->data = x)
  {
    prevy=curry;
    curry=curry->next;
  }
  
  if(currx == NULL || curry == NULL)
  {
    return;
  }
  
  if(prevx != NULL)
  {
    prevx->next=curry;
  }
  else
  {
    head=curry;
  }
  
  if(prevy != NULL)
  {
    prevy->next=currx;
  }
  else
  {
    head=currx;
  }
  
  Node* temp=curry->next;
  curry->next=currx->next;
  currx->next=curry->next;
}
