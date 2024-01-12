#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(500, 450);
    this->setStyleSheet("QLineEdit {border: 2px solid gray;border-radius: 10px;padding: 0 8px;background: white;selection-background-color: darkgray;}"
                        "QPushButton {border: 2px solid #8f8f91;border-radius: 6px;background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde);min-width: 80px;}"
                        "QPushButton:pressed {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #dadbde, stop: 1 #f6f7fa);}"
                        "QPushButton:flat {border: none; /* no border for a flat push button */}"
                        "QPushButton:default {border-color: navy; /* make the default button prominent */}"
                        "QListWidget{border : 2px solid black;background : lightgreen;}QListWidget QScrollBar{background : lightblue;}QListView::item:selected{border : 2px solid black;background : green;}");

    item = new QLineEdit();
    item->setPlaceholderText("new task");
    list = new QListWidget;
    list->setDragEnabled(true);
    layout = new QFormLayout(this);
    addButton = new QPushButton("add");
    removeButton = new QPushButton("remove");

    layout->addRow(item);
    layout->addRow(addButton);
    layout->addRow(list);
    layout->addRow(removeButton);

    connect(addButton, &QPushButton::clicked, this, add);
    connect(removeButton, &QPushButton::clicked, this, remove);
}

Widget::~Widget()
{
    delete this;
    delete ui;
}

void Widget::add()
{
    if(!item->text().isEmpty()){
        QString text = item->text();
        list->addItem(text);
    }

}

void Widget::remove()
{
    //QListWidgetItem* text = list->selectedItems();
    //list->takeItem(text);
    list->model()->removeRow(list->currentRow());
}

