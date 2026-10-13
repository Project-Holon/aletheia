/*
 * function: func_021CBEA8
 * address:  0x021CBEA8
 * packet:   pkt_ov093_021CBEA8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the divide by 6 belongs to the fixed-point multiply's statement
 *           (`x = FX_MUL(x, k) / 6;`); the `>> 12` goes inside the compare.
 *           A separate `q = x / 6;` statement lets the compiler move the
 *           divide after the call, and a separate shift statement moves the
 *           shift before it.
 *
 * symbols:
 *   BTL_MAIN_GetZukanSeenCount  0x021B873C  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 */
#include "../include/Obj09980.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 BTL_MAIN_GetZukanSeenCount(char **p);
extern u32 BTL_CALC_Random(u32 range);

int func_021CBEA8(u8 *p, int x)
{
    u32 v = BTL_MAIN_GetZukanSeenCount(*(char ** *)&((struct Obj09980 *)p)->f4);
    int k;
    if (v > 600) k = 0x2800;
    else if (v > 450) k = 0x2000;
    else if (v > 300) k = 0x1800;
    else if (v > 150) k = 0x1000;
    else if (v > 30) k = 0x800;
    else return 0;
    if (x > 0xff000) x = 0xff000;
    x = (int)(((long long)x * k + 0x800) >> 12) / 6;
    if (BTL_CALC_Random(256) < (u32)(x >> 12))
        return 1;
    return 0;
}
