/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 08:34:52 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/11 20:03:09 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack *s, t_node *n)
{
	if (!s || !n)
		return ;
	n->prev = NULL;
	n->next = s->up;
	if (s->up)
		s->up->prev = n;
	s->up = n;
	if (s->size == 0)
		s->last = n;
	s->size += 1;
}

t_node	*pop_front(t_stack *s)
{
	t_node	*out;

	if (!s || s->size == 0)
		return (NULL);
	out = s->up;
	s->up = out->next;
	if (s->up)
		s->up->prev = NULL;
	else
		s->last = NULL;
	out->prev = NULL;
	out->next = NULL;
	s->size -= 1;
	return (out);
}

void	push_back(t_stack *s, t_node *n)
{
	if (!s || !n)
		return ;
	n->next = NULL;
	n->prev = s->last;
	if (s->last)
		s->last->next = n;
	else
		s->up = n;
	s->last = n;
	s->size += 1;
}

t_node	*pop_back(t_stack *s)
{
	t_node	*out;

	if (!s || s->size == 0)
		return (NULL);
	out = s->last;
	s->last = out->prev;
	if (s->last)
		s->last->next = NULL;
	else
		s->up = NULL;
	out->prev = NULL;
	out->next = NULL;
	s->size -= 1;
	return (out);
}

void	init_and_fill_stack(t_stack *a, int *out, int *idx, int n)
{
	t_node	*node;
	int		i;

	i = 0;
	while (n > i)
	{
		node = node_new(out[i]);
		node->index = idx[i];
		push_back(a, node);
		i++;
	}
}
