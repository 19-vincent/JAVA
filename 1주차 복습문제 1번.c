#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

//��带 �����ϴ� �� �����.
typedef struct Node {
	char elem; // ����
	struct Node* prev;
	struct Node* next;
}Node;

Node* Head;
Node* Trail;


//�� �Լ��� ���� �������ش�.
void linkedHeadTrail();
Node* CreateNode(char e);
void DestroyNode(Node* NewNode);
int AddNode(Node* list, int r, char e);
int DeleteNode(Node* list, int r);
char GetNode(Node* list, int r);
void PrintNode(Node* list);

int main() {
	int N, r;
	char menu, e;
	//�ϴ� ������ Ʈ���� ��带 ������ѳ��´�.
	linkedHeadTrail();

	scanf("%d", &N); getchar();

	//ù��°�� ���ڸ� �޾Ƽ� � �ൿ�� �ؾ����� �����Ѵ�.
	for (int i = 0; i < N; i++) {
		scanf("%c", &menu); getchar();

		//A�� ADD�� �Ѵ�.
		if (menu == 'A') {
			scanf("%d %c", &r, &e); getchar();
			AddNode(Head, r, e);
		}
		//D�� Delete�� �Ѵ�.
		if (menu == 'D') {
			scanf("%d", &r); getchar();
			DeleteNode(Head, r);
		}
		//G�� get�� �Ѵ�.
		if (menu == 'G') {
			scanf("%d", &r); getchar();

			if (GetNode(Head, r) != -1)
				printf("%c\n", GetNode(Head, r));
		}
		//p�� print�� �Ѵ�.
		if (menu == 'P') {
			PrintNode(Head);
		}
	}

	Node* p = Head;
	Node* tmp = NULL;

	while (p != Trail) {
		tmp = p->next;
		DestroyNode(p);
		p = tmp;
	}
}
//�Ӹ��� ������ �����Ű�� �Լ��̴�.
void linkedHeadTrail() {
	Head = (Node*)malloc(sizeof(Node));
	Trail = (Node*)malloc(sizeof(Node));
	//����� �յڸ� ��������, ������ �յڸ� �Ӹ�����
	Head->next = Trail;
	Head->prev = Trail;
	Trail->prev = Head;
	Trail->next = Head;
}
//���ο� ��带 ���� �־ �����
Node* CreateNode(char e) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->elem = e;
	NewNode->prev = NULL;
	NewNode->next = NULL;

	return NewNode;
}
//��带 ������Ű�� �Լ�
void DestroyNode(Node* NewNode) {
	free(NewNode);
}


//��带 �߰��ϴ� �Լ�
int AddNode(Node* list, int r, char e) {
	Node* NewNode = CreateNode(e);
	Node* tmp = list;

	//��� �־���ϴ��� ���ؼ� �ִµ� �ʰ��ϸ� �����޼��� ��
	for (int i = 0; i < r - 1; i++) {
		tmp = tmp->next;
		if (tmp == Trail) {
			printf("invalid position\n");
			return -1;
		}
	}
	//���μ��� �������ֱ�
	NewNode->next = tmp->next;
	tmp->next = NewNode;
	NewNode->next->prev = NewNode;
	NewNode->prev = tmp;
}

//��带 �����ϴ� �Լ�
int DeleteNode(Node* list, int r) {
	Node* tmp = list;

	//�̰͵� ���μ��� �� �����ֱ�
	for (int i = 0; i < r; i++) {
		tmp = tmp->next;
		if (tmp == Trail) {
			printf("invalid position\n");
			return -1;
		}
	}
	//�굵 ���μ��� �����ֱ�
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;

	DestroyNode(tmp);
}
//�Լ��� get�ϱ�
char GetNode(Node* list, int r) {
	Node* tmp = list;

	if (r == 0) {
		printf("invalid position\n");
		return -1;
	}
	//�̰͵� ���� �ʰ��ϸ� �����޽��� ������
	for (int i = 0; i < r; i++) {
		tmp = tmp->next;
		if (tmp == Trail) {
			printf("invalid position\n");
			return -1;
		}
	}

	return tmp->elem;
}
//��带 ����Ʈ �ϱ�
void PrintNode(Node* list) {
	Node* tmp = list;

	while (1) {
		tmp = tmp->next;
		if (tmp == Trail)
			break;
		printf("%c", tmp->elem);
	}

	printf("\n");
}
