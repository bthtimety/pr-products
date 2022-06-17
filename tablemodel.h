/* класс модели, в которую будут помещены данные */

#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include "mainwindow.h"
#include "concreteproducts.h"

#include <QAbstractTableModel>
#include <QList>

class tableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit tableModel(QObject *parent = nullptr);

    QList <concreteProducts> list; //хранилище
    const int countOfColumns; //количество колонок
    void newModel(); //обновление содержимого модели

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override; //возвращает кол-во строк
    int columnCount(const QModelIndex &parent) const override; //возвращает кол-во столбцов
    QVariant data(const QModelIndex &index, int role) const override; //возвращает данные ячейки
    bool setData(const QModelIndex &index, const QVariant &value, int role) override; //вставляет данные
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override; //заголовки
    Qt::ItemFlags flags(const QModelIndex &index) const override; //задает правила раьоты ячейки
};

#endif // TABLEMODEL_H
