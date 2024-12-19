/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:56:04 by davli             #+#    #+#             */
/*   Updated: 2024/12/19 18:17:14 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    handle(int signum)
{
    if (signum == SIGUSR1)
        ft_printf("1");
    else if (signum == SIGUSR2)
        ft_printf("0");
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr = nbr + str[i] - '0';
		i++;
	}
	return (nbr * sign);
}

void	send_message(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 0;
		c = *str;
		while (i < 8)
		{
			if (c & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			c = (c << 1);
			i++;
            usleep(500);
		}
		str++;
	}
}

void	send_end(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 0b10000000)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = (c << 1);
		i++;
        usleep(500);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Usage: %s <PID> <message>\n", argv[0]);
		return (1);
	}
    signal(SIGUSR1, handle);
    signal(SIGUSR2, handle);
	send_message(ft_atoi(argv[1]), argv[2]);
	send_end(ft_atoi(argv[1]), '\0');
    return (0);
}
