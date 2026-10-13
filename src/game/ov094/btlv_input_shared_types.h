#ifndef BTLV_INPUT_SHARED_TYPES_H
#define BTLV_INPUT_SHARED_TYPES_H

#include "btlv_effvm_types.h"

struct Cfg;

typedef struct { char pad[0x68]; unsigned int f68; } W_02206710;

typedef struct { s16 x, y, z; u8 pri, f7; } Cfg;

#endif
