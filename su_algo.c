/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   su_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clucet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/22 10:04:49 by clucet            #+#    #+#             */
/*   Updated: 2013/09/24 16:28:26 by mpotie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "su_head.h"

void	board_resolve()
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
			{
				try_9values(lin, col);
				return ;
			}
			col++;
		}
		lin++;
	}
}

int		try_1value(int n, int lin, int col)
{
	if (!line_rule(n, lin))
		return (0);
	if (!column_rule(n, col))
		return (0);
	if (!square3x3_rule(n, lin, col))
		return (0);
	return (1);
}

void	try_9values(int lin, int col)
{
	int	val;
	int	sav;

	val = 1;
	while (val <= 9)
	{
		if (try_1value(val, lin, col))
		{
			sav = g_board[lin][col];
			g_board[lin][col] = val;
			board_resolve();
			if (board_complete())
				return ;
			g_board[lin][col] = sav;
		}
		val++;
	}
}
