#include "lib.h"

void		get_default_notebook_args(t_notebook_arg* args,
					  GtkWidget* parent,
					  t_parent_type type)
{
	args->not_show = TRUE;
	set_default_parent(&args->not_parent, parent, type);
}

GtkWidget*	get_new_notebook(t_notebook_arg* args)
{
	GtkWidget*	notebook;

	notebook = gtk_notebook_new();
	connect_parent(&args->not_parent, notebook);
	if (args->not_show == TRUE)
		gtk_widget_show(notebook);
	return (notebook);
}
