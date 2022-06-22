#ifndef __FACTORS_H__
#define __FACTORS_H__

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * struct listint_s - list of primary factors
 * @n: prime factor digit
 * @next: next item on the list
 * Description: Singly linked list node
 */
typedef struct list_s
{
	unsigned long long int n;
	struct list_s *next;
} list_t;

void free_list(list_t *head);
list_t *insert_node(list_t **head, unsigned long long int n);
list_t *insert_node_start(list_t **head, unsigned long long int n);
ssize_t print_list(list_t *head);
list_t *factors(unsigned long long int num);
void print_results(char *number, list_t *head);

#endif /* __FACTORS_H__ */
