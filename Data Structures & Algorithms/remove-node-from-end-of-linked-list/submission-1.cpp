/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = head->next;

        int size = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            size++;
        }

        int k = 1;

        int x = size-n+1;

        while(k < x){
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            k++;
        }

        if(prev == NULL){
            curr->next = NULL;
            return nxt;
        }else if(nxt == NULL){
            prev->next = NULL;
            return head;
        }else{
            curr->next = NULL;
            prev->next = nxt;
            return head;
        }
    }
};
