//Detect loop in a linked list

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

bool detectLoop(Node *head){
    Node *slow=head, *fast=head;
    while(slow && fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow == fast)
           return 1;
    }
    
    return 0;
}