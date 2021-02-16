#include <gtk/gtk.h>
#include <math.h>

void on_draw_event (GtkWidget *widget, cairo_t *cr, gpointer data)
{
    cairo_set_line_width (cr, 1);
    cairo_scale(cr, 1, 1);
    int u = 0;
    
    for (int j = 0; j < 3; j++) {
        cairo_move_to(cr, 100, 100 + 40*j);
        for (int i = 0; i < 6; i++) {
            cairo_line_to(cr, 140 + 40 * i, 100 + 40*j);
            cairo_line_to(cr, 140 + 40 * i, 140 + 40*j);
            cairo_line_to(cr, 100 + 40 * i, 140 + 40*j);
            cairo_line_to(cr, 100 + 40 * i, 100 + 40*j);
            cairo_line_to(cr, 100 + 40 * i, 140 + 40*j);
            cairo_stroke(cr);
            cairo_line_to(cr, 140 + 40 * i, 100 + 40*j);
            cairo_line_to(cr, 140 + 40 * i, 140 + 40*j);
            cairo_line_to(cr, 100 + 40 * i, 140 + 40*j);
            cairo_stroke_preserve(cr);
            cairo_fill(cr);
            cairo_move_to(cr, 100 + 40*i, 100 + 40*j);
        }
    }
}
 

int main( int argc, char *argv[])
{
   
    gtk_init(&argc, &argv);
 
    GtkWidget *window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    gtk_window_set_title(GTK_WINDOW(window), "Персонаж");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    
    GtkWidget *vbox;
    vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 1);
    gtk_container_add(GTK_CONTAINER (window), vbox);
 
    GtkWidget *drawing_area;
    drawing_area = gtk_drawing_area_new();

    gtk_box_pack_start (GTK_BOX(vbox), drawing_area, TRUE, TRUE, 10);

    g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(on_draw_event), NULL);

    gtk_widget_show_all(window);

    gtk_main();
 
}
