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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;

        int size = 0; ListNode* temp = head;
        while(temp != NULL){
            size++;
            temp = temp->next;
        }

        if(size < k) return head;

        int total_times = size/k;
        int curr_time = 1;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = head->next;

        while(curr_time <= total_times){
            ListNode* oldStart = prev;
            ListNode* oldLast = curr;
            int curr_k = 1;

            while(curr_k <= k){
                curr->next = prev;
                prev = curr;
                curr = nxt;
                if(nxt != NULL){
                    nxt = nxt->next;
                }
                curr_k++;
            }

            if(oldStart != NULL){
                oldStart->next = prev;
            }else{
                head = prev;
            }

            oldLast->next = curr;
            curr_time++;

        }

        return head;
    }
};
