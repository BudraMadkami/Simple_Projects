#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* res = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int total = carry;
            if (l1) {
                total += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                total += l2->val;
                l2 = l2->next;
            }
            res->next = new ListNode(total % 10);
            carry = total / 10;
            res = res->next;
        }
        return dummy.next;
    }
};

ListNode* list_to_linked(int arr[], int n) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int i = 0; i < n; ++i) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return dummy->next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr1[] = {2, 3, 4};
    int arr2[] = {5, 6, 7};
    ListNode* l1 = list_to_linked(arr1, 3);
    ListNode* l2 = list_to_linked(arr2, 3);
    Solution s;
    ListNode* result = s.addTwoNumbers(l1, l2);
    printList(result);
    return 0;
}