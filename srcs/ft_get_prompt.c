/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:35:20 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/01/24 14:24:31 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_prompt(char *cwd) // TODO segfault with env -i
{
	int		i;
	char	*tmp;
	char	*tmp2;

	if (cwd != NULL)
	{
		i = ft_strlen(cwd);
		while (cwd[i] != '/')
			i--;
		if (!ft_strcmp(cwd, getenv("HOME")))
			cwd = ft_strjoin(" ⚡\e[46;90m\ue0b0 ", "~"); // TODO wtf qu'est-ce que t'as fais Tibo 
		else
			cwd = ft_strjoin(" ⚡\e[46;90m\ue0b0 ", cwd + i + 1);
 		tmp = getenv("LOGNAME");
 		tmp2 = ft_strjoin("\001\e[100;36m ", tmp);
 		tmp = ft_strjoin(tmp2, cwd);
 		free(tmp2);
 		free(cwd);
 		cwd = ft_strjoin(tmp, " \001\e[36;49m\002\ue0b0\001\e[0m\002 ");
 		free(tmp);
 		return (cwd);
 	}
 	return (NULL);
}

/*char	*ft_get_prompt(char *cwd)
{
	int		i;
	char	*tmp;

	if (cwd != NULL)
	{
		i = ft_strlen(cwd);
		while (cwd[i] != '/')
			i--;
		if (!ft_strcmp(cwd, getenv("HOME")))
			cwd = ft_strjoin(" ⚡ ", "~");
		else
			cwd = ft_strjoin(" ⚡ ", cwd + i + 1);
		tmp = getenv("LOGNAME");
		tmp = ft_strjoin(tmp, cwd);
		free(cwd);
		cwd = ft_strjoin(tmp, " ➜  ");
		free(tmp);
		return (cwd);
	}
	return (NULL);
}*/
