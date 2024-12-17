/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:56:04 by davli             #+#    #+#             */
/*   Updated: 2024/12/17 18:53:42 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_bit(pid_t pid, int bit)
{
    if (bit == 0)
	{
        kill(pid, SIGUSR1);
    } else {
        kill(pid, SIGUSR2);
    }
    usleep(100);
}

void send_message(pid_t pid, const char *message)
{
	int	i;
	int	bit;
    unsigned char c;

	i = 7;
    while (*message)
	{
		c = *message;
        while (i >= 0)
		{
            bit = (c >> i) & 1;
            send_bit(pid, bit);
			i--;
        }
        message++;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
	{
        ft_printf("Usage: %s <PID> <message>\n", argv[0]);
        return (1);
    }

    pid_t pid = atoi(argv[1]);
    const char *message = argv[2];

    send_message(pid, message);

    return (0);
}