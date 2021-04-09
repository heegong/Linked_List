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

	appendNode(head, 1);
	appendNode(head, 2);
	appendNode(head, 4);
	insertNode(head, 3, 2);
	removeNode(head, 0);


	printNode(head);
	printf("\n\n%d\n", lenNode(head));

	freeNode(head);
}