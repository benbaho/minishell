/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:30:11 by bbolat            #+#    #+#             */
/*   Updated: 2023/01/19 13:30:11 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/minishell.h"
/*
	olusturulmus lexer bagli listesinde ki her nodeda bulunan
	sozcuklerin tipi belirlenir.
	bu olusturulan tiplerin karsiliklari "lexer.h"'da define edilmistir
	oradan karsiliklari gorulebilir ve kontrol islemleri
	orda define edilmis degiskenler uzerinden yapilabilir.
*/

void	classify(t_lexlist *lex_table)
{
	char	*metachars;

	if (!lex_table)
		return ;
	while (lex_table)
	{
		metachars = compare_metachars(lex_table->content);
		if (metachars)
			lex_table->type = (*metachars - 1) * ft_strlen(metachars);
		else
			lex_table->type = 0;
		lex_table = lex_table->next;
	}
}
