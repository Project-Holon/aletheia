#ifndef UNIT_021B3018_TYPES_H
#define UNIT_021B3018_TYPES_H
/* ov013 0x021B3018 unit: voice-activity gate and TCV packet filter, shared types. */

typedef signed short s16;
typedef signed int s32;
typedef long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

/* d_021B3C50: gate configuration. f0 is a flag shared with the mic callback. */
typedef struct VadCfg {
    volatile u32 f0;
    u32 f4;
    s32 f8;
    s32 fC;
} VadCfg;

/* d_021B4C2C: gate state. */
typedef struct VadState {
    volatile u32 f0;
    u32 f4;
    s32 f8;
} VadState;

/* d_021B4C48: filter state with its ring buffer (buf sits at +0x484). */
struct G_021B4C48 {
    s16 att;
    s16 pad0;
    s32 hp_prev;
    s32 rd;
    s32 wr;
    s32 hp_y;
    s32 c[6];
    s32 x[6];
    u8 pad_44[0x440];
    s16 buf[2048];
};

/* d_021B60CC: session state of the TCV packet receiver. */
struct G_021B60CC {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 fC;
    u8 padD[3];
    void (*fn)(int, int, int, int);
    s32 arg;
    s32 f18;
    s32 f1C;
};
#endif
