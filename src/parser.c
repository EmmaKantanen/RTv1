/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:39:42 by ikarjala          #+#    #+#             */
/*   Updated: 2023/01/30 15:40:39 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static inline t_parser	parser_init(void)
{
	return ((t_parser){
		.errorid = 0,
		.obj_count = 0,
		.light_count = 0,
		.mat_count = 0,
		.obj = NULL,
		.mat = NULL,
		.lights = NULL,
		.active_type = -1,
		.attr = (t_attr){.type = tnull, .val_req = 0},
		.av = {0},
		.line_num = 0,
		.word_num = 0
	});
}

static inline void	pre_process(char *line)
{
	const char	valid[] = "#<>(){}[]/+=:;,\t\v";
	char		*cp;

	cp = ft_strany (line, valid);
	while (cp)
	{
		if (*cp == '#')
		{
			*cp = 0;
			return ;
		}
		*cp = ' ';
		cp = ft_strany (cp, valid);
	}
}

static inline void	process_token(char *word, t_parser *p)
{
	p->word_num ++;
	if (p->attr.val_req != 0)
		set_attr (word, p);
	else if (!(token_try_obj (word, p)
			|| token_try_light (word, p)
			|| token_try_material (word, p)
			|| token_try_meta (word, p)
			|| token_try_attr (word, p)))
		parser_exception (p, word, MEPARSE_NOEXIST);
	free (word);
}

static inline int	read_line(int fd, char **line, t_parser *p)
{
	const char	em[] = CRED "unexpected error reading next line!" CNIL;
	int			gnl_ex;

	gnl_ex = get_next_line(fd, line);
	if (gnl_ex == RET_ERROR)
	{
		ft_strdel (line);
		ft_panic (em, NULL);
	}
	else if (gnl_ex == RET_EOF)
		ft_strdel (line);
	p->line_num ++;
	p->word_num = 0;
	return (gnl_ex);
}

int	ft_parse(int fd, t_scene *ctx)
{
	t_parser	p;
	char		*line;
	char		**tokens;
	char		**ap;

	line = NULL;
	*ctx = scene_init ();
	p = parser_init ();
	p.default_matp = &ctx->default_mat;
	while (read_line (fd, &line, &p) != RET_EOF)
	{
		pre_process (line);
		tokens = ft_strsplit (line, ' ');
		ft_strdel (&line);
		ap = tokens;
		while (*ap)
			process_token (*(ap++), &p);
		ft_memdel ((void **)(&tokens));
	}
	close (fd);
	if (p.attr.val_req != 0)
		return (parser_exception (&p, NULL, MEPARSE_ARGC));
	scene_apply (ctx, &p);
	return (0);
}
