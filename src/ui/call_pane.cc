#include <ui/call_pane.h>

#include "ui_call_pane.h"

namespace ui {

CallPane::CallPane(QTcpSocket* socket, QWidget* parent)
    : QWidget{parent},
      ui_{new Ui::CallPane},
      model_{new QStandardItemModel{{}, 2}},
      socket_{socket} {
  socket_->setParent(this);
  ui_->setupUi(this);

  // TODO: connect socket handlers

  // enable model and delegate
  ui_->argTable->setModel(model_);
  ui_->argTable->setItemDelegateForColumn(0, new ParamDelegate{this});

  // set table column headers
  QStringList columns;
  columns << "Type"
          << "Data";
  model_->setHorizontalHeaderLabels(columns);
}

void CallPane::on_addParam_clicked() {
  // add default parameter entry
  model_->appendRow({});

  // ensure its delegate is visible
  ui_->argTable->openPersistentEditor(
      model_->index((model_->rowCount() - 1), 0));
}

void CallPane::on_removeParam_clicked() {
  // get selection model for table
  auto* selectionModel = ui_->argTable->selectionModel();

  // remove selected rows
  if (selectionModel->hasSelection()) {
    // get the selected rows and sort them
    auto rows = selectionModel->selectedRows();
    std::sort(rows.begin(), rows.end());

    // remove backwards to avoid relative index offset shifting
    for (auto it = rows.rbegin(); it != rows.rend(); ++it)
      model_->removeRow((*it).row());
  }
}

CallPane::~CallPane() {
  delete ui_;
  delete model_;
}

}  // namespace ui
