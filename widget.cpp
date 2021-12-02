#include "widget.h"
#include "ui_widget.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QBoxLayout>
#include <QMenu>
#include <QAction>
#include <QFileDialog>

Widget::Widget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mCamera = new QCamera(this) ;
    mCameraViewfinder = new QCameraViewfinder (this);
    mCameraImageCapture = new QCameraImageCapture (mCamera,this);
    mLayout= new QVBoxLayout;
    mOptionsMenu =new QMenu("Options", this);
    mAllumerAction =new QAction ("Allumer",this);
    mEteindreAction =new QAction ("Etteindre", this);
    mCapturerAction= new QAction ("Capturer",this);

    mOptionsMenu->addActions({mAllumerAction,mEteindreAction,mCapturerAction});
    ui->pushButton->setMenu(mOptionsMenu);
    mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);
    ui->scrollArea->setLayout(mLayout);

    connect(mAllumerAction,&QAction::triggered,[&](){
        mCamera->start();
    });
    connect(mEteindreAction, &QAction::triggered,[&](){
       mCamera->stop();
    });
    connect(mCapturerAction, &QAction::triggered,[&](){
        auto filename = QFileDialog::getSaveFileName(this, "Capturer","/","Image (*.jpg;*.jpeg");
        if (filename.isEmpty()) {
            return ;
        }
        mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
        QImageEncoderSettings imageEncoderSettings ;
        imageEncoderSettings.setCodec("image/jpeg");
        imageEncoderSettings.setResolution(1600, 1200);
        mCameraImageCapture->setEncodingSettings(QImageEncoderSettings());
        mCamera->setCaptureMode(QCamera ::CaptureStillImage);
        mCamera->start() ;
        mCamera->searchAndLock();
        mCameraImageCapture->capture(filename);
        mCamera->unlock();


    });
}

Widget::~Widget()
{
    delete ui;
}
