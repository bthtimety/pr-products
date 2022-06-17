#ifndef DELEGATES_H
#define DELEGATES_H

#include <QStyledItemDelegate>

class delegates : public QStyledItemDelegate
{
    Q_OBJECT

    QStringList listOptions;

public:
    explicit delegates(QWidget *parent = nullptr);
    QWidget *createEditor(QWidget *parent,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;
    //метод, передающий значение из таблицы в виджет-редактор
    void setEditorData(QWidget *editor,
                           const QModelIndex &index) const override;
    //метод, передающий значение из виджета-редактора в таблицу
    void setModelData(QWidget *editor,
                          QAbstractItemModel *model,
                          const QModelIndex &index) const override;
    //метод, определяющий расположение виджета-редактора в таблице
    void updateEditorGeometry(QWidget *editor,
                                  const QStyleOptionViewItem &option,
                                  const QModelIndex &index) const override;

    //метод, описывающий поведение ячейки как реакции на возникающие события
    bool editorEvent(QEvent *event,
                         QAbstractItemModel *model,
                         const QStyleOptionViewItem &option,
                         const QModelIndex &index);

    //метод, передающий диапазон значений в переменную listOptions.
    //позволяет задать варианты в comboBox для выбора пользователем
    //в таблице
    void setData(const QStringList &strList);
};

#endif // DELEGATES_H
