/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiantrin <hiantrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 06:01:14 by mrxy              #+#    #+#             */
/*   Updated: 2020/12/02 18:19:44 by hiantrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sh.h"

int			ft_is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int			ft_argslen(char **args)
{
	int i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int			ft_test(char **args, t_process *process)
{
	int		args_len;

	args_len = ft_argslen(args);
	if (args_len == 1)
		return (g_the_status = 1);
	if (args_len == 2)
		return (g_the_status = 0);
	if (args[1][0] == '-')
		return (g_the_status = test_file(args, process));
	else if (ft_strcmp(args[1], "!") == 0)
	{
		if (args_len > 3)
		{
			ft_putstr_fd("42sh: test: ", process->errorput);
			ft_putstr_fd(args[2], process->errorput);
			ft_putendl_fd(": unary operator expected", process->errorput);
		}
		return (g_the_status = 1);
	}
	else
		return (g_the_status = test_string(args, process));
}

int			test_file_complete(char **args, t_process *process)
{
	if (ft_strcmp(args[1], "-L") == 0)
		return (is_symlink(args[2]));
	else if (ft_strcmp(args[1], "-p") == 0)
		return (is_fifo(args[2]));
	else if (ft_strcmp(args[1], "-r") == 0)
		return (readable_by_owner(args[2]));
	else if (ft_strcmp(args[1], "-S") == 0)
		return (is_socket(args[2]));
	else if (ft_strcmp(args[1], "-s") == 0)
		return (file_not_empty(args[2]));
	else if (ft_strcmp(args[1], "-u") == 0)
		return (ft_setuid(args[2]));
	else if (ft_strcmp(args[1], "-w") == 0)
		return (writeable_by_owner(args[2]));
	else if (ft_strcmp(args[1], "-x") == 0)
		return (executable_by_owner(args[2]));
	else if (ft_strcmp(args[1], "-z") == 0)
		return (EXIT_FAILURE);
	error_test(args[1], process);
	return (2);
}

void		error_test(char *str, t_process *process)
{
	ft_putstr_fd("42sh: test: ", process->errorput);
	ft_putstr_fd(str, process->errorput);
	ft_putendl_fd(": unary operator expected", process->errorput);
}
