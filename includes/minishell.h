/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:11:58 by elias             #+#    #+#             */
/*   Updated: 2023/05/02 13:47:50 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <limits.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

# include "exec.h"
# include "builtins.h"
# include "parsing.h"
# include "utils.h"

typedef struct s_envp
{
	char			*name;
	char			*value;
	int				equal;
	struct s_envp	*next;
}	t_envp;

typedef struct s_args
{
	t_list	*stack;
	t_envp	*envp;
	char	**char_envp;
	t_list	*command_list;
	char	*prompt;
	pid_t	*pid_tab;
	int		*close_tab;
	int		exit_code;
	int		infile;
	int		outfile;
	int		fdd;
	int		size;
	// int		last_err;
	int		equal;
	int		last;
}	t_args;

int	last_errno;

t_envp	*ft_envpnew(char *name, char *value, int equal);
t_envp	*ft_envplast(t_envp *envp);
void	ft_envpadd_back(t_envp **lst, t_envp *new);
int		ft_envpsize(t_envp *envp);

#endif
