/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:51:23 by elias             #+#    #+#             */
/*   Updated: 2023/01/19 11:01:14 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_struct_init(t_args *args)
{
	args->prompt = "\e[36;1mminishell\e[32m ➜\e[0m ";
	args->exit_code = 0;
	args->infile = 0;
	args->outfile = 1;
	args->i = 0;
	args->j = 0;
	return (0);
}
