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

# define BUFF_SIZE 263//19
# define INTERMEDIATE_SIZE 700//4
# define ret(x) return (x)
# define CHECK_ERR(x) if (!(x)) ret(-1)
# define CHECK_CMP_ERR(x) if ((x)) ret (-1)
# define IF_RET_ONE(x) if ((x)) ret (1)
# define FREE_X(x) if ((x)){free((x)); (x) = NULL;}
# define ERR_PROC(x) if ((x)==1) ret(1); else if ((x)==-1) ret(-1);
# define IF_BREAK(x) if ((x)) break

typedef struct			s_info
{
	int			fd;
	char		*buf;
	size_t		buf_size;
	char		*inter_buf;
	size_t		i_buf_size;
	size_t		buf_cur_pos;
}						t_info;
int						get_next_line(const int fd, char **line);

#endif
