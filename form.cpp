#include "form.h"
#include "ui_form.h"
#include "form2.h"
#include "form1.h"
#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QTimer>
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    eventID=startTimer(100);
    time=0;
}

Form::~Form()
{
    delete ui;
}

void Form::paintEvent(QPaintEvent *event)
{
    QPainter paint(this);
    a[k][0]=x+20,a[k][1]=y-40;
    boss_a[k1][0]=boss_x+150,boss_a[k1][1]=boss_y+300;
    QFont font("ink free",50);
    paint.setFont(font);
    paint.setPen(Qt::red);
    paint.drawPixmap(0,0,1000,1000,QPixmap(":/new/prefix1/images/11.jpg"));
    paint.drawPixmap(x,y,50,50,QPixmap(":/new/prefix1/images/me1.png"));
    paint.drawText(500,100,QString::number(point));
    for(int i=0;i<100;i++)
    {
        if(a[i][0]!=0){
            paint.drawPixmap(a[i][0],a[i][1],10,30,QPixmap(":/new/prefix1/images/bom.png"));
        }
    }//绘制子弹
    //绘制血量
    for(int i=0;i<health;i++)
    {
        paint.drawPixmap(50*i,50,50,50,QPixmap(":/new/prefix1/images/health.jpg"));
    }
    //绘制敌方战机
    for(int i=0;i<count;i++)
    {
        if(b[i][0]>=0)
        {
            b[i][0]=100+100*i,b[i][1]=100+q;
            if(b[i][1]>=1000)
            {
                b[i][1]=100;
                q=0;
            }
        }
        paint.drawPixmap(b[i][0],b[i][1],50,50,QPixmap(":/new/prefix1/images/enemy1.png"));
    }
    //Boss
    if(hit<=40)
    {
        paint.drawPixmap(boss_x,boss_y,300,300,QPixmap(":/new/prefix1/images/enemy3_n1.png"));
        //绘制boss弹药
        for(int i=0;i<100;i++)
        {
            if(boss_a[i][0]!=0){
                paint.drawPixmap(boss_a[i][0],boss_a[i][1],40,80,QPixmap(":/new/prefix1/images/Bossbom.png"));
            }
        }
    }
    if(hit==41)
    {
        paint.drawPixmap(boss_x,boss_y,300,300,QPixmap(":/new/prefix1/images/enemy3_down1.png"));
        paint.drawPixmap(boss_x,boss_y,300,300,QPixmap(":/new/prefix1/images/enemy3_down2.png"));
         paint.drawPixmap(boss_x,boss_y,300,3000,QPixmap(":/new/prefix1/images/enemy3_down3.png"));
         paint.drawPixmap(boss_x,boss_y,300,300,QPixmap(":/new/prefix1/images/enemy3_down4.png"));
         paint.drawPixmap(boss_x,boss_y,300,300,QPixmap(":/new/prefix1/images/enemy3_down5.png"));
          paint.drawPixmap(boss_x,boss_y,300,300,QPixmap(":/new/prefix1/images/enemy3_down6.png"));
          this->close();
          Form2 *f2=new Form2();
          f2->point=point;
          f2->resize(1000,1000);
          f2->show();
    }
    for(int j=0;j<100;j++)
    {
        for(int h=0;h<count;h++)
        {
            if(a[j][1]>=b[h][1]-25&&a[j][1]<=b[h][1]+25&&a[j][0]>=b[h][0]-25&&a[j][0]<=b[h][0]+25)
            {
                point++;
                paint.drawPixmap(b[h][0],b[h][1],50,50,QPixmap(":/new/prefix1/images/enemy1_down1.png"));
                paint.drawPixmap(b[h][0],b[h][1],50,50,QPixmap(":/new/prefix1/images/enemy1_down2.png"));
                 paint.drawPixmap(b[h][0],b[h][1],50,50,QPixmap(":/new/prefix1/images/enemy3_down3.png"));
                b[h][1]=-100,b[h][0]=-100;
                a[j][1]=-700,a[j][0]=-700;
            }
        }
    }
    for(int i=0;i<count;i++)
    {
        if(y>=b[i][1]-25&&y<=b[i][1]+25&&x>=b[i][0]-25&&x<=b[i][0]+25)
        {
            health--;
            paint.drawPixmap(x,y,50,50,QPixmap(":/new/prefix1/images/me_destroy_1.png"));
            paint.drawPixmap(x,y,50,50,QPixmap(":/new/prefix1/images/me_destroy_2.png"));
            paint.drawPixmap(x,y,50,50,QPixmap(":/new/prefix1/images/me_destroy_3.png"));
            paint.drawPixmap(x,y,50,50,QPixmap(":/new/prefix1/images/me_destroy_4.png"));
            paint.drawPixmap(x,y,50,50,QPixmap(":/new/prefix1/images/me1.png"));

        }
        for(int j=0;j<100;j++)
        {
            if(y>=boss_a[j][1]-25&&y<=boss_a[j][1]+25&&x>=boss_a[j][0]-25&&x<=boss_a[j][0]+25)
            {
                health--;
                paint.drawPixmap(x,y,50,50,QPixmap(":/new/prefix1/images/me_destroy_1.png"));
                paint.drawPixmap(x,y,50,50,QPixmap(":/new/prefix1/images/me_destroy_2.png"));
                paint.drawPixmap(x,y,50,50,QPixmap(":/new/prefix1/images/me_destroy_3.png"));
                paint.drawPixmap(x,y,50,50,QPixmap(":/new/prefix1/images/me_destroy_4.png"));
                paint.drawPixmap(x,y,50,50,QPixmap(":/new/prefix1/images/me1.png"));
            }
        }
    }
    for(int j=0;j<100;j++)
    {
        if(a[j][1]>=boss_y-150&&a[j][1]<=boss_y+150&&a[j][0]>=boss_x-150&&a[j][0]<=boss_x+150)
        {
            hit++;
            point++;
            a[j][1]=-700,a[j][0]=-700;
        }
    }
    //游戏结束
    if(health<=0)
    {
        this->close();
        Form1 *f1=new Form1();
        f1->resize(1000,1000);
        f1->show();
        time=0;
    }
}
void Form::timerEvent(QTimerEvent *event)
{
    if(o==0)
    {
        for(int i=0;i<100;i++)
        {
            a[i][0]=-700;
            a[i][1]=-700;
        }
        point=0;
    }
    o++;
    if(o%2==0)//控制子弹射击速度
    {
        k++;
    }
    if(o%8==0)
    {
        k1++;
    }
    q+=5;
    for(int i=0;i<100;i++)
    {
        if(a[i][0]!=0)
        {
            a[i][1]-=50;
        }
    }
    for(int i=0;i<100;i++)
    {
        if(boss_a[i][0]!=1000)
        {
            boss_a[i][1]+=10;
        }
    }
    if(k>=100)
    {
        count+=2;
        k=0;
    }
    time+=2;
    time=time%2;
    if(time==0)
    {
        repaint();
    }
    boss_x+=15;
    if(boss_x>=1000)
    {
        boss_x=0;
    }
}

void Form::keyPressEvent(QKeyEvent *event)
{
    QKeyEvent *key=(QKeyEvent *)event;
    switch (key->key()) {
    case Qt::Key_S:
        this->y+=10;
        break;
    case Qt::Key_W:
        this->y-=10;
        break;
    case Qt::Key_A:
        this->x-=10;
        break;
    case Qt::Key_D:
        this->x+=10;
        break;
    }
}

void Form::on_pushButton_clicked()
{
    time++;
}
