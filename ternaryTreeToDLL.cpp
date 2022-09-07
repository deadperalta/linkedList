void convert(Node* root)
{
  if(root == NULL)
  {
    return;
  }
  
  if(head == NULL)
  {
    head=root;
  }
  root->prev=prev;
  if(prev)
  {
    prev->next=root;
  }
  prev=root;
  convert(root->left);
  convert(root->middle);
  convert(root->right);
}

LNode* head=NULL;
LNode* prev=NULL;
LNode* ternaryTreeToDLL(Node* root)
{
  convert(root);
  return head;
}
