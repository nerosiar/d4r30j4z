/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *login_window;
  GtkWidget *Admin_window;
  GtkWidget *ajouter_infirmier_window;
  GtkWidget *ajouter_technicien_window;
  GtkWidget *ajouter_aide_soignant_window;
  GtkWidget *technicien_window;
  GtkWidget *edit_window;
  GtkWidget *ajout_camera;
  GtkWidget *ajout_bracelet;
  GtkWidget *edit_camera_window;
  GtkWidget *edit_bracelet_window;
  GtkWidget *ajouter_medecin_window;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  login_window = create_window2 ();
  gtk_widget_show (login_window);

  gtk_main ();
  return 0;
}
