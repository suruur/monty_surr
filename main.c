#include "monty.h"

/**
 * push - push an element to top of stack
 * @head: pointer to beginning of stack
 * @num: integer to be added to stack
 */
void push(int num, stack_t *head)
{
	stack_t *stack = malloc(sizeof(stack_t));

	stack->next = stack->prev = head; /*works well for null head */
	if (head == NULL) /* empty stack */
	{
		stack->n = num;
		head = stack;
	}
	else /* stack not empty */
	{
		while (head != NULL)
		{
			stack->prev = head;
			head = head->next;
			stack->next = head->next;
		}
		stack->n = num;
		head = stack;
	}
}


/**
 * print_all - prints all elements of a listint_t list
 * @h: pointer to head of list
 */
void print_all(const stack_t *h)
{
	const stack_t *current = h;

	while (current != NULL)
	{
		printf("%i\n", current->n);
		current = current->next;
	}
}
/**
 * main - implement opcodes
 *
 * Return: 0 on success
 */
int main(void)
{
	char opcode[5];
	int value;
	int ln = 0;
	FILE *file = fopen("bytecodes/00.m", "r");

	if (file == NULL)
	{
		fprintf(stderr, "Unable to open file\n");
		return (EXIT_FAILURE);
	}
	for (; fscanf(file, "%s", opcode) != EOF; ln++)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &value) != 1)
			{
				fprintf(stderr,
					"L%d: usage: push integer\n", ln);
				return (EXIT_FAILURE);
			}
			push(value);
		}
		else if (strcmp(opcode, "pall") == 0)
			print_all();
		else
		{
			fprintf(stderr,
				"L%d: Unknown opcode: %s\n", ln, opcode);
			return (EXIT_FAILURE);
		}
	}
	fclose(file);
	return (0);
}
