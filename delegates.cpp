#include "delegates.h"

#include <QComboBox>
#include <QMouseEvent>
#include <QAbstractItemView>
#include <QDebug>
#include <QTableView>

delegates::delegates(QWidget *parent):
    QStyledItemDelegate(parent) {

}

QWidget *delegates::createEditor(QWidget *parent,
                                          const QStyleOptionViewItem &option,
                                          const QModelIndex &index) const
{
      Q_UNUSED(option);
      Q_UNUSED(index);
      QComboBox *comboBox = new QComboBox(parent);

      comboBox->addItems(listOptions);
      comboBox->setCurrentIndex(0);

      return comboBox;
}

void delegates::setEditorData(QWidget *editor,
                                   const QModelIndex &index) const
{
  QComboBox *comboBox = qobject_cast<QComboBox *>(editor);
  comboBox->setCurrentText(index.data().toString());
}

void delegates::setModelData(QWidget *editor,
                                  QAbstractItemModel *model,
                                  const QModelIndex &index) const
{
  QComboBox *comboBox = qobject_cast<QComboBox *>(editor);
  model->setData(index, comboBox->currentText());
}

void delegates::updateEditorGeometry(QWidget *editor,
                                          const QStyleOptionViewItem &option,
                                          const QModelIndex &index) const
{
  Q_UNUSED(index);
  editor->setGeometry(option.rect);
}

bool delegates::editorEvent(QEvent *event,
                                 QAbstractItemModel *model,
                                 const QStyleOptionViewItem &option,
                                 const QModelIndex &index)
{
  Q_UNUSED(option);

  if (event->type() == QEvent::MouseButtonRelease) {
      if (static_cast<QMouseEvent *>(event)->button() == Qt::LeftButton) {
          QWidget *widget = const_cast<QWidget *>(option.widget);
          QAbstractItemView* itemView = qobject_cast<QAbstractItemView *>(widget);

          if (itemView != nullptr) {
              itemView->setCurrentIndex(index);
              itemView->edit(index);
          }
          return true;
      }
  }
  return false;
}

void delegates::setData(const QStringList &strList)
{
  listOptions = strList;
}
