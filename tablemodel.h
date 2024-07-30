/* класс модели, в которую будут помещены данные */

#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include "mainwindow.h"
#include "concreteproducts.h"

#include <QAbstractTableModel>
#include <QList>

/**
 * @brief The tableModel class - класс модели данных
 */

class tableModel : public QAbstractTableModel
{
    Q_OBJECT
public:

    /**
     * @brief tableModel - конструктор класса модели данных
     * @param parent - указатель на родителя объекта
     */

    explicit tableModel(QObject *parent = nullptr);

    /**
     * @brief list - указатель на класс concreteProducts
     */

    QList <concreteProducts> list; //хранилище

    /**
     * @brief countOfColumns - количество колонок
     */

    const int countOfColumns; //количество колонок

    /**
     * @brief newModel - функция обновления содержимого модели
     */

    void newModel(); //обновление содержимого модели

    // QAbstractItemModel interface
public:

    /**
     * @brief rowCount - фунция, возвращающая количество строк
     * @param parent - указатель на родителя объекта
     * @return количество строк
     */

    int rowCount(const QModelIndex &parent) const override; //возвращает кол-во строк

    /**
     * @brief columnCount - фунция, возвращающая количество столбцов
     * @param parent - указатель на родителя объекта
     * @return количество столбцов
     */

    int columnCount(const QModelIndex &parent) const override; //возвращает кол-во столбцов

    /**
     * @brief data - функция, возвращающая данные ячейки
     * @param index - индекс ячейки
     * @param role - переменная, показывающая, в каком качестве был вызван метод
     * @return данные ячейки
     */

    QVariant data(const QModelIndex &index, int role) const override; //возвращает данные ячейки

    /**
     * @brief setData - функция вставления данных при редактировании ячейки
     * @param index - индекс ячейки
     * @param value - значение
     * @param role - переменная, показывающая, в каком качестве был вызван метод
     * @return данные ячейки
     */

    bool setData(const QModelIndex &index, const QVariant &value, int role) override; //вставляет данные

    /**
     * @brief headerData - функция, которая задает значения заголовков
     * @param section - для задания значения строк и столбцов
     * @param orientation - ориентация: горизонтально, вертикально
     * @param role - переменная, показывающая, в каком качестве был вызван метод
     * @return значения заголовков
     */

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override; //заголовки

    /**
     * @brief flags - задает правила работы ячейки таблицы
     * @param index - индекс ячейки
     * @return значение флага
     */

    Qt::ItemFlags flags(const QModelIndex &index) const override; //задает правила раьоты ячейки
};

#endif // TABLEMODEL_H
