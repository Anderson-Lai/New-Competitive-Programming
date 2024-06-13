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
	int maxDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;

		int total = 1;
		return std::max(helper(root->left, total), helper(root->right, total));
	}
private:
	int helper(TreeNode* root, int val) {
		if (root == nullptr)
			return val;

		val++;
		int right = helper(root->left, val);
		int left = helper(root->right, val);

		return std::max(right, left);
	}
};

int32_t main() {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);

	Solution sol;



	return 0;
}