#include "main.h"
/**
 * nop - Do nothing
 * Return: void
 */
void nop(void)
{
	/* Do nothing */
}
/**
 * add - add opcode
 * @stk: Stack pointer
 * @l: Line number
 * Return: void
 */
void add(stack_t *stk, l)
{
	int op1, op2;
	int sum = 0;

	if (stk == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty", l);
		exit(EXIT_FAILURE);
	}

	op1 = pop(stk);
	op2 = pop(stk);

	sum = op1 + op2;

	push(stk, sum);
}
/**
 * swap - swap opcode
 * @stk: Stack
 * @l: Line number
 * Return: void
 */
void swap(stack_t *stk, int l)
{
	int top1, top2;

	if (stk == NULL || stk->next == NULL)
	{
		fprintf(stderr, "L<%d>: can't swap, stack too short\n", l);
		exit(EXIT_FAILURE);
	}

	top1 = pop(stk);
	top2 = pop(stk);

	push(stk, top1);
	push(stk, top2);
}
/**
 * execute_op - execute opcode
 * @op: Opcode
 * @ln: Line
 * Return: void
 */
void execute_op(const char *op, int ln)
{
	if (strcmp(op, "add") == 0)
	{
		add(stack, ln);
	}
	else if (strcmp(op, "swap") == 0)
	{
		swap(stack, ln);
	}
	else if (strcmp(op, "nop") == 0)
	{
		nop();
	}
}
