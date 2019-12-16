## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = maison-de-retraite

maison_de_retraite_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	Login.c Login.h \
	personnel.c personnel.h \
	treeView.c treeView.h \
	lecture_med.c lecture_med.h \
	controle_saisie.c controle_saisie.h \
	add_materiel_data.c add_materiel_data.h \
	treeview1.c treeview1.h \
	lecture_cam.c lecture_cam.h \
	Alerte.c Alerte.h \
	alertetree.c alertetree.h \
	alertespec.c alertespec.h \
	treeMateriel.c treeMateriel.h \
	treealertetec.c treealertetec.h \
	sms.c sms.h \
	treemedicale.c treemedicale.h \
	stat.c stat.h

maison_de_retraite_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)
