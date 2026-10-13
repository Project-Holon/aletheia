/*
 * function: BTL_CALC_PickRandomMoveExcluding
 * address:  0x021D7E44
 * packet:   pkt_ov093_021D7E44
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CALC_ContainsU16  0x021D7E90  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   gBtlCalcWork  0x021F6360  data  ov093
 */

#include "../include/G_Unk021F6360.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern struct Unk021F6360 gBtlCalcWork;
int BTL_CALC_ContainsU16(const u16 *p, u32 n, u32 v);
u32 BTL_CALC_Random(u32 range);

u16 BTL_CALC_PickRandomMoveExcluding(int a, int b)
{
    u16 i;
    u16 n = 0;

    for (i = 1; i < 0x230; i++) {
        if (BTL_CALC_ContainsU16((const u16 *)a, b, i) == 0)
            ((u16 *)gBtlCalcWork.tbl)[n++] = i;
    }
    return ((u16 *)gBtlCalcWork.tbl)[(u16)BTL_CALC_Random(n)];
}
