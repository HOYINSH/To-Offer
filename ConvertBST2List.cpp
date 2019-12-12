

//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
#include<vector>
using namespace std;
//要求不能创建任何新的结点，只能调整树中结点指针的指向。
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
class Solution {
public:
	vector<TreeNode> InOrder(TreeNode* root){
		vector<TreeNode> res;
		if (root){
			InOrder(root->left);
			res.push_back(*root);
			InOrder(root->right);
		}
		return res;
	}
	TreeNode* Convert(TreeNode* pRootOfTree){
		if (!pRootOfTree)
			return NULL;
		auto left_min = Convert(pRootOfTree->left);
		auto right_min = Convert(pRootOfTree->right);
		auto lastNodeOfLeft = pRootOfTree->left;
		while (lastNodeOfLeft && lastNodeOfLeft->right)
			lastNodeOfLeft = lastNodeOfLeft->right;
		if (!lastNodeOfLeft)
			left_min = pRootOfTree;
		else{
			pRootOfTree->left = lastNodeOfLeft;
			lastNodeOfLeft->right = pRootOfTree;
		}
		pRootOfTree->right = right_min;
		if (right_min)
			right_min->left = pRootOfTree;
		return left_min;
	}
	TreeNode* ConstructList(TreeNode* pRootOfTree){
		if (!pRootOfTree)
			return NULL;
		auto p = pRootOfTree->left;
		while (p && p->right)
			p = p->right;
		auto q = pRootOfTree->right;
		while (q && q->left)
			q = q->left;
		auto left = pRootOfTree->left;
		auto right = pRootOfTree->right;	
		if (p)
			pRootOfTree->left = p;
			p->right = pRootOfTree;
		if (q)
			pRootOfTree->right = q;
			q->left = pRootOfTree;
		ConstructList(left);
		ConstructList(right);
		return pRootOfTree;
	}
	TreeNode* Convert_testing(TreeNode* pRootOfTree){
		TreeNode* p = ConstructList(pRootOfTree);
		while (p && p->left)
			p = p->left;
		return p;
	}
};