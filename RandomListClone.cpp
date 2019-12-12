using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead){
		if (!pHead)
			return pHead;
		RandomListNode* p = pHead;
		RandomListNode* cHead = new RandomListNode(pHead->label);
		RandomListNode* q = cHead;
		p = p->next;
		while (p){
			q->next = new RandomListNode(p->label);
			q = q->next;
			p = p->next;
		}
		p = pHead;
		q = cHead;
		RandomListNode* pp = pHead;
		RandomListNode* qq = cHead;
		while (p){
			pp = pHead;
			qq = cHead;
			while (pp){
				if (pp == p->random)
					q->random = qq;
				pp = pp->next;
				qq = qq->next;
			}
			p = p->next;
			q = q->next;
		}
		return cHead;
	}
};