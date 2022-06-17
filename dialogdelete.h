/*диалоговое окно, открывающееся при удалении отдельной записи в файле*/

#ifndef DIALOGDELETE_H
#define DIALOGDELETE_H

#include <QDialog>

namespace Ui {
class dialogDelete;
}

class dialogDelete : public QDialog
{
    Q_OBJECT

public:
    explicit dialogDelete(QWidget *parent = nullptr);
    ~dialogDelete();

    int num(); //получает номер строки, которую пользователь хочет удалить

private slots:
    void on_pushButtonOk_clicked();
    void on_pushButtonCancel_clicked();

private:
    Ui::dialogDelete *ui;
};

#endif // DIALOGDELETE_H
