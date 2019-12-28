#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <rpc/rpc.h>
#include <ui/call_pane.h>

#include <QDebug>
#include <QInputDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace ui {

class MainWindow final : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = {});
  ~MainWindow();

 private slots:
  void on_ConnectToConsole_triggered();
  void CreateConsolePane();

 private:
  Ui::MainWindow *ui_;
  QTcpSocket *socket_;
};

}  // namespace ui

#endif  // MAINWINDOW_H
