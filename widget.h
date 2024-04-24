#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money{0};
    void updateMoney(int diff);
    void changeEnable();

private slots:
    void on_coin_10_clicked();

    void on_coin_50_clicked();

    void on_coin_100_clicked();

    void on_coin_500_clicked();

    void on_coffee_clicked();

    void on_tea_clicked();

    void on_milk_clicked();

    void on_reset_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
