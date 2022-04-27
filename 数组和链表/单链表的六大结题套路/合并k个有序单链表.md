23. 合并K个升序链表
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。  



	class Solution {
	public:
	    struct cmp{
	        bool operator () (ListNode* node1, ListNode* node2){
	            return node1->val > node2->val;
	        }    
	    };
	    ListNode* mergeKLists(vector<ListNode*>& lists) {
	        ListNode* pre = new ListNode(0, nullptr);
	        ListNode* dummy = pre;
	
	        priority_queue<ListNode*, vector<ListNode*>, cmp> qu;
	        for(int i = 0; i<lists.size(); ++i){
	            if(lists[i] == nullptr){
	                continue;
	            }
	            qu.push(lists[i]);
	        }
	
	        while(!qu.empty()){
	            ListNode* now = qu.top();
	            qu.pop();
	
	            if(now->next != nullptr){
	                qu.push(now->next);
	            }
	            pre->next = new ListNode(now->val, nullptr);
	            pre = pre->next;
	        }
	        return dummy->next;
	    }
	};