/*диалоговое окно, открывающееся при изменении отдельной записи в файле*/

#ifndef DIALOGEDIT_H
#define DIALOGEDIT_H

#include <QDialog>

namespace Ui {
    class dialogEdit;
}

/**
 * @brief The dialogEdit class - класс для выбора редактируемой строки
 */

class dialogEdit : public QDialog
{
    Q_OBJECT

public:

    /**
     * @brief dialogEdit - конструктор класса для выбора редактируемой строки
     * @param parent - указатель на родитель объекта
     */

    explicit dialogEdit(QWidget *parent = nullptr);
    ~dialogEdit();

    /**
     * @brief num - возвращает номер редактируемой строки
     * @return номер редактируемой строки
     */\

    int num(); //получает номер строки, которую пользователь хочет изменить

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
    Ui::dialogEdit *ui;
};

#endif // DIALOGEDIT_H
