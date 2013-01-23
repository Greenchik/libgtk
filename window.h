#ifndef __WINDOW_H__
#define __WINDOW_H__

typedef struct	s_window_arg
{
	GtkWindowType		win_type;
	char*			win_title;
	unsigned int		win_width;
	unsigned int		win_height;
	gboolean		win_show;
	gboolean		win_resizable;
	GtkWindowPosition	win_position;
	gboolean		win_decorated;
	void*			win_delete_event_data;
	cb_widget*		win_delete_event_event;
	void*			win_destroy_data;
	cb_widget*		win_destroy_event;
	gboolean		win_quit_on_exit;
}	t_window_arg;

void		get_default_window_args(t_window_arg* args);
GtkWidget*	get_new_window(t_window_arg* args);

#endif
