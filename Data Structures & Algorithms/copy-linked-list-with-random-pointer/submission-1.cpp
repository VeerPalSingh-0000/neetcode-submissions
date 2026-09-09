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
        if(head == NULL){
            return NULL;
        }

        // Step 1: Create the normal copied linked list
        Node* head1 = new Node(head->val);
        Node* tail = head1;

        Node* temp = head->next;

        while(temp != NULL){
            Node* newNode = new Node(temp->val);

            tail->next = newNode;
            tail = newNode;

            temp = temp->next;
        }

        // Step 2: Copy random pointers
        Node* temp1 = head;
        Node* temp2 = head1;

        while(temp1 != NULL){

            if(temp1->random == NULL){
                temp2->random = NULL;
            }
            else{
                // Find the position of temp1->random
                int place = 1;
                Node* aur = head;

                while(aur != temp1->random){
                    aur = aur->next;
                    place++;
                }

                // Go to the same position in copied list
                Node* extra = head1;
                int jagah = 1;

                while(jagah < place){
                    extra = extra->next;
                    jagah++;
                }

                temp2->random = extra;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return head1;
    }
};