117. 填充每个节点的下一个右侧节点指针 II  
  

    


		class Solution {
		public:
		    Node* connect(Node* root) {
		        //使用队列进行层序遍历的方法
		        //建立一个队列 从根节点开始层序遍历，把每一层的节点从左到右按顺序入队
		        //然后依次处理队列中的元素：1.输出；2.不断指向后方；
		    /*
		    if(!root){
		       return NULL; 
		    }
		    queue<Node*> q;
		    q.push(root);
		    while(!q.empty()){
		        int n = q.size();
		        Node* last = NULL;
		        for(int i = 0; i < n; i++){
		            Node* f = q.front();
		            q.pop();
		            if(f->left)
		                q.push(f->left);
		            if(f->right)
		                q.push(f->right);
		            if(i != 0)
		                last->next = f;
		            last = f;
		        }
		    }
		    return root;
		    */
		    //利用next指针进行层序遍历
		    //利用了next指针，在已知next的x层处理x+1层的next关系。降低了空间，时间不变
		    if(!root){
		       return NULL; 
		    }
		    Node* node = root;
		    //把node给last，然后处理每一层的节点和它的孩子节点，front来记录最后一个被处理的节点
		    //然后node初始化为null,front也是null
		    //然后node如果为null,那么就把front更新给它
		    //然后循环，直到node为null
		    while(node){
		        //重新初始化last，front，node
		        Node* last = node;
		        node = NULL;
		        Node* front = NULL;
		        //处理当前层
		        while(last){
		            //处理每一个last的左右孩子
		            //处理完last,front往后走
		            //最后last为null循环终止
		            if(last->left){
		                if(front){
		                    front->next = last->left;
		                    front = front->next;
		                }else{
		                    front = last->left;
							node = front;
		                } 
		            }
		            if(last->right){
		                if(front){
		                    front->next = last->right;
		                    front = front->next;
		                }else{
		                    front = last->right;
							node = front;
		                }
		            }
		            last = last->next;
		        }
		        }
		    return root;
		    }
		
		};