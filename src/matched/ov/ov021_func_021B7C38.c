/*
 * function: func_021B7C38
 * address:  0x021B7C38
 * packet:   pkt_ov021_021B7C38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 */
#include "../include/Obj20055.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef long long s64;

int func_021B7C38(u8 *o)
{
    return (int)(((s64)((struct Obj20055 *)o)->f4C * 0x10000 + 0x800) >> 12);
}
