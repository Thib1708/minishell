/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:21:53 by elias             #+#    #+#             */
/*   Updated: 2023/01/13 18:23:17 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_stack_size(t_args *args)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (args->command_list[i])
	{
		if (ft_get_path(args->command_list[i]))
		{
			while (args->command_list[i] \
					&& !ft_is_delimiter(args->command_list[i]))
				i++;
			count++;
		}
		if (args->command_list[i])
		{
			i++;
			count++;
		}	
	}
	return (count);
}

char	**ft_copy_stack(t_args *args, int i, int j)
{
	char	**instruction;
	int		i_tab;

	instruction = malloc(sizeof(char *) * (j - i + 1));
	if (!instruction)
		return (NULL);
	i_tab = 0;
	while (args->command_list[i] && i < j)
		instruction[i_tab++] = args->command_list[i++];
	instruction[i_tab] = NULL;
	return (instruction);
}

int	ft_init_stack(t_args *args)
{
	int	size;

	size = ft_get_stack_size(args);
	args->stack = malloc(sizeof(char **) * (size + 1));
	if (!args->stack)
		return (99);
	args->stack[size] = NULL;
	return (0);
}

int	ft_get_stack(t_args *args)
{
	int	i;
	int	j;
	int	i_stack;

	i = 0;
	j = 0;
	i_stack = ft_init_stack(args);
	if (i_stack)
		return (i_stack);
	while (args->command_list[j])
	{
		if (ft_get_path(args->command_list[j]) || !ft_strcmp(args->command_list[j], "exit"))
		{
			while (args->command_list[j] \
					&& !ft_is_delimiter(args->command_list[j]))
				j++;
			args->stack[i_stack++] = ft_copy_stack(args, i, j);
			i = j++;
			if (args->command_list[j - 1])
				args->stack[i_stack++] = ft_copy_stack(args, i, j);
			else
				return (0);
			if (!args->stack[i_stack - 1])
				return (99);
			i = j;
		}
		else
			return (2);
	}
	return (0);
}
