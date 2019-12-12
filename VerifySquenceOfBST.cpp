#include <vector>
using namespace std;

// 判断数组是不是某二叉搜索树(Binary Sort Tree, BST)的后序遍历的结果
/*
注意，当sequence为null时，返回false
*/
bool VerifySquenceOfBST(vector<int> sequence){
	return Verify(sequence, 0, sequence.size() - 1);
}

bool Verify(vector<int> a, int left, int right){
	if (a.empty() || left > right)
		return false;
	if (right - left < 2)
		return true;
	int root = a[right];
	int i = left;
	for (; i < right; i++){
		if (a[i]>root)
			break;
	}
	int temp = i;
	while (i++ < right){
		if (a[i] < root)
			return false;
	}
	bool lch = true;
	if (temp > left)
		lch = Verify(a, left, temp - 1);
	bool rch = true;
	if (temp < right - 1)
		rch = Verify(a, temp, right - 1);
	return lch && rch;
}