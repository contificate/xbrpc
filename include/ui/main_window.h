#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ui/call_pane.h>

#include <QDebug>
#include <QMainWindow>
#include <QInputDialog>

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

 private:
  Ui::MainWindow *ui_;
};

}  // namespace ui

#endif  // MAINWINDOW_H
