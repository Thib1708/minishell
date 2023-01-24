/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:24:09 by elias             #+#    #+#             */
/*   Updated: 2023/01/24 12:28:40 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_parsing(t_args *args)
{
	int	i;

	i = -1;
	if (!*args->command_list)
		return (1);
	if (ft_is_delimiter(*args->command_list) == '|')
		return (ft_error(9));
	while (args->command_list[++i])
	{
		if (ft_is_delimiter(args->command_list[i]) && \
			!args->command_list[i + 1])
			return (ft_error(11));
		if (ft_is_delimiter(args->command_list[i]) == '|' && \
			args->command_list[i + 1])
			if (ft_is_delimiter(args->command_list[i + 1]) == '|')
				return (ft_error(9));
		if (ft_is_redirect(args->command_list[i]) && \
			args->command_list[i + 1])
			if (ft_is_delimiter(args->command_list[i + 1]))
				return (ft_error(10));
	}
	return (0);
}

int	ft_check_command(t_args *args) // TODO fix for builtins
{
	int	i;

	i = -1;
	while (args->stack[++i])
		if (!ft_is_delimiter(args->stack[i][0]) && \
			!ft_get_path(args->stack[i][0]))
			return (ft_error(2));
	return (0);
}