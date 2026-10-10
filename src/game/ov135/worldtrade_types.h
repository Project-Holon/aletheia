#ifndef WORLDTRADE_TYPES_H
#define WORLDTRADE_TYPES_H
/* ov135 world trade: types shared by every part of worldtrade_adapter,
 * worldtrade_box and worldtrade_enter. */

#ifndef OV135_BASIC_TYPES
#define OV135_BASIC_TYPES
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#endif

typedef struct {
    void *str;
    int val;
} Item;

typedef struct {
    void **wins;
    u8 pad4[8 - 4];
    u32 cursor;
    u32 up;
    u32 down;
    u8 pad14[0x18 - 0x14];
    void *mgr;
    void *bag;
    void *bank;
    void *msg;
    u8 pad28[0x2C - 0x28];
    u32 x2c;
    Item *items;
    void *num;
    s16 layout;
    s16 start;
    u8 pad3C[0x44 - 0x3C];
    int pos;
    int state;
    u8 pad4C[0x56 - 0x4C];
    s16 page;
    int total;
    u8 pad5C[0x60 - 0x5C];
    u8 flags[0x7A - 0x60];
    u8 last;
    u8 pad7B;
    u8 g[4];
} Menu;

#endif
