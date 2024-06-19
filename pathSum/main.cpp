#include <iostream>
#include <print>
#include <ranges>
#include <algorithm>
#include <vector>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int pathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) {
			return 0;
		}
		else if (root->right == nullptr && root->left == nullptr && root->val != targetSum) {
			return 0;
		}
	}
private:
	void dfs(TreeNode* root, int targetSum, int& total) {
		if (root == nullptr) {
			return;
		}

	}
};

int32_t main() {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);

	Solution sol;
	


	return 0;
}