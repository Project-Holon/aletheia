/*
 * function: func_021B7A10
 * address: 0x021B7A10
 * packet: pkt_ov067_021B7A10
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049EF4 0x02049EF4 arm
 *   func_02082A60 0x02082A60 arm
 *   func_020307B0 0x020307B0 arm
 * prototype: 02049EF4 preserves r3 in r5 and forwards it unchanged to
 * 02062B30, which writes through it; use a pointer for the full-word payload.
 */
#include "../include/Obj09863.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02049EF4(void *, u32, u32, void **, u16);
extern void func_02082A60(const void *, void *, int);
extern void func_020307B0(void *);
void func_021B7A10(u8 *p, u32 a, u32 b, u32 c, u32 index)
{
    void *out;
    void *handle;
    handle = func_02049EF4((void *)a, b, c, &out, ((struct Obj09863 *)p)->f98);
    func_02082A60((u8 *)out + 0xc, (*(void ***)(p + 0x40))[index], p[4] * p[5] * 2);
    func_020307B0(handle);
}
