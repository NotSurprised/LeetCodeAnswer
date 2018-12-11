/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* allocNewNode(int num){
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    if(newNode==NULL){
        return NULL;
    }
    newNode->val = num;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* curl1 = l1;
    struct ListNode* curl2 = l2;
    if(curl1 == NULL || curl2 == NULL){
        return NULL;
    }
    
    struct ListNode* ans = allocNewNode(0);         //this will be ans root.
    if(ans == NULL){
        return NULL;
    }
    
    struct ListNode* curAns = ans;                  // this will be dynamic pointer.
    
    int carry = 0;
    while(curl1 != NULL || curl2 != NULL){
        int num1 = (curl1 !=NULL) ? curl1->val : 0; // from down to up, just simply give 0 to null.
        int num2 = (curl2 !=NULL) ? curl2->val : 0;
        int sum = num1 + num2 + carry;              // carry store last while roop's carry.
        carry = sum/10;                             // remain to next roop.
        curAns->next = allocNewNode(sum%10);
        curAns = curAns->next;
        if(curl1 != NULL) curl1 = curl1->next;
        if(curl2 != NULL) curl2 = curl2->next;
    }
    
    if(carry == 1){                                 // In add mode, carry should always be 1.
        curAns->next = allocNewNode(carry);
    }
    
    return ans->next;                               // remember we alloc 0 already while declared it.
}