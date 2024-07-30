/*диалоговое окно, открывающееся в режиме добавления/редактирования записи в файле*/

#ifndef DIALOGREDACTION_H
#define DIALOGREDACTION_H

#include <mainwindow.h>

#include <QDialog>
#include <QMessageBox>

namespace Ui {
    class dialogRedaction;
}

/**
 * @brief The dialogRedaction class - класс, в котором происходит редактирование/добавление записи
 */

class dialogRedaction : public QDialog
{
    Q_OBJECT

public:

    /**
     * @brief Row - строка
     */

    concreteProducts Row;

    /**
     * @brief dialogRedaction - конструктор класса для редактирования/добавления данных
     * @param parent - указатель на родитель объекта
     */

    explicit dialogRedaction(QWidget *parent = nullptr);
    ~dialogRedaction();

    /**
     * @brief newData - функция, которая добавляет новые данные в таблицу
     */

    void newData();

    /**
     * @brief setRow - для принятия новых значений
     * @param lRow - объект класса
     */

    void setRow(const concreteProducts lRow);

    /**
     * @brief getRow - возвращения новых данных
     * @return новые данные
     */

    concreteProducts getRow() const;

private slots:

    /**
     * @brief on_pushButtonOk_clicked - кнопка ОК, принятие новых значений
     */

    void on_pushButtonOk_clicked();

    /**
     * @brief on_pushButtonCancel_clicked - кнопка Cancel, отмена редактирования/добавления
     */

    void on_pushButtonCancel_clicked();

private:
    Ui::dialogRedaction *ui;
};

#endif // DIALOGREDACTION_H
