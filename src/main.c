#include <gtk/gtk.h>
#include <stdio.h>

#include "lib.h"

void	entry_callback(GtkEntry* entry, gpointer data)
{
	GtkWidget*	tv;

	printf("Catching backspace signal\n");
	tv = (GtkWidget*)data;
	if (gtk_entry_get_text_length(entry) > 0)
	{
		textview_append_text(tv, (char*)gtk_entry_get_text(entry));
		textview_append_text(tv, "\n");
		gtk_entry_set_text(entry, "");
	}
	else
		printf("Nothing to do\n");
}

int	main(int argc, char** argv)
{
	GtkWidget*	win;
	t_window_arg	win_arg;
	GtkWidget*	not;
	t_notebook_arg	not_args;
	GtkWidget*	but;
	t_button_arg	but_arg;
	GtkWidget*	tv;
	GtkWidget*	scroll;
	t_textview_arg	tv_args;
	int		i;
	t_entry_arg	ent_args;
	GtkWidget*	ent;
	t_chatarea	chatarea;

	/* Gtk iniy */
	gtk_init(&argc, &argv);

	/* Get new window */
	get_default_window_args(&win_arg);
	win = get_new_window(&win_arg);

	/* Get new notebook */
	get_default_notebook_args(&not_args, win, E_MY_GTK_PARENT_CONTAINER);
	not = get_new_notebook(&not_args);

	/* Get new button */
	get_default_button_args(&but_arg, NULL, E_MY_GTK_PARENT_NONE);
	but = get_new_button(&but_arg);

	/* Add a notebook */
	gtk_notebook_append_page(GTK_NOTEBOOK(not), but, NULL);

	/* Get new entry */
	get_default_entry_args(&ent_args, NULL, E_MY_GTK_PARENT_NONE);
	ent = get_new_entry(&ent_args);

	/* Add a notebook */
	gtk_notebook_append_page(GTK_NOTEBOOK(not), ent, NULL);

	/* Get new button */
	but = get_new_button(&but_arg);

	/* Add a notebook */
	gtk_notebook_append_page(GTK_NOTEBOOK(not), but, NULL);

	/* Get a basic scrolled textview */
	get_default_textview_args(&tv_args, NULL, E_MY_GTK_PARENT_NONE);
	tv = get_new_textview_scrolled(&tv_args, &scroll);

	/* Add a notebook */
	gtk_notebook_append_page(GTK_NOTEBOOK(not), scroll, NULL);

	/* Get new chatarea */
	init_simple_chatarea(&chatarea, NULL, E_MY_GTK_PARENT_NONE);
	get_simple_chatarea(&chatarea);
	entry_connect_activate_signal(chatarea.ca_entry, &entry_callback,
				      chatarea.ca_textarea);

	/* Add in notebook */
	gtk_notebook_append_page(GTK_NOTEBOOK(not), chatarea.ca_vbox, NULL);

	/* Add 100 time the line "test\n" in the textview */
	i = 0;
	while (i < 100)
	{
		textview_append_text(tv, "Simple gtk_textview\n");
		i = i + 1;
	}
	textview_append_text(chatarea.ca_textarea, "Chatarea view\n");

	/* Gtk main loop */
	gtk_main();

	return (0);
}
