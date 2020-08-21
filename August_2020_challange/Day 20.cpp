/*
  Problem Name  : Reorder List
  Description   : Given a singly linked list L: L0→L1→…→Ln-1→Ln,
                  reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
                  You may not modify the values in the list's nodes, only nodes itself may be changed.
  Example 1:
                  Given 1->2->3->4, 
                  reorder it to 1->4->2->3.
  Example 2:
                  Given 1->2->3->4->5, 
                  reorder it to 1->5->2->4->3.
                  
*/

// Code

    ListNode* find_mid(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* slow_prev;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow_prev = slow;
            slow = slow->next;
        }
        return slow_prev;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode* temp = head;
        ListNode* mid_prev = find_mid(head);
        ListNode* mid = mid_prev->next;
        mid_prev->next = NULL;
        ListNode* head2 = reverseList(mid);
        while(temp && head2){
            ListNode* nxt = temp->next;
            temp->next = head2;
            temp = head2;
            head2 = nxt;
        }
    }
    
// Approach is to find mid then reverse list from mid then merge them in zigzag pattern
