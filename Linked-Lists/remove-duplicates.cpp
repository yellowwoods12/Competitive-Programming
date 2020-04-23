/*

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    ListNode *temp1 = A;
    if(temp1->next ==NULL)
      return temp1;
    while(temp1->next){
        while(temp1->val == temp1->next->val){
            temp1->next = temp1->next->next;
            if(temp1->next == NULL){
                return A;
            }
        }
        temp1=temp1->next;
    }
    return A;
}

