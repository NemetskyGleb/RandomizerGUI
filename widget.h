#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include "randomizer.h"
#include <vector>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    std::vector<QTextEdit*> *vTextEdits = new std::vector<QTextEdit*>;
    std::vector<QTextEdit*> *vTextEditsNumbers = new std::vector<QTextEdit*>;
    ~Widget();
    QTextEdit a;

private slots:
    void on_spinBox_valueChanged(int objNum);

    void on_spinBox_2_valueChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
