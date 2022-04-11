狒狒喜欢吃香蕉。这里有 N 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 H 小时后回来。 
 
狒狒可以决定她吃香蕉的速度 K （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 K 根。如果这堆香蕉少于 K 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉，下一个小时才会开始吃另一堆的香蕉。  

狒狒喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
返回她可以在 H 小时内吃掉所有香蕉的最小速度 K（K 为整数）。

	118 / 118 个通过测试用例  
	状态：通过  
	执行用时: 36 ms  
	内存消耗: 33.9 MB

	class Solution {
	public:
	    int minEatingSpeed(vector<int>& piles, int h) {
	        //最简单的一种方法，找到piles中的最大最小值，然后二分查找，使得分成的堆数成为不大于h的最大值
	        int max = 1;
	        int min = 1;
	        for(int i = 0; i < piles.size(); ++i){
	            if(piles[i] > max){
	                max = piles[i];
	            }
	        }
	        //return needHour(piles, min);
	        while(min <= max){
	            int mid = (min + max)>>1;
	            if(needHour(piles, mid) > h){
	                min = mid+1;
	            }else{
	                max = mid-1;
	            }
	        }
	        return min;
	
	    }
	    int needHour(vector<int> piles, int eat) {
	        int total = 0;
	        for (int pile : piles) {
	            int hour = pile / eat;
	            total += hour * eat == pile ? hour : hour + 1;
	        }
	        return total;
	    }
	
	};  

