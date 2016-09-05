/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   su_rules.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clucet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/22 10:18:29 by clucet            #+#    #+#             */
/*   Updated: 2013/09/24 16:37:52 by mpotie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "su_head.h"

int		line_rule(int n, int lin)
{
	int c;

	c = 0;
	while (c < 9)
	{
		if (g_board[lin][c] == n)
			return (0);
		c++;
	}
	return (1);
}

int		column_rule(int n, int col)
{
	int r;

	r = 0;
	while (r < 9)
	{
		if (g_board[r][col] == n)
			return (0);
		r++;
	}
	return (1);
}

int		square3x3_rule(int n, int lin, int col)
{
	int	r;
	int	c;

	r = 3 * (lin / 3);
	while (r < (3 * (lin / 3) + 3))
	{
		c = 3 * (col / 3);
		while (c < (3 * (col / 3) + 3))
		{
			if (g_board[r][c] == n)
				return (0);
			c++;
		}
		r++;
	}
	return (1);
}
