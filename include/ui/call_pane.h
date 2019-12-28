#ifndef CALL_PANE_H
#define CALL_PANE_H

#include <ui/param_delegate.h>

#include <QDebug>
#include <QStandardItemModel>
#include <QWidget>

namespace Ui {
class CallPane;
}

namespace ui {

class CallPane final : public QWidget {
  Q_OBJECT

 public:
  explicit CallPane(QWidget *parent = {});
  ~CallPane();

 private slots:
  void on_addParam_clicked();
  void on_removeParam_clicked();

 private:
  Ui::CallPane *ui_;
  QStandardItemModel *model_;
};
}  // namespace ui

#endif  // CALL_PANE_H
