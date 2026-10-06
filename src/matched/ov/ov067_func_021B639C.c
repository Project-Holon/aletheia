/*
 * function: func_021B639C
 * address: 0x021B639C
 * packet: pkt_ov067_021B639C
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B691C 0x021B691C thumb ov067
 *   func_021B66FC 0x021B66FC thumb ov067
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj20599.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021B691C(void **p);
extern void func_021B66FC(u32 *p);
extern void func_020307B0(void *p);

void func_021B639C(u8 *p)
{
    u32 i;
    for (i = 0; i < ((struct Obj20599 *)p)->f4; i++)
        func_021B691C((void **)(p + 0x20 + i * 0x38));
    func_021B66FC((u32 *)(p + 0xC));
    func_020307B0(p);
}
