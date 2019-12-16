

#ifndef CALLBACKS_H_INCLUDED
#define CALLBACKS_H_INCLUDED

#include <gtk/gtk.h>
#include "alertetree.h"

void on_connecter_login_button_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_quitter_login_button_clicked(GtkWidget *objet_graphique,  gpointer user_data);

void on_Admin_window_show (GtkWidget *objet_graphique,  gpointer user_data);

void on_ajouter_nouveau_med_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_refresh_medecin_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_search_med_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_refresh_infirmier_clicked  (GtkWidget *objet_graphique,  gpointer user_data);

void on_search_infimier_clicked  (GtkWidget *objet_graphique,  gpointer user_data);

void on_ajouter_nouveau_inf_clicked  (GtkWidget *objet_graphique,  gpointer user_data);

void on_refresh_aide_soignant_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_search_aide_soignant_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_ajouter_nouveau_as_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_search_technicien_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_refresh_technicien_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_ajouter_nouveau_tech_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_treeview1_show (GtkWidget *objet_graphique,  gpointer user_data);

void on_quit_button_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_ajouter_infirmier_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_annuler_infirmier_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_ajouter_technicien_clicked  (GtkWidget *objet_graphique,  gpointer user_data);

void on_annuler_technicien_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_ajouter_as_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_annuler_as_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_button_trouver_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_supprimer_id_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_edit_button_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_add_camera_button_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_search_cam_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_button38_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_button37_clicked  (GtkWidget *objet_graphique,  gpointer user_data);

void on_find_bracelet_button_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_button42_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_supprimer_bracelet_button_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_ajouter_medecin_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_annuler_medecin_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_confirm_ajout_button_clicked  (GtkWidget *objet_graphique,  gpointer user_data);

void on_ajout_succes_window_show (GtkWidget       *widget,   gpointer         user_data);

void on_edit_inf_button_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_supprimer_id_inf_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_button_trouver_inf_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_supprimer_tec_button_clicked (GtkWidget *objet_graphique,   gpointer user_data);

void on_edit_tech_button_clicked (GtkWidget *objet_graphique,   gpointer user_data);

void on_button_trouver_tech_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_button_trouver_as_clicked  (GtkWidget *objet_graphique,  gpointer user_data) ;

void on_supprimer_id_as_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_edit_as_button_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void
on_ajout_photo_persoag_clicked         (GtkWidget *objet_graphique,  gpointer user_data);

void
on_supprimer_photo_persoag_clicked     (GtkWidget *objet_graphique,  gpointer user_data);

void on_enrg_fichier_persoag_clicked(GtkWidget *objet_graphique,  gpointer user_data);

void
on_Quitter_persoag_clicked             (GtkWidget *objet_graphique,  gpointer user_data);

void on_ajouter_nouveaux_pa_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_refresh_cam_clicked(GtkWidget *objet_graphique,  gpointer user_data);

void on_ajouter_nouveau_cam_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_ajouter_nouveau_bra_clicked    (GtkWidget *objet_graphique,  gpointer user_data);

void on_search_bra_clicked   (GtkWidget *objet_graphique,  gpointer user_data);

void
on_refresh_bra_clicked                 (GtkWidget *objet_graphique,  gpointer user_data);

void on_add_bracelet_button_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_search_cam_edit_clicked   (GtkWidget *objet_graphique,  gpointer user_data);

void on_send_alertes_button_clicked         (GtkWidget *objet_graphique,  gpointer user_data);

void on_enregister_saisie_rapport_button_clicked  (GtkWidget *objet_graphique,  gpointer user_data);

void on_fermer_saisie_rapport_clicked       (GtkWidget *objet_graphique,  gpointer user_data);

void on_cancel_ordonnance_button_clicked    (GtkWidget *objet_graphique,  gpointer user_data);

void on_save_ordonnance_button_clicked      (GtkWidget *objet_graphique,  gpointer user_data);

void on_search_fiche_button_clicked         (GtkWidget *objet_graphique,  gpointer user_data);

void on_ajouter_info_button_clicked         (GtkWidget *objet_graphique,  gpointer user_data);

void on_fermer_info_button_clicked          (GtkWidget *objet_graphique,  gpointer user_data);

