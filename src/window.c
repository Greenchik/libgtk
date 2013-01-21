#include <stdio.h>
#include <stdlib.h>

#include "lib.h"

void		get_default_window_args(t_window_arg* args)
{
	args->win_type = GTK_WINDOW_TOPLEVEL;
	args->win_title = "Gtk window";
	args->win_width = 800;
	args->win_height = 600;
	args->win_show = TRUE;
	args->win_resizable = TRUE;
	args->win_position = GTK_WIN_POS_CENTER;
	args->win_delete_event_data = NULL;
	args->win_delete_event_event = NULL;
	args->win_destroy_data = NULL;
	args->win_destroy_event = NULL;
	args->win_quit_on_exit = TRUE;
	args->win_decorated = TRUE;
}

GtkWidget*	get_new_window(t_window_arg* args)
{
	GtkWidget*	window;

	window = gtk_window_new(args->win_type);
	gtk_window_set_title(GTK_WINDOW(window), args->win_title);
	gtk_window_resize(GTK_WINDOW(window), args->win_width,
			  args->win_height);
	gtk_window_set_resizable(GTK_WINDOW(window), args->win_resizable);
	gtk_window_set_position(GTK_WINDOW(window), args->win_position);
	gtk_window_set_decorated(GTK_WINDOW(window), args->win_position);
	if (args->win_quit_on_exit == TRUE)
		g_signal_connect(window, "destroy",
				 G_CALLBACK(&gtk_main_quit), NULL);
	else if (args->win_destroy_event)
		g_signal_connect(window, "destroy",
				 G_CALLBACK(&args->win_destroy_event),
				 args->win_destroy_data);
	if (args->win_delete_event_event)
		g_signal_connect(window, "delete-event",
				 G_CALLBACK(&args->win_delete_event_event),
				 args->win_delete_event_data);
	if (args->win_show == TRUE)
		gtk_widget_show(window);
	return (window);
}
