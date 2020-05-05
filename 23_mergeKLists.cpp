class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //索引优先队列lst（小堆，堆顶元素为最小的）pair前后元素为值和对应列表号的索引
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> lst;
        pair<int,int> cah;
        int index;
        ListNode* res=new ListNode;//结果的头指针
        ListNode* pos=res;//pos为指向链表最后元素指针
        for(int i=0;i!=lists.size();i++){
            if(lists[i]!=NULL){
            cah.first=lists[i]->val;
            cah.second=i;
            lst.push(cah);
            lists[i]=lists[i]->next;
            }
        }//初始化，每个链表头元素进索引优先队列
        while(!lst.empty()){
           cah=lst.top();
           ListNode* cur=new ListNode(cah.first);
           pos->next=cur;
           pos=cur;
           index=cah.second;
           lst.pop();
           if(lists[index]!=NULL){
            cah.first=lists[index]->val;
            cah.second=index;
            lst.push(cah);
            lists[index]=lists[index]->next;
           }  
        }
        return res->next;//消除开始的空节点
    }
};