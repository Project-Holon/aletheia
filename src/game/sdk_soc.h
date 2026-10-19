#ifndef GAME_SDK_SOC_H
#define GAME_SDK_SOC_H

#include "types.h"

/* Socket address types of the SDK network socket layer (SOC). */

typedef struct SOCInAddr {
    u32 addr;
} SOCInAddr;

typedef struct SOCSockAddrIn {
    u8 len;
    u8 family;
    u16 port;
    u32 addr;
} SOCSockAddrIn;

typedef struct SOCHostEnt {
    char *name;
    char **aliases;
    s16 addrType;
    s16 length;
    u8 **addrList;
} SOCHostEnt;

#endif
