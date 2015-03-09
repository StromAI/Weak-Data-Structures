#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct chainNode
{
	int data;
	struct chainNode *next;
} node;

node *
create()
{
	node *head, *p, *s;
	int x, cycle = 1;
	head = (node*)malloc(sizeof(node));
	p = head;
	while(cycle)
	{
		printf("please input the data:");
		scanf("%d",&x);
		if (x != 0)
		{
			s = (node*)malloc(sizeof(node));
			s->data = x;
			printf("%d\n",s->data);
			p->next = s;
			p = s;
		}
		else
			cycle = 0;
	}
	s = head;
	head = head->next;
	free(s);
	p->next = NULL;
	printf("\n 	yyy 	%d\n",head->data);
	return head;
}

int 
length(node *head)
{
	int n = 0;
	node *p;
	p = head;
	while (p != NULL)
	{
		p = p->next;
		n++;
	}
	return n;
}

void
printNode(node *head)
{
	node *p;
	int n;
	p = head;
	n = length(head);
	printf("These %d records are:\n", n);
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

node *
del(node *head, int num)
{
	node *p1, *p2;
	p1 = head;
	while(num != p1->data && p1->next != NULL)
	{
		p2 = p1; p1 = p1->next;
	}

	if (num == p1->data)
	{
		if (p1 == head)
		{
			head = p1->next;
			free(p1);
		}
		else
		{
			p2->next = p1->next;
			free(p1);
		}
	}
	else
		printf("Num %d not found\n", num);
	return head;
}

/* not good but could use ...*/
/* ok ok ... It's wrong  =.=  */
node *
insert(node *head, int num)
{
	node *p0, *p1, *p2;
	p1 = head;
	p0 = (node*)malloc(sizeof(node));
	p0->data = num;
	while (p0->data > p1->data && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p0->data <= p1->data)
	{
		if (head == p1)
		{
			p0->next = p1;
			head = p0;
		}
		else
		{
			p2->next = p0;
			p0->next = p1;
		}
	}
	else
	{
		p1->next = p0;
		p0->next = NULL;
	}
	return head;
}

node *
sort(node *head)
{
	node *p1, *p2, *p3;
	int n;
	int temp;
	n = length(head);

	if (head == NULL || head->next == NULL)
		return head;

	p1 = head;
	int j;
	for (j = 1; j < n; j++)
	{
		p1 = head;
		int i;
		for (i = 0; i < n - j; i++)
		{
			if (p1->data > p1->next->data)
			{
				temp = p1->data;
				p1->data = p1->next->data;
				p1->next->data = temp;
			}
			p1 = p1->next;
		}
	}
	return head;
}

node *
reverse(node *head)
{
	node *p1, *p2, *p3;

	if (head == NULL || head->next == NULL)
		return head;

	p1 = head;
	p2 = p1->next;
	while(p2)
	{
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}

	head->next = NULL;
	head = p1;
	return head;
}

int
main(void)
{
	node * head;
	head = create();
	printNode(head);
	head = del(head,2);
	/*printNode(head);
	head = insert(head,2);*/
	printNode(head);
	head = sort(head);
	printNode(head);
	head = reverse(head);
	printNode(head);
	exit(0);
}