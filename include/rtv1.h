/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:20:34 by ekantane          #+#    #+#             */
/*   Updated: 2022/11/18 16:01:17 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <SDL2/SDL.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

// TODO: fix Makefile and replace relative paths with just names
# include "../libft/libft.h"
# include "vector.h"
# include "scene.h"
# include "render.h"

# define DWIDTH		800
# define DHEIGHT	800
# define V_W		40
# define V_H		40
# define EPS		0.000001

// =======================

typedef struct s_sdl
{
	SDL_Window		*wind;
	SDL_Renderer	*rend;
	t_cam			cam;
	t_object		obj;
	double			min_t;
	int				clos_obj;
	double			ambient;
	t_light			light;
	int				spl_res[0];
}	t_sdl;

void	ft_parse(char *arg, t_sdl *sdl);

void	init_sdl(t_sdl *sdl);
int		main(int argc, char **argv);

int		shadow_init(t_light *light, t_sdl *sdl);
void	get_intensity(t_sdl *sdl, t_light *light, t_vec v, double s);
void	get_dir(double x, double y, t_ray *ray, t_sdl *sdl);
void	set_color(t_sdl *sdl, int i, int x, int y);
void	ray_trace_init(t_sdl *sdl, t_ray *ray);
t_vec	sphere_normal(t_ray *ray, t_object *obj);
double	get_t(double a, double b, double d);
double	sphere_intersect(t_vec o, t_vec dir, t_object *obj);
void	object_init(t_sdl *sdl, t_ray *ray, int i, t_object *obj);
void	cylinder(t_sdl *sdl, t_ray *ray, int i, t_object *obj);
double	cylinder_intersect(t_vec o, t_vec dir, t_object *obj);
t_vec	cylinder_normal(t_ray *ray, t_object *obj);
void	light(t_sdl *sdl, t_ray *ray);
void	intersection_check(t_ray *ray, t_sdl *sdl, int x, int y);

#endif
