/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   su_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clucet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/22 09:59:37 by clucet            #+#    #+#             */
/*   Updated: 2013/09/24 16:36:11 by mpotie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "su_head.h"

/* The Sudoku board global variable */

int	g_board[9][9] = {{0}};

int	error()
{
	ft_putstr("Erreur\n");
	return (-1);
}

int	board_count()
{
	int	lin;
	int	col;
	int	count;

	count = 0;
	lin = 0;
	while (lin < 9)
	{
		col = 0;
		while (col < 9)
		{
			if (g_board[lin][col] != 0)
				count++;
			col++;
		}
		lin++;
	}
	return (count);
}

int main(int argc, char **argv)
{
	if (board_input(argc-1, &argv[1]))
		return (error());
	if (board_count() < 17)
		return (error());
	board_resolve();
	if (!board_complete())
		return (error());
	board_print();
	return (0);
}
