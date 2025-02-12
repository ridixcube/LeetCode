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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right) {
            return head;
        }
        ListNode* temp = new ListNode(0); 
        temp->next = head;
        ListNode* prev = temp;

        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }
        ListNode* current = prev->next;
        ListNode* nextNode = nullptr;
        \
        for (int i = 0; i < right - left; ++i) {
            nextNode = current->next;
            current->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }
        return temp->next;
    }
};
