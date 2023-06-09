/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:01:43 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/05/16 14:48:02 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_new_value(char *value1, char *value2, int add)
{
	char	*new_value;

	if (add)
		new_value = ft_strjoin(value1, value2);
	else
		new_value = ft_strdup(value2);
	free(value2);
	return (new_value);
}

int	ft_add_var_to_envp(t_args *args, char *name, char *value, int add)
{
	t_envp	*envp;
	t_envp	*new;

	envp = args->envp;
	while (envp && ft_strcmp(name, envp->name))
		envp = envp->next;
	if (!envp)
	{	
		new = ft_envpnew(name, value, args->equal);
		if (!new)
			return (ft_error(99));
		ft_envpadd_back(&args->envp, new);
		return (0);
	}
	free(name);
	value = ft_get_new_value(envp->value, value, add);
	if (!value)
		return (ft_error(99));
	free(envp->value);
	envp->value = value;
	envp->equal = args->equal;
	return (0);
}

static void	ft_print_export(t_args *args)
{
	t_envp	*envp;

	envp = args->envp;
	while (envp)
	{
		if (!envp->equal)
			printf("declare -x %s\n", envp->name);
		else
			printf("declare -x %s=\"%s\"\n", envp->name, envp->value);
		envp = envp->next;
	}
}

static void	ft_free_name_value(char *name, char *value)
{
	free(name);
	free(value);
}

int	ft_export(t_args *args, char **cmd)
{
	char	*var_name;
	char	*var_value;
	int		i;
	int		add;

	i = 0;
	add = 0;
	if (!cmd[i + 1])
		ft_print_export(args);
	while (cmd[++i])
	{
		var_name = ft_get_var_name(cmd[i], &add);
		if (!var_name)
			return (1);
		var_value = ft_get_var_value(args, cmd[i]);
		if (!var_value)
			return (free(var_name), 1);
		if (*var_name && ft_add_var_to_envp(args, var_name, var_value, add))
			return (1);
		else if (!*var_name)
			ft_free_name_value(var_name, var_value);
	}
	return (0);
}
