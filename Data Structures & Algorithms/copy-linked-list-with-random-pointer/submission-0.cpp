/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead = NULL;
        Node* tail = NULL;

        Node* temp = head;

        while(temp != NULL){
            Node* nya = new Node(temp->val);
            if(newHead == NULL){
                newHead = tail = nya;
            }else{
                tail->next = nya;
                tail = nya;
            }

            temp = temp->next;
        }

        Node* curr = newHead;
        Node* old_curr = head;

        while(old_curr != NULL){
            if(old_curr->random == NULL){
                curr->random = NULL;
            }
            else{Node* temp = head;
            int dis = 1;
            while(temp != old_curr->random){
                temp = temp->next;
                dis++;
            }
            int curr_dis = 1;
            Node* start = newHead;
            while(curr_dis < dis){
                start = start->next;
                curr_dis++;
            }
            curr->random = start;
            }
            curr = curr->next;
            old_curr = old_curr->next;
        }

        return newHead;
    }
};
