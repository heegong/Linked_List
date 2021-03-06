#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>


typedef struct {
	int value;
	struct Node* next;
} Node;



int makeNode() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->value = 0;										// head에 value는 리스트의 길이로 사용될꺼임
	head->next = NULL;
	return head;
}


int appendNode(Node* head, int append_num) {
	head->value++;														//  head의 value 즉 길이에 1을 더해줌


	Node* append_node = (Node*)malloc(sizeof(Node));
	append_node->value = append_num;
	append_node->next = NULL;

	Node* curr = head;

	while (1) {
		if (curr->next == NULL) {
			curr->next = append_node;
			return 0;
		}
		curr = curr->next;
	}
	return 0;
}


int appendArrayNode(Node* head, int* array, int size_array) {		// 흐음 head를 안쓰고 가능할려나.. 생각해보자..
	int i;

	Node* append_array_node = (Node*)malloc(sizeof(Node));
	Node* curr = append_array_node;


	for (i = 0; i < size_array; i++) {
		Node* qu = (Node*)malloc(sizeof(Node));
		qu->value = array[i];
		curr->next = qu;
		curr = curr->next;
	}
	curr->next = NULL;


	curr = head;
	while (1) {
		if (curr->next == NULL) {
			curr->next = append_array_node->next;

			free(append_array_node);
			break;
		}
		curr = curr->next;
	}


	head->value += size_array;
	return 0;
}


int insertNode(Node* head, int value, int index) {					// 구현하는데 머리 좀 썻음...;;; ㅎㅎ
	Node* insert_node = (Node*)malloc(sizeof(Node));
	insert_node->value = value;


	Node* curr = head;
	int index_plus = 0;
	while (1) {
		if (index_plus++ == index) {
			insert_node->next = curr->next;
			curr->next = insert_node;
			break;
		}
		curr = curr->next;
	}
	head->value++;												// insert했으니깐 길이 늘려주기
	return 0;
}


int removeNode(Node* head, int index) {
	Node* curr = head;

	int index_plus = 0;
	while (1) {
		if (index_plus++ == index) {
			Node* next = curr->next;
			curr->next = next->next;
			free(next);
			break;
		}
		curr = curr->next;
	}

	head->value--;								// remove 했으니깐 길이 하나 줄여주기
	return 0;
}


int indexNode(Node* head, int index) {
	Node* curr = head->next;

	int index_plus = 0;
	while (1) {
		if (index_plus++ == index) {
			return curr->value;
		}
		curr = curr->next;
	}

	return 0;
}


int findNode(Node* head, int num) {
	Node* curr = head->next;

	int index_plus = 0;
	while (1) {
		if (curr->value == num) {
			return index_plus;
		}
		index_plus++;
		curr = curr->next;
	}

	return -1;
}



int lenNode(Node* head) {
	return head->value;
}


int printNode(Node* head) {
	Node* curr = head->next;
	while (curr != NULL) {
		printf("%d\n", curr->value);
		curr = curr->next;
	}
	return 0;
}


int freeNode(Node* head) {
	Node* curr = head->next;
	while (curr != NULL) {
		Node* next = curr->next;
		free(curr);
		curr = next;
	}
	return 0;
}



int main() {
	Node* head = makeNode();

	int array[5] = { 1,2,3,4,5 };

	appendArrayNode(head, array, sizeof(array) / sizeof(int) );
	appendNode(head, 6);

	/*appendNode(head, 1);
	appendNode(head, 2);
	appendNode(head, 4);
	insertNode(head, 3, 2);
	removeNode(head, 0);*/


	printNode(head);

	printf("\n\nindexNode : %d\n", indexNode(head, 0));
	printf("\n\nfindNode : %d\n", findNode(head, 1));
	printf("\n\nlenNode : %d\n", lenNode(head));

	freeNode(head);
}