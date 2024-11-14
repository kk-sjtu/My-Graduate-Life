

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>  s1;
        stack<int>  s2;
        ListNode* p1=l1;
        ListNode* p2=l2;
        do{
            s1.push(p1->val);
            p1 = p1->next;
        
        }while(p1!=nullptr);
        
        do{
            s2.push(p2->val);
            p2 = p2->next;
        }while(p2!=nullptr);
        int flag1=s1.size()-1;
        int flag2=s2.size()-1;
        int resu = 0;
        cout<<"flag1="<<flag1<<endl;;
        cout<<"flag2="<<flag2<<endl;
        while(!s1.empty()){
            resu = resu + s1.top()*pow(10,flag1);
            cout<<"s1第"<<4-flag1<<":"<<s1.top()<<endl;
            s1.pop();
            flag1 = flag1-1;
        }
        cout<<"resu="<<resu<<endl;;
        while(!s2.empty()){
            resu = resu + s2.top()*pow(10,flag2);
            s2.pop();
            flag2 = flag2-1;
        }
        cout<<"resu="<<resu<<endl;;
// 栈不为空，导出。然后，然后根据stack.size，乘以位数（100，10等），然后输出。两个链表同理，然后相加。
        ListNode* ans = new ListNode(1);
        ListNode* p = ans;
        int temp = 0;
        while(resu!=0){
            temp = resu%10;
            resu = resu/10;
            p->next = new ListNode(temp);
            p = p->next;
        }
        return ans->next;
        
    
    
    }

};