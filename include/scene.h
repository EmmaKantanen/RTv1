/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:57:29 by ikarjala          #+#    #+#             */
/*   Updated: 2023/01/30 15:46:03 by ikarjala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "render.h"

typedef struct s_material
{
	double	gloss;
	double	specular;
	t_rgbf	color;
}	t_mat;

typedef struct s_object
{
	int		id;
	t_vec	pos;
	t_vec	rot;
	double	r;
	int		mat;
}	t_obj;

typedef struct s_cam
{
	t_vec	pos;
	t_vec	rot;
}	t_cam;

typedef struct s_parser_data	t_parser;
typedef struct s_scene_context {
	t_obj	*obj;
	t_light	*lights;
	t_mat	*mat;
	size_t	obj_count;
	size_t	light_count;
	size_t	mat_count;
	t_mat	default_mat;
	t_cam	cam;
	double	ambient;
}	t_scene;

typedef enum e_object_type {
	sphere = 0,
	cylinder = 1,
	cone = 2,
	plane = 3
}	t_eobjtype;

void	scene_unload(t_scene *context);
t_scene	scene_init(void);
void	scene_apply(t_scene *ctx, t_parser *p);

#endif
