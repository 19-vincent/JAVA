#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

//��� ����� ��
struct node {
	int number;
	struct node* left;
	struct node* right;
};

//Ʈ���� ���ֱ�.
void freeTree(struct node* tree) {

	if (tree == NULL) {
		return;
	}

	freeTree(tree->left);
	freeTree(tree->right);
	free(tree);
}



//��Ʈ�ް�  �� 3�� �޾ƿ���
void addson(struct node* tree, int value1, int value2, int value3) {
	//���� ����ִ°� �޾ƿ��� �״�� ����
	if (tree == NULL) {
		return;
	}
	//���� ������ �ϴ� �߰��� �ֱ�.
	struct node* leftchild = (struct node*)malloc(sizeof(struct node));
	struct node* rightchild = (struct node*)malloc(sizeof(struct node));
	//������ ����, ������ �ڽĿ��ٰ� �� �־��ֱ�.
	leftchild->number = value2;
	rightchild->number = value3;
	//�ϴ� �����´� null������
	leftchild->left = NULL;
	leftchild->right = NULL;
	rightchild->left = NULL;
	rightchild->right = NULL;

	//Ʈ���� ������ ���� ��� 1�ϋ�
	if (tree->number == value1) {
		//�����Ͱ��� 0�� �ǹ����� ���ֹ�����
		if (value2 == 0) {
			tree->left = NULL;
			free(leftchild);
		}
		//�ƴϸ� ���� �ڽĿ� �߰��Ѵ�.
		else {
			tree->left = leftchild;
		}
		//������� 0�� �ǹ��Ӹ� ���ֹ�����
		if (value3 == 0) {
			tree->right = NULL;
			free(rightchild);
		}
		//�ƴϸ� ������ �ڽĿ� �߰��Ѵ�.
		else {
			tree->right = rightchild;
		}
	}
	//���࿡ ����Ⱑ ���� �ȸ����� �׳� �� �����Ѵ�.
	else {
		free(leftchild);
		free(rightchild);
	}

	addson(tree->left, value1, value2, value3);
	addson(tree->right, value1, value2, value3);
}


//���� ã�� �Լ��̴�.
void search(struct node* root, char tree[100]) {
	//�ϴ� �ǲ���� ���
	printf(" %d", root->number);
	for (int i = 0; i < strlen(tree); i++) {
		//���࿡ r�� ������ ���������� ��ĭ ��������
		if (tree[i] == 'R') {
			root = root->right;
		}
		//���࿡ l�� ������ �������� ��ĭ ��������
		else if (tree[i] == 'L') {
			root = root->left;
		}
		else {
			return;
		}
		//����ع�����.
		printf(" %d", root->number);
	}
	printf("\n");
}
void main() {

	int nodeNumber, value1, value2, value3, searchNumber;
	struct node* root;
	struct node* tree = (struct node*)malloc(sizeof(struct node));
	char searchInfomation[100];
	root = tree;
	//��ó�� ��� ���� ����� �˷��ֱ�.
	scanf("%d", &nodeNumber);

	for (int i = 0; i < nodeNumber; i++) {
		scanf("%d", &value1);
		scanf("%d", &value2);
		scanf("%d", &value3);
		//���ָ� ó�� �޾����� ����� ���°�.
		if (i == 0) {
			struct node* leftchild = (struct node*)malloc(sizeof(struct node));//���� ����� ����.
			struct node* rightchild = (struct node*)malloc(sizeof(struct node));//������ ����� ����.
			//���� ������ ���� ��ݹ��� ������ �־� ����.
			tree->number = value1;
			leftchild->number = value2;
			rightchild->number = value3;
			//�ϴ� ���� ������ ��δ� null�� ����� ���� ���� �غ���.
			leftchild->left = NULL;
			leftchild->right = NULL;
			rightchild->left = NULL;
			rightchild->right = NULL;
			//�����ڽ��� 0�� �ƴϸ� ��Ʈ�� �ִ´�.
			if (value2 != 0) {
				root->left = leftchild;
			}
			//�ƴϸ� �����ϰ�
			else {
				free(leftchild);
			}
			//���� ������ �ڽ��� 0 �� �ƴϸ� ��Ʈ�� �����ʿ� �־���´�.
			if (value3 != 0) {
				root->right = rightchild;
			}
			//�ƴϸ� �����ع�����.
			else {
				free(rightchild);
			}
		}
		//ù����°�� �ƴϸ� add�ϴ� �Լ��� ȣ���ع�����.
		else {
			addson(root, value1, value2, value3);
		}

	}
	//�ٳ������� Ž��Ƚ�� �޾ƹ�����
	scanf("%d", &searchNumber);

	for (int i = 0; i < searchNumber; i++) {
		getchar();
		scanf("%s", searchInfomation);
		search(root, searchInfomation);
	}
	//�������� �����Ѵ�.
	freeTree(root);

}