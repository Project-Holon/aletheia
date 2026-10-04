/*
 * function: func_021D6404
 * address: 0x021D6404
 * packet: pkt_ov123_021D6404
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_02049238 0x02049238 arm
 *   func_0204AF28 0x0204AF28 arm
 */
#include "../include/Obj00343.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_0201BC3C(void);
typedef signed int     s32;
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02049238(void *);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
void func_021D6404(u8 *p)
{
    void *h;
    h = func_020490F4(7, ((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f28 = (void *)func_0204ACEC(h, func_0201BC3C(), 2, 0, ((struct Obj00343 *)p)->f43C4);
    func_02049238(h);
    h = func_020490F4(143, ((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f5C = (void *)func_0204AF28(h, 14, 27, ((struct Obj00343 *)p)->f43C4);
    func_02049238(h);
}
