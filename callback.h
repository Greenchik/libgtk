#ifndef __CALLBACK_H__
#define __CALLBACK_H__

#ifndef __BUTTON_CALLBACK_H__
#define __BUTTON_CALLBACK_H__
typedef void	cb_button(GtkButton* button, gpointer user_data);
#endif

#ifndef __ENTRY_CALLBACK_H__
#define __ENTRY_CALLBACK_H__
typedef void	cb_entry(GtkEntry* entry, gpointer user_data);
#endif

#ifndef __WIDGET_CALLBACK_H__
#define __WIDGET_CALLBACK_H__
typedef void	cb_widget(GtkWidget* widget, GdkEvent* event,
			  gpointer user_data);
#endif

#endif
