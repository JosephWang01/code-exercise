96. 不同的二叉搜索树
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。



		class Solution {
		    int** memo;
		public:
		    int numTrees(int n) {
		        memo = new int* [n+1];
		        for(int i = 0; i<n+1; i++){
		            memo[i] = new int[n+1];
		        }
		        for(int i = 0; i<n+1; ++i){
		            for(int j = 0; j<n+1; ++j){
		                memo[i][j] = 0;
		            }
		        }
		        return sumCon(1, n);
		    }
		    //返回树有多少种构造方式
		    int sumCon(int lf, int rt){
		        if(lf > rt){
		            return 1;
		        }
		        //可能会出现重复计算的情况
		        //用memo记录
		        int sum = 0;
		
		        if(memo[lf][rt] != 0){
		            return memo[lf][rt];
		        }
		        for(int i = lf; i <= rt; ++i){
		            int left = sumCon(lf, i-1);
		            int right = sumCon(i+1, rt);
		            sum += left*right;
		        }
		        memo[lf][rt] = sum;
		        return sum;
		    }
		};