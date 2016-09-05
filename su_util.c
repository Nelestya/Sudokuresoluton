/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   su_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clucet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/22 10:28:28 by clucet            #+#    #+#             */
/*   Updated: 2013/09/24 14:32:30 by clucet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "su_head.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	board_print()
{
	int	lin;
	int	col;

	lin = 0;
	while (lin < 9)
	{
		col = 0;
		while (col < 9)
		{
			ft_putchar(g_board[lin][col] + '0');
			if (col < (9-1))
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		lin++;
	}
}

int		board_input(int linc, char **linv)
{
	int	lin;
	int	col;
	char c;

	if (linc != 9)
		return (-1);
	lin = 0;
	while (lin < 9)
	{
		col = 0;
		while (col < 9)
		{
			c = linv[lin][col];
			if (c >= '1' && c <= '9' && try_1value(c - '0', lin, col))
				g_board[lin][col] = c - '0';
			else if (c != '.')
				return (-1);
			col++;
		}
		lin++;
	}
	return (0);
}

int	board_complete()
{
	int	lin;
	int	col;

	lin = 0;
	while (lin < 9)
	{
		col = 0;
		while (col < 9)
		{
			if (g_board[lin][col] == 0)
				return (0);
			col++;
		}
		lin++;
	}
	return (1);
}
