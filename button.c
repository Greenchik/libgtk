#include "lib.h"

void		get_default_button_args(t_button_arg* args, GtkWidget* parent,
					t_parent_type type)
{
	args->but_label = "Button";
	args->but_clicked_data = NULL;
	args->but_clicked_event = NULL;
	args->but_enter_data = NULL;
	args->but_enter_event = NULL;
	args->but_leave_data = NULL;
	args->but_leave_event = NULL;
	args->but_show = TRUE;
	set_default_parent(&args->but_parent, parent, type);
}

GtkWidget*	get_new_button(t_button_arg* args)
{
	GtkWidget*	button;

	button = gtk_button_new();
	if (args->but_label)
		gtk_button_set_label(GTK_BUTTON(button), args->but_label);
	if (args->but_clicked_event)
		g_signal_connect(button, "clicked",
				 G_CALLBACK(args->but_clicked_event),
				 args->but_clicked_data);
	if (args->but_enter_event)
		g_signal_connect(button, "enter",
				 G_CALLBACK(args->but_enter_event),
				 args->but_enter_data);
	if (args->but_leave_event)
		g_signal_connect(button, "leave",
				 G_CALLBACK(args->but_leave_event),
				 args->but_leave_data);
	connect_parent(&args->but_parent, button);
	if (args->but_show)
		gtk_widget_show(button);
	return (button);
}
