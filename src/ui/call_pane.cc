#include <ui/call_pane.h>

#include "ui_call_pane.h"

namespace ui {

CallPane::CallPane(QTcpSocket* socket, QWidget* parent)
    : QWidget{parent},
      ui_{new Ui::CallPane},
      model_{new QStandardItemModel{{}, 2}},
      socket_{socket} {
  // socket_->setParent(this);
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

void CallPane::on_callBtn_clicked() {
  QMessageBox box;

  // attempt to parse address
  bool parsedAddr{};
  const uint32_t kAddr = ui_->addrEdit->text().toUInt(&parsedAddr, 16);
  if (!parsedAddr) {
    box.critical(this, "Parse failure", "Failed to parse address!");
    return;
  }

  // initialise writer
  mpack_writer_t writer;
  size_t size;
  char* buffer;
  mpack_writer_init_growable(&writer, &buffer, &size);

  // write the rpc action tag
  mpack_write_u32(&writer, static_cast<uint32_t>(RPCTag::kCall));

  // begin argument array
  const auto kArgCount = model_->rowCount();
  mpack_start_array(&writer, static_cast<uint32_t>(kArgCount) + 1);

  // write the address
  mpack_write_u32(&writer, kAddr);

  for (int i = 0; i < kArgCount; i++) {
    // get the argument type
    const auto kType =
        static_cast<ParamType>(model_->index(i, 0).data().toInt());

    // get the argument's value as a string
    const auto kData = model_->index(i, 1).data().toString();
    qDebug() << "Packing " << kData << '\n';

    // pack dependent on type
    switch (kType) {
      case ParamType::kInt: {
        qDebug() << "int\n";
        mpack_write_int(&writer, kData.toInt());
        break;
      }
      case ParamType::kFloat: {
        qDebug() << "float\n";
        mpack_write_float(&writer, kData.toFloat());
        break;
      }
      case ParamType::kString: {
        qDebug() << "string\n";
        mpack_write_cstr(&writer, kData.toStdString().c_str());
        break;
      }
    }
  }

  // pack the array
  mpack_finish_array(&writer);

  // pack the entire buffer
  if (mpack_writer_destroy(&writer) != mpack_ok) {
    box.critical(this, "Packing failure",
                 "Failed to pack arguments in buffer!");
    return;
  }

  // just a hack, TODO: assign handlers and form blocking
  socket_->write(buffer, static_cast<qint64>(size));
}

CallPane::~CallPane() {
  delete ui_;
  delete model_;
}

}  // namespace ui
