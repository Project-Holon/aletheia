/*
 * function: func_021B891C
 * address: 0x021B891C
 * packet: pkt_ov172_021B891C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
#include "../include/Obj24084.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D3F8(u32, u32, u32, u32, u32, u32, u32, u32);
void func_021B891C(int a, char *q, u16 *p)
{
    u32 entry;
    entry = (u32)func_020399A8();
    if (func_0203D3F8(entry, 255, 0x2001, *p + 8, (u32)p, 1, 0, 1) != 0)
        ((struct Obj24084 *)q)->f194 = 1;
}
