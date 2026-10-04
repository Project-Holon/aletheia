/*
 * function: func_021C83A0
 * address: 0x021C83A0
 * packet: pkt_ov093_021C83A0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding follow the 42-byte function.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021C2AF0 0x021C2AF0 thumb ov093
 *   func_021D67E8 0x021D67E8 thumb ov093
 *   func_021D7B10 0x021D7B10 thumb ov093
 */
#include "../include/Obj21119.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021B9934(char *p, int i);
extern int func_021C2AF0(u8 *, u8 *);
extern u16 func_021D67E8(u8 *p);
extern u32 func_021D7B10(u32, u32);
u32 func_021C83A0(u8 *p, int i)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj21119 *)p)->f8, i);
    int b = func_021C2AF0(p, a);
    u32 r = func_021D7B10(func_021D67E8(a), b);
    if (r < 1) r = 1;
    return r;
}
