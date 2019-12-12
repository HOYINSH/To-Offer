#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};


//输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
//路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
//(注意: 在返回值的list中，数组长度大的数组靠前)

vector<int> temp;
vector<vector<int> > res;
vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
	if (!root)
		return res;
	temp.push_back(root->val);
	if (expectNumber == root->val && !root->left && !root->right)
		res.push_back(temp);
	else{
		if (root->left)
			FindPath(root->left, expectNumber - root->val);
		if (root->right)
			FindPath(root->right, expectNumber - root->val);
	}
	temp.pop_back();
	return res;
}

vector<vector<int> > FindPath(TreeNode* root){
	if (!root)
		return res;
	temp.push_back(root->val);
	if (!root->left&&!root->right)
		res.push_back(temp);
	else{
		if (root->left)
			FindPath(root->left);
		if (root->right)
			FindPath(root->right);
	}
	temp.pop_back();
	return res;
}