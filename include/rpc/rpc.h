#ifndef RPC_H
#define RPC_H

#include <stdint.h>

#define XBRPC_PORT 1337

enum class ParamType : uint32_t { kInt, kFloat, kString };
enum class RPCTag : uint32_t { kDisconnect, kCall };

#endif  // RPC_H
