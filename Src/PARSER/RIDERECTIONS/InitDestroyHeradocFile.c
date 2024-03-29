/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitDestroyHeradocFile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:33:03 by bbolat            #+#    #+#             */
/*   Updated: 2023/01/19 13:33:03 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Include/minishell.h"

void	close_heradoc_file(void)
{
	if (g_core.heradoc_fd > SSTDERR)
	{
		g_core.heradoc_fd = close(g_core.heradoc_fd);
		g_core.heradoc_fd = 0;
	}
}

void	open_heradoc_file(char	*create_mode)
{
	char	*heracoc_path;
	char	ptr[256];

	heracoc_path = NULL;
	own_strjoin(&heracoc_path, (char *)getcwd(ptr, 256));
	str_addchar(&heracoc_path, '/');
	own_strjoin(&heracoc_path, "heradoc");
	if (str_compare(create_mode, "READ"))
		g_core.heradoc_fd = open(heracoc_path, O_RDONLY, 0777);
	else
		g_core.heradoc_fd = open(heracoc_path,
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
	free(heracoc_path);
}
