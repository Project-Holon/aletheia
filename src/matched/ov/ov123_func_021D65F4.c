/*
 * function: func_021D65F4
 * address: 0x021D65F4
 * packet: pkt_ov123_021D65F4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_02005624 0x02005624 thumb
 *   func_021D6548 0x021D6548 thumb ov123
 *   func_02024230 0x02024230 thumb
 */
#include "../include/Obj08108.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(unsigned int id, u16 heap);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *);
extern void func_021D6548(void *, u8 *);
typedef signed short   s16;
typedef signed int     s32;
extern void *func_02005624(u32 a, u32 b, u32 c);
extern void func_02024230(s16 *out, u32 count, u16 step, s32 amp);
void func_021D65F4(u8 *p)
{
    void *h;
    h = func_020490F4(143, ((struct Obj08108 *)p)->f43C4);
    func_02049990(h, 22, 3, 0, (u16)((struct Obj08108 *)p)->f4, 0, 0, ((struct Obj08108 *)p)->f43C4);
    func_02049238(h);
    ((struct Obj08108 *)p)->f14 = func_02005624((u32)func_021D6548, (u32)p, 0);
    func_02024230((s16 *)(p + 0x43c8), 192, 0x5b0, 0x1800);
}
