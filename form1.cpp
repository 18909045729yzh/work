#include "form1.h"
#include "form.h"
#include "ui_form1.h"
#include <QPainter>
#include <QPaintEvent>

Form1::Form1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form1)
{
    ui->setupUi(this);
}

Form1::~Form1()
{
    delete ui;
}
void Form1::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    paint.drawPixmap(0,0,1000,1000,QPixmap(":/new/prefix1/images/over.jpg"));
}
