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


//����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
//·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
//(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)

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