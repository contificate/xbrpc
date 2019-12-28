#include <mpack/arg_packer.h>

ArgPacker::ArgPacker() {
  mpack_writer_init_growable(&writer_, &buffer_, &size_);
}

ArgPacker::~ArgPacker() {
  mpack_writer_destroy(&writer_);
  delete buffer_;
}
