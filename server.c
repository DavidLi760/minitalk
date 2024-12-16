/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:56:10 by davli             #+#    #+#             */
/*   Updated: 2024/12/16 18:56:15 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main()
{
	pid_t	pid;
	struct sigaction	sa;
	
	sa.sa_handlet = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	while (1)
		pause();
	return (0);
}
