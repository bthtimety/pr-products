#include "tablemodel.h"
#include "mainwindow.h"
#include "dialogredaction.h"

tableModel::tableModel(QObject *parent) :
    QAbstractTableModel(parent),
    countOfColumns(7)
{

}

void tableModel::newModel()
{
    emit layoutChanged();
}

int tableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent); //установим кол-во строк столько же, сколько элементов с списке list
    return list.count();
}

int tableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return countOfColumns;
}

QVariant tableModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();
    if (index.isValid() && !list.isEmpty()) {
        switch (role) {
        case Qt::DisplayRole :
        case Qt::EditRole :
            switch (col) {
                case 0: return list.at(row).getID(); break;
                case 1: return list.at(row).getName(); break;
                case 2: return list.at(row).getProducer(); break;
                case 3: return list.at(row).getArticle(); break;
                case 4: return list.at(row).getSum(); break;
                case 5: return list.at(row).getWeight(); break;
                case 6: return list.at(row).getPrice();  break;
            }
            break;
        default:
            return QVariant(); //для всех остальных случаев выдать недопустимый вариант (invalid)
        }
    }
    return QVariant(); //для всех остальных случаев выдать недопустимый вариант (invalid)
}

bool tableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    int row = index.row();
    int col = index.column();
    if (role == Qt::EditRole) {
        if (!index.isValid())
            return false;
        switch (col) {
            case 0: list[row].setID(value.toInt()); break;
            case 1: list[row].setName(value.toString()); break;
            case 2: list[row].setProducer(value.toString()); break;
            case 3: list[row].setArticle(value.toString()); break;
            case 4: list[row].setSum(value.toInt()); break;
            case 5: list[row].setWeight(value.toInt()); break;
            case 6: list[row].setPrice(value.toInt()); break;
        }
        return true;
    }
    return false;
}

QVariant tableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    //задаем заголовки столбцов
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch (section) {
            case 0: return QString("ID"); //id
            case 1: return QString(tr("Name")); //наименование
            case 2: return QString(tr("Producer")); //производитель
            case 3: return QString(tr("Article")); //артикул
            case 4: return QString(tr("Summary")); //количество
            case 5: return QString(tr("Weight")); //вес
            case 6: return QString(tr("Price")); //цена
        }
    }
    if (orientation == Qt::Vertical && role == Qt::DisplayRole)
    return QString::number(section + 1);
    return QVariant();
}

Qt::ItemFlags tableModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractTableModel::flags(index);
    flags |= Qt::ItemIsEditable | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled;
    return flags;
}
