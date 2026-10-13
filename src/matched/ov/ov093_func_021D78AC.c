/*
 * function: BTL_CALC_Random
 * address:  0x021D78AC
 * packet:   pkt_ov093_021D78AC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBtlCalcWork  0x021F6360  data  ov093
 *   _ull_mul       0x0209C054  arm
 */

#include "../include/G_Unk021F6360.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef unsigned long long u64;

extern struct Unk021F6360 gBtlCalcWork;

u32 BTL_CALC_Random(u32 range)
{
    struct Unk021F6360 *p = &gBtlCalcWork;
    u32 v;

    p->seed = p->mul * p->seed + p->add;
    if (range == 0) {
        v = (u32)(p->seed >> 32);
    } else {
        v = (u32)(((p->seed >> 32) * range) >> 32);
    }
    return v;
}
