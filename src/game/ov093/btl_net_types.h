#ifndef BTL_NET_TYPES_H
#define BTL_NET_TYPES_H
/* ov093 battle net: the in-battle Pokemon record and its move slots. */

#ifndef OV093_BASIC_TYPES
#define OV093_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
#endif

/* 14-byte net record: two bytes, six flag bits, five halfwords. */
struct BtlNetEntry {
    u8 b0;
    u8 b1;
    u8 f0 : 1;
    u8 f1 : 1;
    u8 f2 : 1;
    u8 f3 : 1;
    u8 f4 : 1;
    u8 f5 : 1;
    u8 pad3;
    u16 h4;
    u16 h6;
    u16 h8;
    u16 h10;
    u16 h12;
};

/* Battle net script context: reached by the command handlers. */
struct BtlNetCtx {
    void *f00;
    void *f04;
    u8 pad08[0x34 - 8];
    void *f34;
    u8 pad38[0x118 - 0x38];
    u32 f118;
    u8 pad11c[0x1a6 - 0x11c];
    u8 f1a6;
    u8 pad1a7[4];
    u8 f1ab;
};
#endif
