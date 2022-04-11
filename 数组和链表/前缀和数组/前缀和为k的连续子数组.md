560. 和为 K 的子数组
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。


		class Solution {
		public:
		    int subarraySum(vector<int>& nums, int k) {
		        map<int, int> list;
		        //如果前缀和为k，那么sum-k == 0，让res+1就可以
		        list[0] = 1;
		        int sum = 0;
		        int res = 0;
		        for(int i = 0; i<nums.size(); ++i){
		            sum += nums[i];
		            //处理当前sum和sum-前面的数字
		            if(list.count(sum-k) != 0){
		                res += list[sum-k];
		            }
		            ++list[sum];
		        }
		        return res;
		    }
		};