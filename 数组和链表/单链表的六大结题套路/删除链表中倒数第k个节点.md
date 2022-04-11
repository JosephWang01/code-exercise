 19. 删除链表的倒数第 N 个结点
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。  

		class Solution {
		public:
		    ListNode* removeNthFromEnd(ListNode* head, int n) {
		        ListNode* fast = head;
		        while(n > 0){
		            fast = fast->next;
		            n--;
		        }
		        ListNode* slow = head;
		        if(fast == nullptr){
		            head = head->next;
		            return head;
		        }
		        while(fast->next != NULL){
		            fast = fast->next;
		            slow = slow->next;
		        }
		        slow->next = slow->next->next;
		        return head;
		    }
		};