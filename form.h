#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);
    void getpoint();
    int point;
    ~Form();

private slots:
    void on_pushButton_clicked();

private:
    int x=500,y=700;
    int health=3;
    int a[100][2];
    int k=0,k1=0,q=0,o=0;
    int count=1;
    int b[20][2];
    int eventID;
    int time;
    int boss_x=200,boss_y=0;
    int boss_a[100][2];
    int hit=0;
    Ui::Form *ui;
};

#endif // FORM_H
