#include "lib.h"

void		get_default_button_args(t_button_arg* args, GtkWidget* parent,
					t_parent_type type)
{
	gtk_memset(args, 0, sizeof(*args));
	args->but_label = "Button";
	args->but_show = TRUE;
	set_default_parent(&args->but_parent, parent, type);
}

static void	connect_signals(GtkWidget* button, t_button_arg* args)
{
	if (args->but_activate_event)
		g_signal_connect(button, "activate",
				 G_CALLBACK(args->but_activate_event),
				 args->but_activate_data);
	else if (args->but_clicked_event)
		g_signal_connect(button, "clicked",
				 G_CALLBACK(args->but_clicked_event),
				 args->but_clicked_data);
	else if (args->but_clicked_event)
		g_signal_connect(button, "enter",
				 G_CALLBACK(args->but_enter_event),
				 args->but_enter_data);
	else if (args->but_clicked_event)
		g_signal_connect(button, "leave",
				 G_CALLBACK(args->but_leave_event),
				 args->but_leave_data);
	else if (args->but_clicked_event)
		g_signal_connect(button, "pressed",
				 G_CALLBACK(args->but_pressed_event),
				 args->but_pressed_data);
	else if (args->but_clicked_event)
		g_signal_connect(button, "released",
				 G_CALLBACK(args->but_released_event),
				 args->but_released_data);
}

static void	set_args(GtkButton* button, t_button_arg* args)
{
	if (args->but_label)
		gtk_button_set_label(button, args->but_label);
}

GtkWidget*	get_new_button(t_button_arg* args)
{
	GtkWidget*	button;

	button = gtk_button_new();
	set_args(GTK_BUTTON(button), args);
	connect_signals(button, args);
	connect_parent(&args->but_parent, button);
	if (args->but_show)
		gtk_widget_show(button);
	return (button);
}
