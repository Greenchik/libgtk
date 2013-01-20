#include "lib.h"

void		get_default_textview_args(t_textview_arg* args,
					  GtkWidget* parent,
					  t_parent_type type)
{
	args->tv_show = TRUE;
	args->tv_editable = FALSE;
	args->tv_cursor_visible = FALSE;
	args->tv_buffer = NULL;
	set_default_parent(&args->tv_parent, parent, type);
}

GtkWidget*	get_new_textview(t_textview_arg* args)
{
	GtkWidget*	textview;

	textview = gtk_text_view_new_with_buffer(args->tv_buffer);
	gtk_text_view_set_editable(GTK_TEXT_VIEW(textview), args->tv_editable);
	gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(textview),
					 args->tv_editable);
	if (args->tv_show == TRUE)
		gtk_widget_show(textview);
	return (textview);
}

GtkWidget*	get_new_textview_scrolled(t_textview_arg* args, GtkWidget** scroll)
{
	GtkWidget*	textview;
	GtkWidget*	scroll_tmp;

	textview = gtk_text_view_new_with_buffer(args->tv_buffer);
	scroll_tmp = gtk_scrolled_window_new(NULL, NULL);
	gtk_container_add(GTK_CONTAINER(scroll_tmp), textview);
	gtk_text_view_set_editable(GTK_TEXT_VIEW(textview), args->tv_editable);
	gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(textview),
					 args->tv_editable);
	if (args->tv_show == TRUE)
	{
		gtk_widget_show(scroll_tmp);
		gtk_widget_show(textview);
	}
	if (scroll)
		*scroll = scroll_tmp;
	return (textview);
}

void		textview_append_text(GtkWidget* textview, char* line)
{
	GtkTextBuffer*	buffer;

	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
	gtk_text_buffer_insert_at_cursor(buffer, line, -1);
}
