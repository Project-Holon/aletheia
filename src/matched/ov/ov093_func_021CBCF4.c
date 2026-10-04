/*
 * function: func_021CBCF4
 * address:  0x021CBCF4
 * packet:   pkt_ov093_021CBCF4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B873C  0x021B873C  thumb  ov093
 */
#include "../include/Obj09980.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_021B873C(char **p);

u32 func_021CBCF4(u8 *p)
{
    u32 v = func_021B873C(*(char ** *)&((struct Obj09980 *)p)->f4);
    if (v > 600) return 0x1000;
    if (v > 450) return 0xe66;
    if (v > 300) return 0xccd;
    if (v > 150) return 0xb33;
    if (v > 30) return 0x800;
    return 0x4cd;
}
