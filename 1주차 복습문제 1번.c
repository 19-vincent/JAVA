#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

//노드를 생성하는 걸 만들기.
typedef struct Node {
	char elem; // 원소
	struct Node* prev;
	struct Node* next;
}Node;

Node* Head;
Node* Trail;


//쓸 함수를 먼저 선언해준다.
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
	//일단 헤드노드랑 트레일 노드를 연결시켜놓는다.
	linkedHeadTrail();

	scanf("%d", &N); getchar();

	//첫번째로 문자를 받아서 어떤 행동을 해야할지 선택한다.
	for (int i = 0; i < N; i++) {
		scanf("%c", &menu); getchar();

		//A면 ADD를 한다.
		if (menu == 'A') {
			scanf("%d %c", &r, &e); getchar();
			AddNode(Head, r, e);
		}
		//D면 Delete를 한다.
		if (menu == 'D') {
			scanf("%d", &r); getchar();
			DeleteNode(Head, r);
		}
		//G면 get을 한다.
		if (menu == 'G') {
			scanf("%d", &r); getchar();

			if (GetNode(Head, r) != -1)
				printf("%c\n", GetNode(Head, r));
		}
		//p면 print를 한다.
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
//머리와 꼬리를 연결시키는 함수이다.
void linkedHeadTrail() {
	Head = (Node*)malloc(sizeof(Node));
	Trail = (Node*)malloc(sizeof(Node));
	//헤드의 앞뒤를 꼬리에게, 꼬리의 앞뒤를 머리에게
	Head->next = Trail;
	Head->prev = Trail;
	Trail->prev = Head;
	Trail->next = Head;
}
//새로운 노드를 문자 넣어서 만들기
Node* CreateNode(char e) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->elem = e;
	NewNode->prev = NULL;
	NewNode->next = NULL;

	return NewNode;
}
//노드를 삭제시키는 함수
void DestroyNode(Node* NewNode) {
	free(NewNode);
}


//노드를 추가하는 함수
int AddNode(Node* list, int r, char e) {
	Node* NewNode = CreateNode(e);
	Node* tmp = list;

	//어디에 넣어야하는지 정해서 넣는데 초과하면 오류메세지 뜸
	for (int i = 0; i < r - 1; i++) {
		tmp = tmp->next;
		if (tmp == Trail) {
			printf("invalid position\n");
			return -1;
		}
	}
	//서로서로 연결해주기
	NewNode->next = tmp->next;
	tmp->next = NewNode;
	NewNode->next->prev = NewNode;
	NewNode->prev = tmp;
}

//노드를 제거하는 함수
int DeleteNode(Node* list, int r) {
	Node* tmp = list;

	//이것도 서로서로 다 맞춰주기
	for (int i = 0; i < r; i++) {
		tmp = tmp->next;
		if (tmp == Trail) {
			printf("invalid position\n");
			return -1;
		}
	}
	//얘도 서로서로 맞춰주기
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;

	DestroyNode(tmp);
}
//함수를 get하기
char GetNode(Node* list, int r) {
	Node* tmp = list;

	if (r == 0) {
		printf("invalid position\n");
		return -1;
	}
	//이것도 순서 초과하면 오류메시지 나오기
	for (int i = 0; i < r; i++) {
		tmp = tmp->next;
		if (tmp == Trail) {
			printf("invalid position\n");
			return -1;
		}
	}

	return tmp->elem;
}
//노드를 프린트 하기
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
