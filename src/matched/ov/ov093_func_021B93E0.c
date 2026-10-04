/*
 * function: func_021B93E0
 * address:  0x021B93E0
 * packet:   pkt_ov093_021B93E0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent 68, compiled 66, trailing padding)
 *
 * symbols:
 *   func_021B9B40  0x021B9B40  thumb  ov093
 */
#include "../include/Obj13278.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void func_021B9B40(void *p);

void func_021B93E0(char *p, u32 a, u32 b)
{
    u32 i;
    u32 j;
    u32 k;

    ((struct Obj13278 *)p)->f0 = a;
    ((struct Obj13278 *)p)->fE4 = b;
    for (i = 0; i < 4; i++)
        func_021B9B40(p + 4 + i * 0x1c);
    for (j = 0; j < 0x18; j++)
        *(u32 *)(p + 0x84 + j * 4) = 0;
    for (k = 0; k < 4; k++)
        *(u32 *)(p + 0x74 + k * 4) = 0;
}
