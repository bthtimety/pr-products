#ifndef DELEGATES_H
#define DELEGATES_H

#include <QStyledItemDelegate>

/**
 * @brief The delegates class - класс для редактирования ячеек таблицы
 */

class delegates : public QStyledItemDelegate
{
    Q_OBJECT

    /**
     * @brief listOptions - переменная, хранящая список значений для выбора
     */

    QStringList listOptions;

public:

    /**
     * @brief delegates - конструктор класса для редактирования ячеек таблицы
     * @param parent - указатель на родителя объекта
     */

    explicit delegates(QWidget *parent = nullptr);

    /**
     * @brief createEditor - метод, создающий виджет-редактор со списком
     * @param parent - указатель на родителя объекта
     * @param option - варианты выбора
     * @param index - индекс списка
     * @return возвращает редактор-виджет
     */

    QWidget *createEditor(QWidget *parent,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;

    /**
     * @brief setEditorData - метод, передающий значение из таблицы в виджет-редактор
     * @param editor - указатель, через который приходят разные объекты
     * @param index - индекс списка
     */

    void setEditorData(QWidget *editor,
                           const QModelIndex &index) const override;

    /**
     * @brief setModelData - метод, передающий значение из виджета-редактора в таблицу
     * @param editor - указатель, через который приходят разные объекты
     * @param model - указатель на таблицу с данными
     * @param index - индекс списка
     */

    void setModelData(QWidget *editor,
                          QAbstractItemModel *model,
                          const QModelIndex &index) const override;

    /**
     * @brief updateEditorGeometry - метод, определяющий расположение виджета-редактора в таблице
     * @param editor - указатель, через который приходят разные объекты
     * @param option - варианты выбора
     * @param index - индекс списка
     */

    void updateEditorGeometry(QWidget *editor,
                                  const QStyleOptionViewItem &option,
                                  const QModelIndex &index) const override;

    /**
     * @brief editorEvent - метод, описывающий поведение ячейки как реакции на возникающие события
     * @param event - событие
     * @param model - указатель на таблицу с данными
     * @param option - варианты выбора
     * @param index - индекс списка
     * @return передача информации оператору, который вызывал метод
     */

    bool editorEvent(QEvent *event,
                         QAbstractItemModel *model,
                         const QStyleOptionViewItem &option,
                         const QModelIndex &index);

    //метод, передающий диапазон значений в переменную listOptions.
    //позволяет задать варианты в comboBox для выбора пользователем
    //в таблице
    /**
     * @brief setData - метод, позволяющий задать варианты для выбора пользователем
     * @param strList - для вариантов на выбор в выпадающем списке
     */

    void setData(const QStringList &strList);
};

#endif // DELEGATES_H
