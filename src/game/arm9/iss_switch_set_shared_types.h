#ifndef ISS_SWITCH_SET_SHARED_TYPES_H
#define ISS_SWITCH_SET_SHARED_TYPES_H

#include "../arm9/iss_switch_sys_shared_types.h"

#include "../types.h"

struct IssSwitch {
    u32 state;
    u16 fadeCount;
    u16 fadeFrames;
    u16 trackBits;
    u8  pad_0A[2];
};

#endif
