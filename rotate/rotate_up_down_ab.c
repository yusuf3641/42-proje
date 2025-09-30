#include "push_swap.h"

void	rotate_once(t_stack *s)
{
	t_node	*n;

	if (!s || s->size < 2)
		return ;
	n = pop_front(s);
	push_back(s, n);
}
void	op_ra(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	rotate_once(a);
	write(1, "ra\n", 3);
}
void	op_rb(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	rotate_once(b);
	write(1, "rb\n", 3);
}
void	op_rr(t_stack *a, t_stack *b)
{
	int	did_any;

	did_any = 0;
	if (a && a->size >= 2)
	{
		did_any = 1;
		rotate_once(a);
	}
	if (b && b->size >= 2)
	{
		did_any = 1;
		rotate_once(b);
	}
	if (did_any == 1)
		write(1, "rr\n", 3);
}
