#include "form2.h"
#include "ui_form2.h"
#include<QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include "form.h"
Form2::Form2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);
}

void Form2::paintEvent(QPaintEvent *event)
{
    QPainter paint1(this);
    QFont font("ink free",50);
    paint1.setFont(font);
    paint1.setPen(Qt::red);
    paint1.drawPixmap(0,0,1000,1000,QPixmap(":/new/prefix1/images/11.jpg"));
    paint1.drawText(0,400,tr("恭喜您通关游戏"));
    paint1.drawText(0,500,tr("您获得的分数为"));
    paint1.drawText(0,600,QString::number(point));
}

Form2::~Form2()
{
    delete ui;
}
