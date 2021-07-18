#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QMediaPlayer>
#include <QSound>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::play()
{
    QMediaPlayer *player = new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile(":/new/prefix1/music/1.mp3"));
    player->setVolume(30);
    player->play();
}

void MainWindow::on_pushButton_clicked()
{
    Form *form=new Form();
    form->resize(1000,1000);
    this->close();
    form->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}
