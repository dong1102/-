## 题目描述： ##
**给定一个链表，删除链表的倒数第 k 个节点，并且返回链表的头结点。**

示例：



- 给定一个链表: 1->2->3->4->5, 和 n = 2.



- 当删除了倒数第二个节点后，链表变为 1->2->3->5.

说明：给定的 n 保证是有效的。

进阶：你能尝试使用一趟扫描实现吗？
## 题目分析： ##
- 不使用额外空间，且一次遍历删除节点；
- 使用双指针，开始这两个指针都指向head；
- 前一个指针先走k个结点后，两个个指针同时往前走，直到前一个节点为空；
- 此时后一个结点的为止就是要删除的倒数第k个节点（前后指针之间相差为k）。

## 代码实现： ##

    /*
	 * Definition for singly-linked list.
	 * struct ListNode {
	 *     int val;
	 *     ListNode *next;
	 *     ListNode(int x) : val(x), next(NULL) {}
	 * };
	 */
	class Solution {
	public:
	    ListNode* removeNthFromEnd(ListNode* head, int n) {
	        ListNode* fort = head;
	        ListNode* back = head;
	        ListNode* p = head;
	        int size = 0;	//整个链表的长度
	        while(p)
	        {
	            p = p->next;
	            size++;
	        }
	
	        if(n == 1 && fort->next == NULL)	//删除最后一个结点，且只有一个节点
	        {
	            delete head;
	            return NULL;
	        }
	        else if(n == size)	//删除第一个节点
	        {
	            head = head->next;
	        }
	        else	//常规节点
	        {
	            while(n >= 0 && fort != NULL)
	            {
	                fort = fort->next;
	                n--;
	            }
	            while(fort != NULL)
	            {
	                back = back->next;
	                fort = fort->next;
	            }
	
	            back->next = back->next->next;  
	        }                         
	    
	        return head;
	    }     
	};