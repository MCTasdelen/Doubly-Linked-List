#include <stdio.h>
#include<stdlib.h>

struct Node {
	int x;
	struct Node* next;
	struct Node* prev;
};
struct Node* head;

void prepend( int x)
{
	struct Node* insert;
	insert = malloc(sizeof(struct Node));
	insert->x = x;
	if (head == NULL)
	{
		insert->next = NULL;
		insert->prev = NULL;
		head = insert;
		
	}
	else {
	head->prev = insert;
	insert->next = head;
	head = insert;
	}
	
	

}
void Print(struct Node* head)
{
	struct Node* temp = head;
	
	while (temp!= NULL)
	{
		printf("%d\n", temp->x);
		
		
		temp = temp->next;
	}
	
	
}

void Delete(int n)
{
	int flag = 0;
	struct Node* count = head;
	while (count!=NULL)
	{
		flag++;
		count = count->next;
	}
	if (n <= flag)
	{
		if (n == 1)
		{
			struct Node* temp = head;
			head = head->next;
			free(temp);
		}
		else {
			struct Node* temp = head;
			for (int i = 0; i < (n - 1); i++)
			{
				temp = temp->next;

			}
			temp->prev->next = temp->next;
			free(temp);


		}
	}
	else {
		printf("element count exceeded\n");
	}
}
int main()
{
	 head = NULL;
	 prepend( 5);
	prepend( 50);
	 prepend( 541);
	 prepend( 57);
	 prepend( 15);
	Print(head);
	int n;
	printf("enter position of delete:\n");
	
	scanf_s("%d", &n);
	Delete(n);
	printf("*******************\n");
	Print(head);
	

}

