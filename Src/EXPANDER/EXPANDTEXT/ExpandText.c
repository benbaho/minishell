/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExpandText.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:29:56 by bbolat            #+#    #+#             */
/*   Updated: 2023/01/19 13:29:56 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Include/minishell.h"

void	expand_envs(char **dst, char *ptr)
{
	t_env	*copy_envs;

	copy_envs = g_core.env_table;
	while (copy_envs)
	{
		if (str_compare(ptr, copy_envs->env_name))
		{
			own_strjoin(dst, copy_envs->content);
			break ;
		}
		copy_envs = copy_envs->next;
	}
}

void	expand_order(char **dst, char **src)
{
	if (**src == *DOLLAR)
		expand_dollar(dst, src);
	else
		expand_envs(dst, "HOME");
}
