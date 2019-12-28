#ifndef CALL_PANE_H
#define CALL_PANE_H

#include <ui/param_delegate.h>

#include <QDebug>
#include <QStandardItemModel>
#include <QTcpSocket>
#include <QWidget>

namespace Ui {
class CallPane;
}

namespace ui {

class CallPane final : public QWidget {
  Q_OBJECT

 public:
  CallPane(QTcpSocket *socket, QWidget *parent = {});
  ~CallPane();

 private slots:
  void on_addParam_clicked();
  void on_removeParam_clicked();

 private:
  Ui::CallPane *ui_;
  QStandardItemModel *model_;
  QTcpSocket *socket_;
};
}  // namespace ui

#endif  // CALL_PANE_H
