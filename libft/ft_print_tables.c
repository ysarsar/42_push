/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:09:57 by ommadhi           #+#    #+#             */
/*   Updated: 2019/12/21 14:27:57 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_tables(char **tabl)
{
	int i;

	i = 0;
	while (tabl[i] != NULL)
	{
		ft_putstr(tabl[i]);
		ft_putchar('\n');
		i++;
	}
}
