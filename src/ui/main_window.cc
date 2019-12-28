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
  const auto kIP =
      QInputDialog::getText(this, "Enter Console Address", "Enter console IP:");

  // TODO: connect to console, create new tab on signal, transfer socket
  // ownership
}

MainWindow::~MainWindow() { delete ui_; }

}  // namespace ui
