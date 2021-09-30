#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};
void rotate(Node** head_ref, int k)
{
	if (k == 0)
		return;

	Node* current = *head_ref;
	int count = 1;
	while (count < k && current != NULL) {
		current = current->next;
		count++;
	}

	if (current == NULL)
		return;

	Node* kthNode = current;
	while (current->next != NULL)
		current = current->next;

	current->next = *head_ref;
	*head_ref = kthNode->next;
	kthNode->next = NULL;
}

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();

	new_node->data = new_data;

	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

int main(void)
{
	Node* head = NULL;

	for (int i = 60; i > 0; i -= 10)
		push(&head, i);

	cout << "Given linked list \n";
	printList(head);
	rotate(&head, 4);

	cout << "\nRotated Linked list \n";
	printList(head);

	return (0);
}
