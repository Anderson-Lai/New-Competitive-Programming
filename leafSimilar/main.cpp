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
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		std::vector<int> first, second;

		helper(root1, first);
		helper(root2, second);

		return first == second;
	}
private:
	void helper(TreeNode* root, std::vector<int>& vals) {
		if (root == nullptr)
			return;
		else if (root->left == nullptr && root->right == nullptr) {
			vals.push_back(root->val);
			return;
		}
			
		helper(root->left, vals);
		helper(root->right, vals);
	}
};

int32_t main() {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);

	Solution sol;
	


	return 0;
}