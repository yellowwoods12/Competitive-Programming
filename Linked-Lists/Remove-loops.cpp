//Remove loops from a linked list

/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *head)
{
   // bool val = detectLoop(head);
    Node *prev;
    int flag =0;
          Node *slow=head, *fast=head;
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow == fast)
           
           break;
    }
    
    if(slow==fast){
        slow = head;
    while(slow->next != fast->next){
        
        fast=fast->next;
        slow=slow->next;
    }
    fast->next = NULL;
    }
    
    

    
     //Your code here
}
