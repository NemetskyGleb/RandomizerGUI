#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <iostream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
    delete vTextEdits;
}



void Widget::on_spinBox_valueChanged(int objNum)
{
    static int incr_y = 0;
    static int prev_objNum = objNum;
    int g_xpos = 10;
    int g_ypos = 60;
    int g_w = 100;
    int g_h = 30;
    if (objNum >= prev_objNum) {
        for (int i = vTextEdits->size(); i < objNum ; i++, incr_y += 35) {
            vTextEdits->push_back(new QTextEdit(this));
            vTextEdits->operator [](i)->setGeometry(g_xpos, g_ypos + incr_y, g_w, g_h);
            vTextEdits->operator [](i)->setAttribute(Qt::WA_DeleteOnClose);
            vTextEdits->operator [](i)->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            vTextEdits->operator [](i)->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            vTextEditsNumbers->push_back(new QTextEdit(this));
            for (uint j = 0; j < vTextEditsNumbers->size(); j++) {
                if (ui->spinBox_2->value() > 1)
                    vTextEditsNumbers->operator [](i)->setGeometry(g_xpos + 210, g_ypos + incr_y,30*ui->spinBox_2->value(), g_h);
                else
                    vTextEditsNumbers->operator [](i)->setGeometry(g_xpos + 210, g_ypos + incr_y,30, g_h);
            }
            vTextEditsNumbers->operator [](i)->setAttribute(Qt::WA_DeleteOnClose);
            vTextEditsNumbers->operator [](i)->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
            vTextEditsNumbers->operator [](i)->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        }
        prev_objNum = objNum;
    }
    else {
        for (int i = vTextEdits->size() - 1; i >= objNum; i--, incr_y -= 35) {
            vTextEdits->pop_back();
            vTextEditsNumbers->pop_back();
            delete(vTextEdits->operator [](i));
            delete(vTextEditsNumbers->operator [](i));
        }
        prev_objNum = objNum;
    }
    for (int i = 0; i < objNum; i++) {
        vTextEdits->operator [](i)->show();
        vTextEditsNumbers->operator [](i)->show();
    }
}
void Widget::on_spinBox_2_valueChanged(int numPerObj)
{
    int defaultEdit_width = 30;
    if (numPerObj >= 1) {
        for (uint i = 0; i < vTextEditsNumbers->size(); i++)
            vTextEditsNumbers->operator [](i)->resize(defaultEdit_width * numPerObj, 30);
    }
}

void Widget::on_pushButton_clicked()
{
    // TODO:
    // Check if all Edits've been fill
    // Exception if there are excess numbers
//    const int NUMBER_OF_STUDENTS = 4;
//    const int NUMBER_OF_TICKETS = 20;
//    const int TICKETS_PER_STUDENT = 5;
//    Randomizer a(students, NUMBER_OF_STUDENTS, NUMBER_OF_TICKETS, TICKETS_PER_STUDENT);
    for (uint i = 0; i < vTextEditsNumbers->size(); ++i) {
        vTextEditsNumbers->operator [](i)->clear();
    }
    vstring Objects;
    for (uint i = 0; i < vTextEdits->size(); ++i) {
        Objects.push_back((vTextEdits->operator [](i)->toPlainText()).toStdString());
    }
    int number_of_objects = vTextEdits->size();
    int min_range = ui->spinBox_3->value();
    int max_range = ui->spinBox_4->value();
    int numbers_per_object = ui->spinBox_2->value();
    Randomizer *obj = new Randomizer(Objects, number_of_objects, min_range, max_range, numbers_per_object);
    for (uint i = 0; i < vTextEditsNumbers->size(); ++i) {
        for (uint j = 0; j < obj->getSecond(i).size();  j++) {
            vTextEditsNumbers->operator [](i)->moveCursor(QTextCursor::End);
            vTextEditsNumbers->operator [](i)->insertPlainText(QString::number(obj->getSecond(i).operator [](j)));
            vTextEditsNumbers->operator [](i)->insertPlainText(QString(2, ' '));
        }
    }
//    for (int i = 0; i < vTextEditsNumbers->size(); i++) {
//        vTextEditsNumbers->operator [](i)->show();
//    }
    delete obj;
}
