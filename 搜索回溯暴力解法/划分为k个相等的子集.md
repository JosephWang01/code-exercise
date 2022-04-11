698. 划分为k个相等的子集
给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。



	
		class Solution {
		    map<int, bool> memo;
		public:
		    bool canPartitionKSubsets(vector<int>& nums, int k) {
		        //backtrack1是数字选桶，直接暴力搜索过不了时间限制，需要排序以后，尽可能多命中大数字，触发剪枝，但是时长还是大k^n
		        //先处理一些特殊情况
		        /*
		        if(k > nums.size()){
		            return false;
		        }
		        int sum = 0;
		        for(int i = 0; i<nums.size(); ++i){
		            sum += nums[i]; 
		        }
		        if(sum/k * k < sum){
		            return false;
		        }
		        //
		        sort(nums.begin(), nums.end());
		        for (int i = 0, j = nums.size() - 1; i < j; i++, j--) {
		        // 交换 nums[i] 和 nums[j]
		            int temp = nums[i];
		            nums[i] = nums[j];
		            nums[j] = temp;
		        }
		        //开始搜索回溯暴力破解
		        vector<int> bag(k);
		        //;
		        int avr = sum/k;
		        return backtrack1(nums, bag, 0, avr);
		        */
		        if(k > nums.size()){
		            return false;
		        }
		        int sum = 0;
		        for(int i = 0; i<nums.size(); ++i){
		            sum += nums[i]; 
		        }
		        if(sum/k * k < sum){
		            return false;
		        }
		        int vis = 0;
		        vector<int> bag(k);
		        int avr = sum/k;
		
		        return backtrack2(nums, vis, bag, 0, avr, 0);
		    }
		    //backtrack2是用数字装桶，避免装桶的时候出现重复的情况，就用memo作为备忘录备忘
		    //可以在终止条件中判断一个桶装满
		    //然后从第一个数字开始穷举下一个桶，做备忘处理
		    //其实都是一样的，在一个桶装满的时候做备忘处理
		    //然后在每一次更新vis的时候查一下就好了
		    bool backtrack2(vector<int>& nums, int vis, vector<int>& bag, int index, int avr, int start){
		        if(index == bag.size()){
		            return true;
		        }
		        //穷举数字放到一个一个桶里去
		        for(int i = start; i < nums.size(); ++i){
		            if(bag[index] + nums[i] > avr || (vis & (1<<i))){
		                continue;
		            }
		            bag[index] += nums[i];
		            vis |= 1<<i;
		            
		            if(memo.count(vis)){
		                bag[index] -= nums[i];
		                vis &= ~(1<<i);
		                continue;
		            }
		            
		            //穷举找到下一个没有用过的数字，是否放入当前桶里
		            if(bag[index] == avr){
		                bool bl = false;
		                //备忘状态
		                if(bl = backtrack2(nums, vis, bag, index+1, avr, 0)){
		                    return true;
		                }else{
		                    memo[vis] = bl;
		                }
		            }else{
		                //如果旧桶也从0开始就浪费时间
		                if(backtrack2(nums, vis, bag, index, avr, i+1)){
		                    return true;
		                }
		            }
		            bag[index] -= nums[i];
		            vis &= ~(1<<i);
		        }
		        return false;
		    }
		
		    bool backtrack1(vector<int>& nums, vector<int>& bag, int index,  int avr){
		        //搜索终点
		        if(index == nums.size()){
		            for(int i = 0; i < bag.size(); ++i){
		                if(bag[i] != avr){
		                    return false;
		                }
		            }
		            return true;
		        }
		        for(int i = 0; i<bag.size(); ++i){
		            if(bag[i] + nums[index] > avr){
		                continue;
		            }
		
		            bag[i] += nums[index];
		            //vis[index] = 1;
		
		            if(backtrack1(nums, bag, index+1, avr)){
		                return true;
		            }
		
		            bag[i] -= nums[index];
		            //vis[index] = 0;
		        }
		        return false;
		    }
		};