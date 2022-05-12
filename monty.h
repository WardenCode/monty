#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - Struct for a global variable
 * @tokens: Tokens of command.
 * @stack: Pointer to the stack.
 * @fd_monty: File Descriptor of the Monty file.
 * @command: Pointer to a line of the Monty file.
 * @line_num: Number of line of the Monty file.
 * @quantity: Cuantity of nodes.
 *
 * Description: This struct is for free the command
 * and close the Monty File
 */
typedef struct global_s
{
	char **tokens;
	stack_t *stack;
	FILE *fd_monty;
	char *command;
	unsigned int line_num;
	int quantity;
} global_t;

extern global_t global;

/*Utils*/
char *str_concat(char *s1, char *s2);
void print_tokens(char **tokens);
int is_a_num(char *n);

/*Clean*/
int total_malloc(char *command);
void free_tokens(char **tokens);
int _isdigit(int c);
char **tokenizer(char *input);
void free_cases(int flag);

/*Core*/
size_t print_dlistint(stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);
/*stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index);*/
/*int sum_dlistint(stack_t *head);*/
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);

/*Opcodes*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

#endif /*_MONTY_H_*/
