#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <iostream>
#include <QLineEdit>
#include <QListWidget>
#include <QFormLayout>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void add();
    void update();
    void remove();

private:
    Ui::Widget *ui;
    QLineEdit* item;
    QListWidget* list;
    QFormLayout* layout;
    QPushButton* addButton;
    QPushButton* removeButton;
};
#endif // WIDGET_H
