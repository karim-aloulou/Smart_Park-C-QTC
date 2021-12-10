#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPainter>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QTextStream>



class notification :public QWidget
{
    Q_OBJECT

       Q_PROPERTY(float popupOpacity READ getPopupOpacity WRITE setPopupOpacity)

       void setPopupOpacity(float opacity);
       float getPopupOpacity() const;

   public:
       explicit notification(QWidget *parent = 0);

   protected:
       void paintEvent(QPaintEvent *event);


   public slots:
       void setPopupText(const QString& text);
       void show();

   private slots:
       void hideAnimation();
       void hide();


   private:
       QLabel label;
       QGridLayout layout;
       QPropertyAnimation animation;
       float popupOpacity;
       QTimer *timer;
};


#endif // NOTIFICATION_H
