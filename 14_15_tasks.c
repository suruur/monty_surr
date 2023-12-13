#include "main.h"

/* stack_t *head = NULL; */

/**
 * queue - Do nothing
 * Return: void
 */

void queue(stack_t **h)
{
	stack_t *tmp;

	if (*h == NULL || (*h)->next == NULL)
	{
		return ();
	}
	tmp = *h;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->prev->next = NULL;
	tmp->next = NULL;


	/* Updating head to point to the front of the queue */
	tmp->next = *h;
	(*h)->prev = tmp;
	*h = tmp;

}

/**
 * rotr - rotl opcode
 * @stk: Stack
 * @l: Line
 * Return: void
 */
void rotr(stack_t **stk, int l)
{
	(void)l;
	stack_t *tmp, *curr;

	if (*stk != NULL && (*stk)->next != NULL)
	{
	}

	curr = *stk;

	while(curr->next != NULL)
	{
		curr = curr->next;
	}
	
	tmp = curr->prev;
	tmp->next = NULL;
	curr->prev = NULL;
	curr->next = *stk;
	(*stk)->prev = curr;

	*stk = curr;
	
}
