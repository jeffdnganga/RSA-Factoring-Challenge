#include "factors.h"

int[] factors1(unsigned long long num)
{

}

/**
 * factors2 - gets the prime factors of a number
 * @num_str: the number in string format
 * Return: a linked list of prime factors of the number
 */

list_t *factors2(unsigned long long num)
{
	long long i = 2;
	list_t *list = NULL;

	while (num > 1)
	{
		if (num % i == 0)
		{
			insert_node_start(&list, i);
			num /= i;
		}
		else
			i++;
	}

	return (list);
}
