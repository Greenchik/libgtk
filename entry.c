#include "lib.h"

void		get_default_entry_args(t_entry_arg* args, GtkWidget* parent,
				       t_parent_type type)
{
	args->ent_show = TRUE;
	set_default_parent(&args->ent_parent, parent, type);
}

GtkWidget*	get_new_entry(t_entry_arg* args)
{
	GtkWidget*	entry;

	entry = gtk_entry_new();
	connect_parent(&args->ent_parent, entry);
	if (args->ent_show == TRUE)
		gtk_widget_show(entry);
	return (entry);
}

void		entry_connect_activate_signal(GtkWidget* entry,
					      callback_activate* cb,
					      void* data)
{
	g_signal_connect(GTK_ENTRY(entry), "activate", G_CALLBACK(cb), data);
}
