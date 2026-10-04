/*
 * function: func_020508EC
 * address:  0x020508EC
 * packet:   pkt_020508EC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj16161.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_020508EC(u8 *p, int i, u16 *out)
{
    u16 v = *(u16 *)(*(u8 * *)&((struct Obj16161 *)p)->f18 + i * 40 + 0x1c);
    *out = v;
    return (u16)(v + 4 + 0xC000) <= 3;
}
