/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:50:26 by event04           #+#    #+#             */
/*   Updated: 2023/01/30 14:24:50 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_remove_quote(char *str)
{
	char	*new_str;
	int		i;
	int		size;

	i = -1;
	size = 0;
	while (str[++i])
		if (str[i] == '\'' || str[i] == '"')
			size++;
	if (size == 0)
		return (str);
	new_str = malloc(sizeof(char) * (ft_strlen(str) - size + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str != '\'' && *str != '"')
			new_str[i++] = *str;
		str++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static char	*ft_get_variable_size(t_args *args, char *str, int *size)
{
	char	*variable;
	char	*env;
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '"')
		i++;
	variable = ft_substr(str, 1, i++ - 1);
	if (!variable)
		return (NULL);
	env = ft_getenv(args, variable);
	if (env)
		*size += ft_strlen(getenv(variable));
	free(env);
	free(variable);
	str += i - 2;
	return (str);
}

static int	ft_get_size(t_args *args, char *str)
{
	int		size;

	size = 0;
	while (*str)
	{
		if (*str == '$')
		{	
			str = ft_get_variable_size(args, str, &size);
			if (!str)
				return (-1);
		}
		else
			size++;
		str++;
	}
	return (size);
}

#include <string.h> // TODO remove after creating ft_strcat


static char	*ft_current_var(t_args *args, char *new_str, char *str, int *size)
{
	char	*variable;
	char	*env;
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '"')
		i++;
	variable = ft_substr(str, 1, i++ - 1);
	if (!variable)
		return (NULL);
	env = ft_getenv(args, variable);
	if (env)
	{
		strcat(new_str, env); //TODO changer en ft_strcat
		*size += ft_strlen(env);
	}
	free(env);
	free(variable);
	str += i - 1;
	return (str);
}

char	*ft_replace_variable(t_args *args, char *new_str, char *str)
{
	int	size;

	size = 0;
	while (*str)
	{
		if (*str == '$')
		{
			str = ft_current_var(args, new_str, str, &size);
			if (!str)
				return (NULL);
			/*while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '"')
				i++;
			variable = ft_substr(str, 1, i++ - 1);
			if (!variable)
				return (NULL);
			if (getenv(variable))
			{
				strcat(new_str, getenv(variable)); //TODO changer en ft_strcat
				size += ft_strlen(getenv(variable));
			}
			free(variable);
			str += i - 1;*/
		}
		else
			new_str[size++] = *str++;
	}
	new_str[size] = '\0';
	return (new_str);
}

char	*ft_replace_env(t_args *args, char *str)
{
	char	*new_str;
	int		size;

	size = ft_get_size(args, str);
	if (size == -1)
		return (NULL);
	if (str[0] == '"' && str[ft_strlen(str) - 1] == '"')
	{
		size -= 2;
		str[ft_strlen(str) - 1] = '\0';
		str++;
	}
	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (NULL);
	while (size >= 0)
		new_str[size--] = '\0';
	new_str = ft_replace_variable(args, new_str, str);
	return (new_str);
}

int	ft_parse_quotes(t_args *args)
{
	char	*current;
	int		i;
	int		j;

	i = -1;
	while (args->stack[++i])
	{
		j = -1;
		while (args->stack[i][++j])
		{
			current = args->stack[i][j];
			if (current[0] != '\'' && \
				current[ft_strlen(current)] != '\'')
				current = ft_replace_env(args, current);
			if (!current)
				return (ft_error(99));
			current = ft_remove_quote(current);
			args->stack[i][j] = current;
			if (!args->stack[i][j])
				return (ft_error(99));
		}
	}
	return (0);
}
