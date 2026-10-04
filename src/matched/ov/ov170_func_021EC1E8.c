/*
 * function: func_021EC1E8
 * address: 0x021EC1E8
 * packet: pkt_ov170_021EC1E8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020275E4 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02027618 0x02027618 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_02027614 0x02027614 thumb
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj02214.h"
typedef unsigned short u16;

extern unsigned func_020275E4(void);
extern void *func_020490F4(unsigned int id, u16 heap);
extern unsigned func_02027618(void);
extern void *func_0204A6C8(void *, unsigned, int, int, unsigned);
extern unsigned func_02027614(void);
extern void *func_0204ABF0(void *, unsigned, int, unsigned, unsigned);
typedef unsigned int   u32;
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern void *func_0204AF28(void *, unsigned, unsigned, unsigned);
extern void func_02049238(void *);
void func_021EC1E8(char *p)
{
    void *h = func_020490F4(func_020275E4(), 0x4C);
    ((struct Obj02214 *)p)->fA0F8 = func_0204A6C8(h, func_02027618(), 0, 0, 0x4C);
    ((struct Obj02214 *)p)->fA124 = func_0204ABF0(h, func_02027614(), 0, 0x100, 0x4C);
    ((struct Obj02214 *)p)->fA154 = func_0204AF28(h, func_0202761C(2), func_02027620(2), 0x4C);
    func_02049238(h);
}
