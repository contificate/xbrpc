#ifndef ARGPACKER_H
#define ARGPACKER_H

#include <mpack/mpack.h>

class ArgPacker {
 public:
  ArgPacker();
  ~ArgPacker();

 private:
  mpack_writer_t writer_;
  char* buffer_{};
  size_t size_;
};

#endif  // ARGPACKER_H
