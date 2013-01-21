#include "lib.h"

void		get_default_box_args(t_box_arg* args,
				     t_box_orientation orientation,
				     GtkWidget* parent, t_parent_type type)
{
	args->box_orientation = orientation;
	args->box_homogeneous = FALSE;
	args->box_spacing = 0;
	args->box_show = TRUE;
	set_default_parent(&args->box_parent, parent, type);
}

GtkWidget*	get_new_box(t_box_arg* args)
{
	GtkWidget*	box;

	if (args->box_orientation == E_MY_GTK_BOX_V)
		box = gtk_vbox_new(args->box_homogeneous, args->box_spacing);
	else if (args->box_orientation == E_MY_GTK_BOX_H)
		box = gtk_hbox_new(args->box_homogeneous, args->box_spacing);
	else
		return (NULL);
	connect_parent(&args->box_parent, box);
	if (args->box_show == TRUE)
		gtk_widget_show(box);
	return (box);
}
