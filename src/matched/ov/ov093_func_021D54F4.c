/*
 * unit:     yes
 * function: func_021D54F4, func_021D5528
 * address:  0x021D54F4
 * packet:   pkt_ov093_021D54F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj10048.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Ent {
    u16 h0;
    u16 h1;
    u16 h2;
    u16 h3;
    u8 b8;
    u8 b9;
    u16 hA;
    u8 fC;
    u8 fD;
};

struct Work {
    u8 pad0[0x104];
    struct Ent e[4];
    u8 pad13C[4];
    u8 n140;
};

void func_021D54F4(struct Work *src, struct Work *dst)
{
    u32 i;
    for (i = 0; i < 4; i++) dst->e[i] = src->e[i];
    dst->n140 = src->n140;
}

u16 func_021D5528(u8 *p, int i, u8 *a, u8 *b)
{
    u8 *q = p + i * 14;
    *a = q[0x10c];
    *b = q[0x10d];
    return ((struct Obj10048 *)q)->f10A;
}
