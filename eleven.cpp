#include <gtk/gtk.h>
#include <math.h>
#include <random>
#include <ctime>
#include <iostream>
using namespace std;

void on_draw_event (GtkWidget *widget, cairo_t *cr, gpointer data)
{
    cairo_set_line_width (cr, 1);
    cairo_scale(cr, 1, 1);
    cairo_move_to(cr, 99, 99);
    cairo_line_to(cr, 99, 500);
    cairo_line_to(cr, 500, 500);
    cairo_line_to(cr, 500, 99);
    cairo_line_to(cr, 99, 99);
    cairo_stroke(cr);
    int N = 500;
    srand(time(0));
    
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    int counter4 = 0;
    
    for (int i = 0; i < N; i++) {
        cairo_set_source_rgb(cr, rand()/RAND_MAX, rand()/RAND_MAX, rand()/RAND_MAX);
        int x = rand() % 400;
        int y = rand() % 400;
        cairo_move_to(cr, x, y);
        cairo_move_to(cr, x + 0.01, y + 0.01);
        cairo_stroke(cr);
        if ((x < 200) and (y < 200)) {
            counter2 += 1;
        }
        if ((x > 199) and (y < 200)) {
            counter1 += 1;
        }
        if ((x > 199) and (y > 199)) {
            counter4 += 1;
        }
        if ((x < 200) and (y > 199)) {
            counter3 += 1;
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
