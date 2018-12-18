/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:26:53 by gbrandon          #+#    #+#             */
/*   Updated: 2018/12/07 14:38:47 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1  // -23 0 ?
# define INTERMEDIATE_SIZE 700
# define CHECK_ERR(x) if (!(x)) return (-1)
# define CHECK_CMP_ERR(x) if ((x)) return (-1)
# define IF_RET_ONE(x) if ((x)) return (1)
# define FREE_X(x) if ((x)){free((x)); (x) = NULL;}

int         get_next_line(const int fd, char **line);

#endif
