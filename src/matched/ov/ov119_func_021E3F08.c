/*
 * function: func_021E3F08
 * address:  0x021E3F08
 * packet:   pkt_ov119_021E3F08
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203FB44  0x0203FB44  arm
 */
#include "../include/Obj00001.h"

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0203FB44(u32 layer, u32 offset, u32 size);

void func_021E3F08(char *p)
{
    u32 v;

    v = ((struct Obj00001 *)p)->f86C;
    if (v != 0)
        func_0203FB44((int)2, (u16)v, (u16)(v >> 16));
    ((struct Obj00001 *)p)->f86C = 0;
}
