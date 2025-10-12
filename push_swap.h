/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuskaya <yuskaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:37:12 by yuskaya           #+#    #+#             */
/*   Updated: 2025/10/12 20:13:56 by yuskaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int				n;
	int				*idx;
}					t_data;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;

}					t_node;

typedef struct s_stack
{
	char			name;
	int				size;
	t_node			*up;
	t_node			*last;
}					t_stack;

t_node				*node_new(int value);
t_stack				*stack_init(char name);
void				stack_clear(t_stack *s);

void				push_front(t_stack *s, t_node *n);
t_node				*pop_front(t_stack *s);
void				push_back(t_stack *s, t_node *n);
t_node				*pop_back(t_stack *s);

void				swap_top2(t_stack *s);
void				op_sa(t_stack *a);
void				op_sb(t_stack *b);

void				op_pa(t_stack *a, t_stack *b);
void				op_pb(t_stack *a, t_stack *b);

void				rotate_once(t_stack *s);

void				op_ra(t_stack *a);
void				op_rb(t_stack *b);

void				rrotate_once(t_stack *s);
void				op_rra(t_stack *a);
void				op_rrb(t_stack *b);

int					is_sorted(t_stack *a);
void				sort_two(t_stack *a);
void				sort_three(t_stack *a);
void				sort_help_three(t_stack *a);
void				sort_four_five(t_stack *a, t_stack *b);
void				small_sort(t_stack *a, t_stack *b);
int					get_min_value(t_stack *stack);
int					find_pos(t_stack *a, int min);

int					*ps_make_indicates(int *out, int n);
int					ps_parse_args(char **argv, int **out, int *n);
int					ps_parse_string(char *str, int **out, int *n);

void				ps_strncpy(char *dst, char *src, int n);
char				*ps_allocate_word(char *str, int start, int end);
void				ps_free_partial_result(char **result, int count);
int					ps_count_words(char *str);
char				**ps_split(char *str, char c);
void				ps_free_split(char **split, int count);
void				ps_copy_ints(int *dst, const int *src, int n);
void				ps_sort_ints(int *a, int n);
void				while_loop(int *vals, int *sorted, int *idx, int n);

int					ps_has_dup(int *a, int n);
int					ps_atoi_strict(const char *s, int *out);

void				init_and_fill_stack(t_stack *a, int *out, int *idx, int n);
void				cleanup_resources(t_stack *a, t_stack *b, int *idx,
						int *out);
int					init_data_and_validate(char **argv, int **out,
						t_data *data);

void				bite_loop(t_stack *a, t_stack *b, int n);

int					ps_is_sorted(int *a, int n);
int					put_error(void);
void				ps_skip_delimiters(char *str, int *i, char c);
void				ps_skip_word(char *str, int *i, char c);
int					ps_next_word(char *str, char **out, int *i, char c);
char				**ps_split(char *str, char c);

#endif
