QT       += core gui sql network printsupport charts multimedia
QT +=widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    mailing1.cpp \
    main.cpp \
    personnelles/mainwindow4.cpp \
    personnelles/personnelles.cpp \
    personnelles/qrcode.cpp \
    reservation.cpp \
    services.cpp \
    smtp.cpp \
    ticket/mainwindow3.cpp \
    ticket/notification.cpp \
    ticket/ticket.cpp \
    visiteur.cpp \
    window.cpp

HEADERS += \
    connection.h \
    dialog.h \
    mailing1.h \
    personnelles/mainwindow4.h \
    personnelles/personnelles.h \
    personnelles/qrcode.h \
    reservation.h \
    services.h \
    smtp.h \
    ticket/mainwindow3.h \
    ticket/notification.h \
    ticket/ticket.h \
    visiteur.h \
    window.h

FORMS += \
    mailing1.ui \
    personnelles/mainwindow4.ui \
    ticket/mainwindow3.ui \
    window.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
   Atelier_Connexion.pro \
   Atelier_Connexion1.pro \
   integration1.pro \
   personnelles/Atelier_Connexion4.pro \
   reservation/Atelier_Connexion.pro \
   reservation/Atelier_Connexion1.pro \
   reservation/Gestionplacesparking.pro \
   ticket/Atelier_Connexion3.pro \
   visiteur/Atelier_Connexion2.pro

DISTFILES += \
    Atelier_Connexion.pro.user \
    Atelier_Connexion.pro.user.1a1554a.4.8-pre1 \
    Atelier_Connexion.pro.user.d567f1b.4.8-pre1 \
    Atelier_Connexion.pro.user.d567f1b.xml \
    Atelier_Connexion1.pro.user \
    Atelier_Connexion1.pro.user.d567f1b.4.8-pre1 \
    personnelles/Atelier_Connexion4.pro.user \
    reservation/Atelier_Connexion.pro.user \
    reservation/Atelier_Connexion.pro.user.d567f1b.4.8-pre1 \
    reservation/Gestionplacesparking.pro.user \
    ticket/Atelier_Connexion3.pro.user \
    ticket/Atelier_Connexion3.pro.user.1a1554a.4.8-pre1 \
    ticket/Atelier_Connexion3.pro.user.d567f1b.4.8-pre1 \
    ticket/Atelier_Connexion3.pro.user.d567f1b.xml \
    visiteur/Atelier_Connexion2.pro.user \
    visiteur/Atelier_Connexion2.pro.user.1a1554a.4.8-pre1 \
    visiteur/Atelier_Connexion2.pro.user.d567f1b.xml \
    visiteur/anglais.qm \
    visiteur/anglais.ts \
    visiteur/english.ts
    integration1.pro.user \

RESOURCES += \
    visiteur/translate.qrc \
    visiteur/translation.qrc
