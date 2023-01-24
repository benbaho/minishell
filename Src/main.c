/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:31:50 by bbolat            #+#    #+#             */
/*   Updated: 2023/01/22 04:42:29 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minishell.h"

void	init_core(char **env)
{
	fill_envs(env);
	set_metachars();
	g_core.exec_output = 0;
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	init_core(env);
	signal(SIGINT, signals);
	while (1)
	{
		g_core.cmd = readline("minishell-> ");
		lexer(); 
		expander();
		parser();
		executer();
		add_history(g_core.cmd);
		exit_signal_check();
		free_for_loop();
	}
	free_core();
}
