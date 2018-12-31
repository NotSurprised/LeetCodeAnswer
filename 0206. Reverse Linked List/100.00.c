/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    bool flag = true;
    struct ListNode* old=NULL;
    struct ListNode* new=NULL;
    
    if (head != NULL){
        // if head == NULL or head->next == NULL
        // just return head                      
        if(head->next != NULL){
            // first time with NULL end 
            old = head; 
            head = head->next;
            old->next = NULL;
            new = head->next; 
            head->next = old;
            // continue until new == NULL
            while(new != NULL){        
                old = head;
                head = new;
                // this compiler take warning as error
                // you should make sure current & next both not NULL
                // before you change your pointer
                if(new != NULL && new->next != NULL){
                    new = new->next; 
                }else{
                    new = NULL;
                } 
                head->next = old;
            }
        }                
    }
    return head;
}