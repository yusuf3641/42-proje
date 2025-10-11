/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:37:09 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/11 12:30:35 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_new(int value)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->index = 0;
	n->prev = NULL;
	n->next = NULL;
	return (n);
}

t_stack	*stack_init(char name)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(*s));
	if (!s)
		return (NULL);
	s->name = name;
	s->size = 0;
	s->last = NULL;
	s->up = NULL;
	return (s);
}

void	stack_clear(t_stack *s)
{
	t_node	*cur;
	t_node	*next;

	if (!s)
		return ;
	cur = s->up;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	s->up = NULL;
	s->last = NULL;
	s->size = 0;
	free(s);
}
