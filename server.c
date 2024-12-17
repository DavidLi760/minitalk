/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:56:10 by davli             #+#    #+#             */
/*   Updated: 2024/12/17 18:50:20 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	byte = 0;
int				bit_count = 0;

void	handler(int signum)
{
    if (signum == SIGUSR1)
	{
        byte &= ~(1 << bit_count);
	}
	else if (signum == SIGUSR2)
	{
        byte |= (1 << bit_count);
    }

    bit_count++;

    if (bit_count == 8)
	{
        write(1, &byte, 1);
        bit_count = 0;
        byte = 0;
    }
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error :\n Couldn't install signal handler.\n");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error :\n Couldn't install signal handler.\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
