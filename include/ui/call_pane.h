#ifndef CALL_PANE_H
#define CALL_PANE_H

#include <rpc/rpc.h>
#include <ui/param_delegate.h>
#include <mpack/mpack.h>

#include <QDebug>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QTcpSocket>
#include <QWidget>
#include <QFile>

#include "ui_call_pane.h"

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

  void on_callBtn_clicked();

 private:
  Ui::CallPane *ui_;
  QStandardItemModel *model_;
  QTcpSocket *socket_;
};
}  // namespace ui

#endif  // CALL_PANE_H
