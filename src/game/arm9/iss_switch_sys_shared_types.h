#ifndef ISS_SWITCH_SYS_SHARED_TYPES_H
#define ISS_SWITCH_SYS_SHARED_TYPES_H

struct IssSwitchSet;

struct IssSwitchSet;

struct IssSwitchSet;

struct IssSwitchSet;

struct IssSwitchSet;

struct IssSwitch;

struct IssSwitch;

#include "../types.h"

struct IssSwitchSet {
    u32 bgmNo;
    u16 zones[9];
    u8  zoneCount;
    u8  pad_17;
    struct IssSwitch *switches[9];
};

#endif
