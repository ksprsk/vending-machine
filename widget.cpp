#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    changeEnable();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateMoney(int value) {
    money += value;
    ui->lcdNumber->display(money);

    changeEnable();
}

void Widget::changeEnable() {
    ui->coffee->setEnabled(money >= 100);
    ui->tea->setEnabled(money >= 150);
    ui->milk->setEnabled(money >= 200);
    ui->reset->setEnabled(money > 0);
}

void Widget::on_coin_10_clicked()
{
    updateMoney(10);
}


void Widget::on_coin_50_clicked()
{
    updateMoney(50);
}


void Widget::on_coin_100_clicked()
{
    updateMoney(100);
}


void Widget::on_coin_500_clicked()
{
    updateMoney(500);
}


void Widget::on_coffee_clicked()
{
    updateMoney(-100);
}


void Widget::on_tea_clicked()
{
    updateMoney(-150);
}


void Widget::on_milk_clicked()
{
    updateMoney(-200);
}


void Widget::on_reset_clicked()
{
    QString msg = "";
    msg += "500 won : " + QString::number(money / 500) + "\n"; money %= 500;
    msg += "100 won : " + QString::number(money / 100) + "\n"; money %= 100;
    msg += "50 won : " + QString::number(money / 50) + "\n"; money %= 50;
    msg += "10 won : " + QString::number(money / 10); money %= 10;

    QMessageBox mb;
    mb.information(nullptr, "title", msg);

    updateMoney(0);
}
