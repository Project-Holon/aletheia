/*
 * function: func_021C2260
 * address:  0x021C2260
 * packet:   pkt_ov217_021C2260
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj26021.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

struct Obj;
extern void func_0204B3DC(struct Obj *a, unsigned int b);

void func_021C2260(void *p)
{
    s32 i;
    s32 n = ((struct Obj26021 *)p)->f298;
    for (i = 0; i < n; i++)
        func_0204B3DC((struct Obj *)*(u32 *)((char *)p + 0x3c + i * 0x18), 0);
}
