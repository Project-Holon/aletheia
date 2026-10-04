/*
 * function: func_021B89F0
 * address: 0x021B89F0
 * packet: pkt_ov102_021B89F0
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero padding bytes at 021B8A3E.
 * symbols:
 *   func_021B8874 0x021B8874 thumb ov102
 */
#include "../include/Obj05270.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B8874(u32 *);
void func_021B89F0(u8 *p)
{
    int i;
    for (i = 0; i < ((struct Obj05270 *)p)->f34C; i++)
        func_021B8874((u32 *)(p + i * 0x1c));
    if ((((struct Obj05270 *)p)->f348)++ > 30) {
        ((struct Obj05270 *)p)->f348 = 0;
        if (((struct Obj05270 *)p)->f34C < ((struct Obj05270 *)p)->f34E)
            (((struct Obj05270 *)p)->f34C)++;
    }
}
