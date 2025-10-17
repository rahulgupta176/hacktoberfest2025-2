
class Solution {
public:
ListNode* reverseList(ListNode* head) {
    // REcursion
        if(head == NULL || head->next== NULL) return head;
    //ITTERATION
       ListNode* prev = NULL;    
       ListNode* curr = head;    
       ListNode* Next = head;  
       while(curr){
        Next = Next->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
       }  

       head = prev;
       return head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;
        ListNode* temp = head;
        int n = 1 ; // idx from 1 only
        while(temp!=NULL){
            if(n == left-1) a =temp;
            if(n == left) b =temp;
            if(n == right) c =temp;
            if(n == right+1) d =temp;
            temp = temp->next;
            n++;
        }
        if(a) a->next = NULL;
        if(c) c->next = NULL;
        c = reverseList(b);
       if(a) a->next = c;
        b->next = d;
       if(a) return head;
       return c;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp = head;
        int gap = 1;
        while(temp && temp->next ){
            int remLen = 0;
            ListNode* t = temp->next;
            for(int i = 1; i<= gap+1 && t!= NULL;i++){
                t = t->next;
                remLen++;
            }
            if(remLen < gap +1) gap = remLen -1;
           if(gap%2!=0) reverseBetween(temp,2,gap+2);
            gap++;
            for(int i = 1;temp!=NULL && i<=gap;i++){
                temp = temp->next;
            }
        }
        return head;
    }
};
