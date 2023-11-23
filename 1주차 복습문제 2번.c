#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

//노드 만드는 것
struct node {
	int number;
	struct node* left;
	struct node* right;
};

//트리를 없애기.
void freeTree(struct node* tree) {

	if (tree == NULL) {
		return;
	}

	freeTree(tree->left);
	freeTree(tree->right);
	free(tree);
}



//루트받고  값 3개 받아오기
void addson(struct node* tree, int value1, int value2, int value3) {
	//만약 비어있는거 받아오면 그대로 종료
	if (tree == NULL) {
		return;
	}
	//왼쪽 오른쪽 일단 추가해 주기.
	struct node* leftchild = (struct node*)malloc(sizeof(struct node));
	struct node* rightchild = (struct node*)malloc(sizeof(struct node));
	//생성한 왼쪽, 오른쪽 자식에다가 값 넣어주기.
	leftchild->number = value2;
	rightchild->number = value3;
	//일단 가지는다 null때려놔
	leftchild->left = NULL;
	leftchild->right = NULL;
	rightchild->left = NULL;
	rightchild->right = NULL;

	//트리의 데이터 값이 밸류 1일떄
	if (tree->number == value1) {
		//데이터값이 0이 되버리면 없애버리고
		if (value2 == 0) {
			tree->left = NULL;
			free(leftchild);
		}
		//아니면 왼쪽 자식에 추가한다.
		else {
			tree->left = leftchild;
		}
		//밸류값이 0이 되버ㅣ면 없애버리고
		if (value3 == 0) {
			tree->right = NULL;
			free(rightchild);
		}
		//아니면 오른쪽 자식에 추가한다.
		else {
			tree->right = rightchild;
		}
	}
	//만약에 꼭대기가 값이 안맞으면 그냥 다 삭제한다.
	else {
		free(leftchild);
		free(rightchild);
	}

	addson(tree->left, value1, value2, value3);
	addson(tree->right, value1, value2, value3);
}


//이제 찾는 함수이다.
void search(struct node* root, char tree[100]) {
	//일단 맨꼭대기 출력
	printf(" %d", root->number);
	for (int i = 0; i < strlen(tree); i++) {
		//만약에 r이 들어오면 오른쪽으로 한칸 가버리고
		if (tree[i] == 'R') {
			root = root->right;
		}
		//만약에 l이 들어오면 왼쪽으로 한칸 가버리고
		else if (tree[i] == 'L') {
			root = root->left;
		}
		else {
			return;
		}
		//출력해버린다.
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
	//맨처음 노드 개수 몇개인지 알려주기.
	scanf("%d", &nodeNumber);

	for (int i = 0; i < nodeNumber; i++) {
		scanf("%d", &value1);
		scanf("%d", &value2);
		scanf("%d", &value3);
		//아주맨 처음 받았을때 만들어 놓는것.
		if (i == 0) {
			struct node* leftchild = (struct node*)malloc(sizeof(struct node));//왼쪽 만들어 놓음.
			struct node* rightchild = (struct node*)malloc(sizeof(struct node));//오른쪽 만들어 놓음.
			//안의 데이터 값에 방금받은 값들을 넣어 놓음.
			tree->number = value1;
			leftchild->number = value2;
			rightchild->number = value3;
			//일단 왼쪽 오른쪽 모두다 null로 만들어 놓고 받을 준비함.
			leftchild->left = NULL;
			leftchild->right = NULL;
			rightchild->left = NULL;
			rightchild->right = NULL;
			//왼쪽자식이 0이 아니면 루트에 넣는다.
			if (value2 != 0) {
				root->left = leftchild;
			}
			//아니면 해제하고
			else {
				free(leftchild);
			}
			//만약 오른쪽 자식이 0 이 아니면 루트에 오른쪽에 넣어놓는다.
			if (value3 != 0) {
				root->right = rightchild;
			}
			//아니면 해제해버린다.
			else {
				free(rightchild);
			}
		}
		//첫번찌째가 아니면 add하는 함수를 호출해버린다.
		else {
			addson(root, value1, value2, value3);
		}

	}
	//다끝난다음 탐색횟수 받아버리고
	scanf("%d", &searchNumber);

	for (int i = 0; i < searchNumber; i++) {
		getchar();
		scanf("%s", searchInfomation);
		search(root, searchInfomation);
	}
	//다했으면 해제한다.
	freeTree(root);

}