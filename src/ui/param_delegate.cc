#include <ui/param_delegate.h>

namespace ui {

ParamDelegate::ParamDelegate(QObject *parent)
    : QItemDelegate{parent}, options_{"int", "float", "string"} {}

QWidget *ParamDelegate::createEditor(QWidget *parent,
                                     const QStyleOptionViewItem &option,
                                     const QModelIndex &index) const {
  Q_UNUSED(option)
  Q_UNUSED(index)

  auto *box = new QComboBox(parent);
  for (const auto &o : options_) box->addItem(o);
  return box;
}

void ParamDelegate::setEditorData(QWidget *editor,
                                  const QModelIndex &index) const {
  auto *box = static_cast<QComboBox *>(editor);
  box->setCurrentIndex(index.model()->data(index, Qt::EditRole).toInt());
}

void ParamDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                 const QModelIndex &index) const

{
  auto *box = static_cast<QComboBox *>(editor);
  model->setData(index, QVariant::fromValue(box->currentIndex()));
}

void ParamDelegate::updateEditorGeometry(QWidget *editor,
                                         const QStyleOptionViewItem &option,
                                         const QModelIndex &index) const {
  Q_UNUSED(index)
  editor->setGeometry(option.rect);
}

}  // namespace ui
