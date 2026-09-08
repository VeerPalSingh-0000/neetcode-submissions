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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;

        int size = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            size++;
        }

        int times = (size-1)/2;
        int curr_times = 0;

        ListNode* prev1 = head;
        ListNode* curr1 = head->next;

        while(curr_times < times){
            ListNode* prev2 = head;
            ListNode* curr2 = head->next;
            while(curr2->next != NULL){
                prev2 = curr2;
                curr2 = curr2->next;
            }

            prev2->next = NULL;
            prev1->next = curr2;
            curr2->next = curr1;

            prev1 = curr1;
            if(curr1 != NULL) curr1 = curr1->next;

            curr_times++;
        }

    }
};
