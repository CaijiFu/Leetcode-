class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res=new ListNode;//res作为结果返回
        ListNode* pos=res;//pos指向已经merge好的最后一个元素
        //将两个有序数组merge一下就好，依次接在pos后面
        while(l1!=NULL||l2!=NULL){
            if(l1==NULL) {
                pos->next=l2;
                break;
            }//l1遍历完
            if(l2==NULL) {
                pos->next=l1;
                break;
            }//l2遍历完
            if(l1->val<l2->val) {
               pos->next=l1;
               l1=l1->next;  
            }
            else{
                pos->next=l2;
                l2=l2->next;
            }
            pos=pos->next;
        }
        return res->next;//去掉开头空节点
    }
};