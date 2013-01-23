#ifndef __BOX_H__
#define __BOX_H__

typedef enum	s_box_orientation
{
	E_MY_GTK_BOX_V,
	E_MY_GTK_BOX_H
}	t_box_orientation;

typedef struct	s_box_arg
{
	t_box_orientation	box_orientation;
	gboolean		box_homogeneous;
	int			box_spacing;
	gboolean		box_show;
	t_parent		box_parent;
}	t_box_arg;

void		get_default_box_args(t_box_arg* args,
				     t_box_orientation orientation,
				     GtkWidget* parent, t_parent_type type);
GtkWidget*	get_new_box(t_box_arg* args);

#endif
