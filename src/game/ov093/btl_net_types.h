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

union BtlMonSlot {
    u32 raw;
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
};

/* One half of a move slot: move id, PP, PP maximum, PP ups and two counters. */
struct BtlMoveInfo {
    u16 id;
    u8 pp;
    u8 ppMax;
    u8 ppUp;
    u8 lo : 4;
    u8 hi : 4;
};

/* One move slot, 14 bytes: the current state, then a saved copy of it. */
struct BtlMoveSlot {
    union {
        u16 h[6];
        struct {
            struct BtlMoveInfo cur;
            struct BtlMoveInfo saved;
        };
    };
    u8 fC;
    u8 fD;
};

struct BtlMon {
    void *f00;
    void *f04;
    u32 f08;
    u16 f0c;
    u16 f0e;
    u16 f10;
    u16 f12;
    u16 f14;
    u16 f16;
    u8 f18;
    u8 f19;
    u8 f1a;
    u8 lo : 5;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
    union BtlMonSlot w1c[40];
    u8 padBC[0xee - 0xbc];
    u16 fee;
    u16 ff0;
    u16 ff2;
    u16 ff4;
    u16 ff6;
    u8 ff8;
    u8 ff9;
    u8 ffa;
    u8 padFB;
    union {
        u8 f0fc[8];
        struct {
            s8 ffc;
            s8 ffd;
            s8 ffe;
            s8 fff;
            u8 f100;
            s8 f101;
            s8 f102;
        };
    };
    struct BtlMoveSlot e[4];
    u16 f13c;
    u16 f13e;
    u8 n140;
    u8 f141;
    u8 f142;
    u8 f143;
    u8 f144;
    u8 pad145;
    u16 f146;
    u16 f148;
    u16 f14a;
    u16 f14c;
    u16 f14e;
    u8 pad150[2];
    u8 f152;
    u8 f153[2];
    u8 f155[2];
    u8 f157[5];
    u8 pad15c[0x1f2 - 0x15c];
    u16 f1f2;
    u16 f1f4;
    u8 f1f6;
    u8 pad1f7;
};

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
