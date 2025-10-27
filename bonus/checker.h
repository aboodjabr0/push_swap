/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:37:00 by asauafth          #+#    #+#             */
/*   Updated: 2025/10/27 12:24:54 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 4
# include "../libft/libft.h"
# include "../push_swap.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_strlen_gnl(const char *s);
#endif