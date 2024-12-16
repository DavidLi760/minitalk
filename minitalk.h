/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:26:51 by davli             #+#    #+#             */
/*   Updated: 2024/06/07 14:26:52 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include "ft_printf/ft_printf.h"

struct sigaction s_sigaction
{
    void    (*sa_handler)(int);
    sigset_t sa_mask;
    int         sa_flags;
    
} t_sigaction;

#endif