void on_cancel_rdv_button_clicked           (GtkWidget *objet_graphique,  gpointer user_data);

void on_save_rdv_button_clicked             (GtkWidget *objet_graphique,  gpointer user_data);

void on_as_envoyer_alerte_button_clicked    (GtkWidget *objet_graphique,  gpointer user_data);

void on_as_ajouter_rapport_espace_button_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_as_ajouter_reclamation_button_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_Espace_medecin_show (GtkWidget  *widget, gpointer user_data);

void  on_ordonnance_recherche_clicked (GtkWidget *objet_graphique,  gpointer user_data);

void on_ajouter_materiel_clicked            (GtkWidget *objet_graphique,  gpointer user_data);

void on_supprimer_materiel_clicked          (GtkWidget *objet_graphique,  gpointer user_data);

void on_selectionner_tout_etat_clicked      (GtkWidget *objet_graphique,  gpointer user_data);

void on_supprimer_etat_clicked              (GtkWidget *objet_graphique,  gpointer user_data);

void on_enregister_remarque_etat_clicked    (GtkWidget *objet_graphique,  gpointer user_data);

void on_actualiser_nouveau_alertes_clicked  (GtkWidget *objet_graphique,  gpointer user_data);

void on_envoyer_alerte_clicked              (GtkWidget *objet_graphique,  gpointer user_data);

void on_eregistrer_rapport_clicked          (GtkWidget *objet_graphique,  gpointer user_data);

void on_se_deconnecter_clicked (GtkWidget       *objet_graphique, gpointer         user_data);

void on_envoyer_alertes_clicked(GtkWidget       *objet_graphique, gpointer         user_data);



void on_ajouter_materiel_technique_clicked  (GtkWidget *objet_graphique, gpointer user_data);

void  on_actualiser_liste_materiel_technique_clicked(GtkWidget *objet_graphique, gpointer user_data);

void on_ajouter_materiel_medical_clicked(GtkWidget *objet_graphique, gpointer user_data);

void on_actualiser_liste_materiel_medical_clicked(GtkWidget *objet_graphique, gpointer user_data);

void on_deconnecter_clicked (GtkWidget       *objet_graphique, gpointer         user_data);

void on_espace_as_show(GtkWidget  *widget,gpointer   user_data);

void on_Espace_infirmier_show (GtkWidget *widget,   gpointer user_data);

void on_technicien_window_show  (GtkWidget *widget, gpointer user_data);

void on_as_chercher_espace_as_button_clicked (GtkWidget *objet_graphique, gpointer user_data);

void on_ajout_mat_butt_clicked(GtkWidget  *objet_graphique,   gpointer  user_data);

void on_rest_as_button_clicked (GtkWidget  *objet_graphique,   gpointer  user_data);

void on_deconnecter_as_button_clicked  (GtkWidget  *objet_graphique,   gpointer  user_data);

void on_deconnecter_medecin_button_clicked  (GtkWidget *objet_graphique,  gpointer user_data);

void on_ajout_mat_med_butt_clicked (GtkWidget *objet_graphique,  gpointer user_data);


#endif

void
on_map_button_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_cam_button_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_waiting_room_cam_button_clicked     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_hall_cam_button_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_front_door_cam_button_clicked       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_back_door_cam_button_clicked        (GtkWidget       *button,
                                        gpointer         user_data);

gboolean
on_label532_activate_link              (GtkLabel        *label,
                                        gchar           *arg1,
                                        gpointer         user_data);

void
on_curve1_show                         (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_reset_al_tec_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_reset_text_inf_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_reset_as_txt_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_reset_sr_as_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

gboolean
on_combobox_al_focus                   (GtkWidget       *widget,
                                        GtkDirectionType  direction,
                                        gpointer         user_data);

void
on_combobox_al_move_active             (GtkWidget       *widget,
                                        GtkScrollType    arg1,
                                        gpointer         user_data);

void
on_quit_cam_button_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_twitter_button_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_facebook_button_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_youtube_button_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_publicite_button_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_authentification_button_clicked     (GtkWidget      *button,
                                        gpointer         user_data);

void
on_info_geek_button_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_stat_button_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_stat_button_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_stat_button_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_afficher_stat_button_clicked        (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void on_button44_clicked  (GtkWidget       *button,   gpointer         user_data);
