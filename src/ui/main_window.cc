#include <ui/main_window.h>

#include "./ui_main_window.h"

namespace ui {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}, ui_{new Ui::MainWindow} {
  ui_->setupUi(this);
}

void MainWindow::on_ConnectToConsole_triggered() {
  // TODO: display some kind of window to input IP address and connect
  const auto kIP =
      QInputDialog::getText(this, "Enter Console Address", "Enter console IP:");

  if (kIP.isEmpty()) return;

  // create socket and bind connected handler
  socket_ = new QTcpSocket{this};
  connect(socket_, &QTcpSocket::connected, this,
          &MainWindow::CreateConsolePane);

  // begin connecting
  socket_->connectToHost(kIP, XBRPC_PORT);

  // block on join with timeout
  if (!socket_->waitForConnected(2000)) {
    QMessageBox msg;
    msg.critical(this, "Error connecting", "Failed to connect to console!");
  }
}

void MainWindow::CreateConsolePane() {
  if (socket_ && socket_->isOpen()) {
    ui_->tabs->addTab(new CallPane{socket_, this}, QIcon{":/xbox.png"},
                      socket_->peerName());

    disconnect(socket_, &QTcpSocket::connected, this,
               &MainWindow::CreateConsolePane);
  }

  // nullify, TODO: get STL to play nicely with this project
  socket_ = {};
}

MainWindow::~MainWindow() { delete ui_; }

}  // namespace ui
