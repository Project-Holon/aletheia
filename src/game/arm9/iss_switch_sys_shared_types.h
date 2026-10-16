#ifndef ISS_SWITCH_SYS_SHARED_TYPES_H
#define ISS_SWITCH_SYS_SHARED_TYPES_H

struct IssSwitchSet;

struct IssSwitchSet;

struct IssSwitchSet;

struct IssSwitchSet;

struct IssSwitchSet;

struct IssSwitch;

struct IssSwitch;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int  u32;

struct IssSwitchSet {
    u32 bgmNo;
    u16 zones[9];
    u8  zoneCount;
    u8  pad_17;
    struct IssSwitch *switches[9];
};

#endif
