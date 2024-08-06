// https://leetcode.com/problems/add-two-numbers/


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:

    int updateValue(int* value, int* carry_bit) {
        if(*value > 9) {
            *value = *value % 10;
            *carry_bit = 1;
        }
        else {
            *carry_bit = 0;
        }
        return *carry_bit;
    }

    void addNewNode(ListNode** l1, ListNode** l2, ListNode** head, int* carry_bit) {
        if(*l1 != nullptr || *l2 != nullptr || *carry_bit > 0) {
            ListNode* newNode = new ListNode();
            newNode -> next = nullptr;

            (*head) -> next = newNode;
            (*head) = (*head) -> next;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        head -> next = nullptr;
        ListNode* start = head;
        int carry_bit = 0;
        int value = 0;
        while(l1 != nullptr || l2 != nullptr || carry_bit > 0) {
            value += carry_bit;
            if(l1 != nullptr) {
                value += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2 != nullptr) {
                value += l2 -> val;
                l2 = l2 -> next;
            }
            
            updateValue(&value, &carry_bit);

            head -> val = value;

            addNewNode(&l1, &l2, &head, &carry_bit);

            value = 0;
        }
        return start;
    }
};
