/*диалоговое окно, открывающееся при изменении отдельной записи в файле*/

#ifndef DIALOGEDIT_H
#define DIALOGEDIT_H

#include <QDialog>

namespace Ui {
    class dialogEdit;
}

class dialogEdit : public QDialog
{
    Q_OBJECT

public:
    explicit dialogEdit(QWidget *parent = nullptr);
    ~dialogEdit();

    int num(); //получает номер строки, которую пользователь хочет изменить

private slots:
    void on_pushButtonOk_clicked();
    void on_pushButtonCancel_clicked();

private:
    Ui::dialogEdit *ui;
};

#endif // DIALOGEDIT_H
