#include <iostream>
using namespace std;

struct Node {
	char a;
	Node *left = nullptr;
	Node *right = nullptr;
};

Node *pNode;

void inputNode(int N) {
	pNode = new Node[N];
	char a, l, r;
	for (int i = 0; i < N; i++){
		pNode[i].a = 'A' + i;
	}
	for (int i = 0; i < N; i++){
		cin >> a >> l >> r;
		Node *pn = &pNode[a - 'A'];
		if (l == '.') pn->left = nullptr;
		else pn->left = &pNode[l -'A'];
		if (r == '.') pn->right = nullptr;
		else pn->right = &pNode[r -'A'];
	}
}
void preorder(Node *root) {
	if(root == nullptr){
		return;
	}
	cout << root->a;
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node *root) {
	if(root == nullptr){
		return;
	}
	inorder(root->left);
	cout << root->a;
	inorder(root->right);
}

void postorder(Node *root) {
	if(root == nullptr){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->a;
}

int main() {
	int N;
	cin >> N;
	inputNode(N);
	preorder(pNode);
	cout << '\n';
	inorder(pNode);
	cout << '\n';
	postorder(pNode);
	cout << '\n';
	delete []pNode;
	return 0;
}