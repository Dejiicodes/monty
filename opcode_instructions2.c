#include "monty.h"

/**
 * _queue - this sets the format of the data to a queue (FIFO)
 * @doubly: the head of the linked list
 * @cline: the line number;
 * Return: no return
 */

void _queue(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 0;
}

/**
 * _stack - this sets the format fo the data to a stack (LIFO)
 * @doubly: the head of the linked list
 * @cline: the line number;
 * Return: no return
 */

void _stack(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;

	vglo.lifo = 1;
}

/**
 * _add - this adds the top two elements of the stack
 * @doubly: the head of the linked list
 * @cline: the line number;
 * Return: no return
 */

void _add(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _nop - this does not do anything
 * @doubly: the head of the linked list
 * @cline: the line number;
 * Return: no return
 */

void _nop(stack_t **doubly, unsigned int cline)
{
	(void)doubly;
	(void)cline;
}

/**
 * _sub - this subtracts the top element to the second top element of the stack
 * @doubly: the head of the linked list
 * @cline: the line number;
 * Return: no return
 */

void _sub(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", cline);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n -= (*doubly)->n;
	_pop(doubly, cline);
}
