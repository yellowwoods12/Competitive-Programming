/*Ques) 

Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

    Expected solution is linear in time and constant in space.

For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.

*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    ListNode *t1,*t2,*temp;
    t1=A;
    t2=A;
    temp = A;
    int size = 0;
    while(t1->next != NULL){
       size++;
       t1=t1->next;
    }
    for(int i=0;i<size/2;i++){
        t2=t2->next;
    }
    ListNode* curr, *prev,*n;
    prev=NULL;
    n = NULL;
    curr = t2;
    while(curr != NULL){
        n = curr->next;
        curr->next = prev;
        prev= curr;
        curr = n;
    }
    t2 = prev;
    while(t2->next!= NULL){
        if(temp->val == t2->val){
            temp=temp->next;
            t2=t2->next;
            
        }
        else{
            return 0;
        }
    }
    return 1;
}

