

//快速排序
//复杂度可以通过观察p1的位置，例如完全相同的数组，那么每一次p1 都会到最后一个，因此O（n^2）
int *quicksort(Node* pBegin, Node* pEnd){
	if(pBegin == NULL || pEnd == NULL || pBegin == pEnd){
		return 0;
	}
	//定义两个指针
	Node* p1 = pBegin;
	Node* p2 = pBegin->next;
	int data = pBegin->data;
	//每次与data进行比较，p1定位小的最后一个值，p2一直向后移，经过一轮比较以后p1指向中值
	while(p2 != NULL){
		if(p2->data < data){
			p1 = p1->next;
			if(p1 != p2){
				swap(&p1->data, &p2->data);
			}
		}
		p2 = p2->next;
	}
	swap(&p1->data, &pBegin->data);
	quicksort(pBegin, p1);
	quicksort(p1->next, pEnd);
	
}

//冒泡排序
//最坏O(n^2)
//最好时间复杂度：O(N)
//平均时间复杂度：O(N2)  

void bubbleSort(int *arr, int n){
	int m,i,j;
	for(i = 0; i<n-1; i++){
		for(j = 0; i<n-1-i; j++){
			if(arr[j] > arr[j+1]){
				m = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = m;
			}
		}
	}
}

//堆排序
//最好时间复杂度：O(NlogN)
//最坏时间复杂度：O(NlogN)
//平均时间复杂度：O(NlogN)
void heapify(Mytype tree[], int n, int i){
	if(i >= n){
		return;
	}
	//当前父节点的两个子节点
	int c1 = 2*i + 1;
	int c2 = 2*i + 2;
	//假设根节点为最大值
	int max = i;
	//找出子树中三个
}

int build_heap (Mytype tree[],int n)
{
	int last_node = n-1;
	//最后一个父节点
	int parent = (last_node-1)/2;
	int i;
	//从最后一个父节点开始，由下到上遍历每一个父节点依次调整构建堆
	for(i = parent;i>=0;i--)
	{
		heapify(tree,n,i);
	}
}

/*
* @Description: 堆排序时间复杂度 O(nlogn) 思想：构建大根堆/小根堆，将堆顶元素与最后
一个叶子节点交换，切断叶子节点 （B站正月点灯笼）
* @Param: Mytype tree[] 数组 int n 数组中元素的个数
* @Return: 无
* @Author: Carlos
*/
int HeapSort (Mytype tree[],int n)
{
	//构建堆 第一个节点为堆中最大的数
	build_heap(tree,n);
	int i;
	  //每次都换出来一个最大值
	for(i = n-1;i>=0;i--)
	{
		//交换最后一个节点和第一个节点
		swap(tree,i,0);
		//每次都截断最后一个元素，我们可以默认最后一个元素已经被截断了，i即为剩下的元
		素，每次传入i的值即可继续构建0--i范围内的元素
		heapify(tree,i,0);
	}
}

//插入排序
//直接插入排序函数 升序
void InsertSort(Mytype a[], int n)
{
	//注意从第二个元素开始
	  for(int i= 1; i<n; i++)
	 {
	    //如果a[i-1]本来就是小于a[i]的，就不需要做任何操作。当a[i-1]是较大的元素，需要从i向前找，找到合适的位置，插在a[i]前面
	    if(a[i] < a[i-1])
	   {//若第 i 个元素大于 i-1 元素则直接插入；反之，需要找到适当的插入位置后在插入。
	      int j= i-1;
	      int x = a[i];
	      //在0到j-1的中找到 a[i-1]<a[i]的位置
	      //从第j个元素开始，即i的前一个。找一个比i位置元素小的位置
	      while(j>-1 && x < a[j])
	     {  //采用顺序查找方式找到插入的位置，在查找的同时，将数组中的元素进行后移操作，给插入元素腾出空间
	        a[j+1] = a[j];
	        j--;
	     }
	      //跳出循环时，找到了x > a[j] 的恰当位置
	      a[j+1] = x;    //插入到正确位置
	   }
	 }
}

