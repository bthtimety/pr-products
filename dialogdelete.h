/*диалоговое окно, открывающееся при удалении отдельной записи в файле*/

#ifndef DIALOGDELETE_H
#define DIALOGDELETE_H

#include <QDialog>

namespace Ui {
    class dialogDelete;
}

/**
 * @brief The dialogDelete class - класс для выбора удаляемой строки
 */

class dialogDelete : public QDialog
{
    Q_OBJECT

public:

    /**
     * @brief dialogDelete - конструктор класса для выбора удаляемой строки
     * @param parent - указатель на родитель объекта
     */

    explicit dialogDelete(QWidget *parent = nullptr);
    ~dialogDelete();

    /**
     * @brief num - возвращает номер удаляемой строки
     * @return номер удаляемой строки
     */

    int num(); //получает номер строки, которую пользователь хочет удалить

private slots:

    /**
     * @brief on_pushButtonOk_clicked - кнопка ОК, принятие значения
     */

    void on_pushButtonOk_clicked();

    /**
     * @brief on_pushButtonCancel_clicked - кнопка Cancel, отмена выбора
     */

    void on_pushButtonCancel_clicked();

private:
    Ui::dialogDelete *ui;
};

#endif // DIALOGDELETE_H
