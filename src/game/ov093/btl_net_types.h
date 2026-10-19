#ifndef BTL_NET_TYPES_H
#define BTL_NET_TYPES_H
/* ov093 battle net: the in-battle Pokemon record and its move slots. */

#include "../types.h"

/* 14-byte net record: two bytes, six flag bits, five halfwords. */
struct BtlNetEntry {
    u8 b0;
    u8 b1;
    u8 reserved0 : 1;
    u8 reserved1 : 1;
    u8 reserved2 : 1;
    u8 reserved3 : 1;
    u8 reserved4 : 1;
    u8 reserved5 : 1;
    u8 pad3;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 h10;
    u16 h12;
};

/* Battle net script context: reached by the command handlers. */
struct BtlNetCtx {
    void *reserved00;
    void *reserved04;
    u8 pad08[0x34 - 8];
    void *reserved34;
    u8 pad38[0x118 - 0x38];
    u32 reserved118;
    u8 pad11c[0x1a6 - 0x11c];
    u8 reserved1a6;
    u8 pad1a7[4];
    u8 reserved1ab;
};
#endif
