#include <ui/main_window.h>
#include "./ui_main_window.h"

namespace ui {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}, ui_{new Ui::MainWindow} {
  ui_->setupUi(this);

  ui_->tabs->addTab(new CallPane{this}, QIcon{":/xbox.png"}, "192.168.1.147");
}

void ui::MainWindow::on_ConnectToConsole_triggered() {
    // TODO: display some kind of window to input IP address and connect
}

MainWindow::~MainWindow() { delete ui_; }

}  // namespace ui
