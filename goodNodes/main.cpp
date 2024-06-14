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
	int goodNodes(TreeNode* root) {
		if (root == nullptr)
			return 0;
		else if (root->left == nullptr && root->right == nullptr)
			return 1;
		
		int max = root->val;
		int nodes = 0;

		return helper(root->left, max, nodes) + helper(root->right, max, nodes) + 1;
	}
private:
	int helper(TreeNode* root, int max, int curr) {
		if (root == nullptr)
			return curr;
		
		if (root->val >= max) {
			curr++;
			max = root->val;
		}
		return helper(root->left, max, curr) + helper(root->right, max, curr);
	}
};

int32_t main() {
	std::cin.sync_with_stdio(0);	
	std::cin.tie(0);

	Solution sol;
	
	TreeNode l1l1(3);
	TreeNode l1(1, &l1l1, nullptr);
	TreeNode r1r1(5);
	TreeNode r1l1(1);
	TreeNode r1(4, &r1l1, &r1r1);
	TreeNode root(3, &l1, &r1);

	std::cout << sol.goodNodes(&root) << "\n";


	return 0;
}