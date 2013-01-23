#include "lib.h"

void		get_default_entry_args(t_entry_arg* args, GtkWidget* parent,
				       t_parent_type type)
{
	gtk_memset(args, 0, sizeof(*args));
	args->ent_show = TRUE;
	set_default_parent(&args->ent_parent, parent, type);
}

static void	connect_signals(GtkWidget* entry, t_entry_arg* args)
{
	if (args->ent_activate_event)
		g_signal_connect(entry, "activate",
				 G_CALLBACK(args->ent_activate_event),
				 args->ent_activate_data);
}

GtkWidget*	get_new_entry(t_entry_arg* args)
{
	GtkWidget*	entry;

	entry = gtk_entry_new();
	connect_signals(entry, args);
	connect_parent(&args->ent_parent, entry);
	if (args->ent_show == TRUE)
		gtk_widget_show(entry);
	return (entry);
}
