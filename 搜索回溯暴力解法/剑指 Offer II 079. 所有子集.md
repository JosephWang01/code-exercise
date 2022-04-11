78. 子集
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

执行用时：
4 ms
, 在所有 C++ 提交中击败了
43.16%
的用户
内存消耗：
7.1 MB
, 在所有 C++ 提交中击败了
27.33%
的用户

	 void dfs(vector<int>& nums, int i, bool flag){
        if(i == nums.size()){
            return;
        }
        //先序编程，对元素处理
        //进入下一个数字，选择或是不选择两种方法

        if(flag == false){
            if(!track.empty()){
            track.pop_back();
        }
        }
        else{
            track.push_back(nums[i]);
            res.push_back(track);
        }
        dfs(nums, i+1, true);
        dfs(nums, i+1, false);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        res.push_back(track);
        //tracking(nums, -1); 
        dfs(nums, 0, true);
        dfs(nums, 0, false);
        return res;
    }