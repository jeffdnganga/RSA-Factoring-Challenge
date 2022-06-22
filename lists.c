#include "factors.h"

/**
 * free_list - frees a linked list
 * @head: head
 * Return: nothing
 */

void free_list(list_t *head)
{
	list_t *next_node = NULL;

	while (head != NULL)
	{
		next_node = head->next;
		free(head);
		head = next_node;
	}
}

/**
 * insert_node_start - insert a node at the begining of a linked list
 * @head: head
 * @n: n
 * Return: new node
 */

list_t *insert_node_start(list_t **head, unsigned long long n)
{
	list_t *new_node = NULL;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	
	if (head == NULL)
		new_node->next = NULL;

	else
		new_node->next = *head;

	*head = new_node;
	return (new_node);
}

/**
 * insert_node_end - insert node at the end of the list
 * @head: head
 * Return: nothing
 */

list_t *insert_node_end(list_t **head, unsigned long long n)
{
	list_t *new_node = NULL, *last_node = NULL;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head != NULL)
	{
		last_node = *head; 
		while (last_node->next != NULL)
			last_node = last_node->next;

		last_node->next = new_node;
	}
	else
		*head = new_node;

	return (new_node);
}

/**
 * print_list - prints all the elements in a list
 * @h: linked list
 * Return: the number of nodes
 */

ssize_t print_list(list_t *head)
{
	list_t *temp = head;
	unsigned long long i = 0;

	while(temp != NULL)
	{
		printf("%llu\n", temp->n);
		i++, temp = temp->next;
	}

	return (i);
}
