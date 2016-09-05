/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   su_head.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clucet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/22 09:49:36 by clucet            #+#    #+#             */
/*   Updated: 2013/09/24 16:35:02 by mpotie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SU_HEAD_H
# define	SU_HEAD_H

void	ft_putchar(char	c);
void	ft_putstr(char	*str);
void	board_resolve(void);
void	board_print(void);
int		board_input(int argc, char **argv);
int		board_complete(void);
int		line_rule(int n, int lin);
int		column_rule(int n, int col);
int		square3x3_rule(int n, int lin, int col);
int		try_1value(int n, int lin, int col);
void	try_9values(int lin, int col);

extern int g_board[9][9];

#endif /* !SU_HEAD_H */
