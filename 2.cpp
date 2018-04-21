//better codes
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra) {
        if (l1) extra += l1->val, l1 = l1->next;
        if (l2) extra += l2->val, l2 = l2->next;
        p->next = new ListNode(extra % 10);
        extra /= 10;
        p = p->next;
    }
    return preHead.next;
}
//my codes
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        int a=l1->val+l2->val;
        if(a>9)
        {
            a=a-10;
            carry=1;
        }
        ListNode*result=new ListNode(a);
        result->val=a;
        result->next=NULL;
        ListNode*cur=result;
        l1=l1->next;
        l2=l2->next;
        while(l1!=NULL&&l2!=NULL)
        {
            int a=l1->val+l2->val+carry;
            if(a>9)
            {
                a=a-10;
                carry=1;
            }
            else
                carry=0;
            //ListNode p(a);
            cur->next=new ListNode(a);
            cur=cur->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            int a=l1->val+carry;
            if(a>9)
            {
                a=a-10;
                carry=1;
            }
            else
                carry=0;
            //ListNode p(a);
            cur->next=new ListNode(a);
            cur=cur->next;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            int a=l2->val+carry;
            if(a>9)
            {
                a=a-10;
                carry=1;
            }
            else
                carry=0;
            //ListNode p(a);
            cur->next=new ListNode(a);
            cur=cur->next;
            l2=l2->next;
        }
        if(carry==1)
            cur->next=new ListNode(1);
        return result;
    }
};
