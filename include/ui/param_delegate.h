#ifndef PARAMDELEGATE_H
#define PARAMDELEGATE_H

#include <QComboBox>
#include <QDebug>
#include <QItemDelegate>
#include <QObject>

namespace ui {

// TODO: rename to something more specific
class ParamDelegate final : public QItemDelegate {
 public:
  ParamDelegate(QObject *parent = {});

  QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                        const QModelIndex &index) const override;
  void setEditorData(QWidget *editor, const QModelIndex &index) const override;
  void setModelData(QWidget *editor, QAbstractItemModel *model,
                    const QModelIndex &index) const override;
  void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                            const QModelIndex &index) const override;

 private:
  QVector<QString> options_;
};

}  // namespace ui

#endif  // PARAMDELEGATE_H
