/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingywu <jingywu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:05:19 by jingywu           #+#    #+#             */
/*   Updated: 2026/03/09 23:08:17 by jingywu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include "ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	handler(int signal);
void	send_signal(int pid, char c);
void	bhandler(int signal, siginfo_t *info, void *context);
#endif