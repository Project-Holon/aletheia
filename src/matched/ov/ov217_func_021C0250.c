/*
 * function: func_021C0250
 * address: 0x021C0250
 * packet: pkt_ov217_021C0250
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing 00 00 at 021C02A6 is two-byte alignment padding.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj08438.h"
typedef unsigned int u32;
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, u16 heap);
typedef signed int     s32;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern int func_0204ABF0(u32, u32, u32, u32, u16);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);
void func_021C0250(char *p)
{
    u16 heap = ((struct Obj08438 *)p)->f4;
    void *h = func_020490F4(192, heap);
    int a = func_0204A6C8((void *)((u32)h), 15, 0, 1, heap);
    int b = func_0204ABF0((u32)h, 16, 1, 0, heap);
    int c = func_0204AF28((void *)((u32)h), 14, 17, heap);
    ((struct Obj08438 *)p)->f378 = a;
    ((struct Obj08438 *)p)->f37C = b;
    ((struct Obj08438 *)p)->f380 = c;
    func_02049238(h);
}
