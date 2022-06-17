/*диалоговое окно, открывающееся в режиме добавления/редактирования записи в файле*/

#ifndef DIALOGREDACTION_H
#define DIALOGREDACTION_H

#include <mainwindow.h>

#include <QDialog>
#include <QMessageBox>

namespace Ui {
    class dialogRedaction;
}

class dialogRedaction : public QDialog
{
    Q_OBJECT

public:
    concreteProducts Row;

    explicit dialogRedaction(QWidget *parent = nullptr);
    ~dialogRedaction();

    void newData();
    void setRow(const concreteProducts lRow);
    concreteProducts getRow() const;

private slots:
    void on_pushButtonOk_clicked();
    void on_pushButtonCancel_clicked();

private:
    Ui::dialogRedaction *ui;
};

#endif // DIALOGREDACTION_H
