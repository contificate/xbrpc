#include <ui/main_window.h>

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  // show primary view
  ui::MainWindow w;
  w.show();

  return app.exec();
}
