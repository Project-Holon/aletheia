/*
 * function: func_021D6BB0
 * address: 0x021D6BB0
 * packet: pkt_ov120_021D6BB0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D698C 0x021D698C thumb ov120
 *   func_021D692C 0x021D692C thumb ov120
 *   func_021D6810 0x021D6810 thumb ov120
 *   func_021D6E84 0x021D6E84 thumb ov120
 *   func_021D6EF4 0x021D6EF4 thumb ov120
 *   func_020490F4 0x020490F4 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj01540.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D698C(u8 *);
extern void func_021D692C(u8 *, int);
extern void func_021D6810(u8 *, int);
extern void func_021D6E84(u8 *);
extern void func_021D6EF4(u8 *, int);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_02049EF4(void *, u32, u32, void **, u16);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049238(void *);
void func_021D6BB0(u8 *p, int n)
{
    void *t;
    func_021D698C(p);
    func_021D692C(p, 8);
    func_021D6810(p, 1);
    t = func_020490F4(144, ((struct Obj01540 *)p)->fF4);
    ((struct Obj01540 *)p)->f120 = func_02049EF4(t, 21, 0, (void **)(p + 0x11c), ((struct Obj01540 *)p)->fF4);
    func_02049BDC(t, 0, 5, 0, 320, 32, ((struct Obj01540 *)p)->fF4);
    func_02049238(t);
    t = func_020490F4(32, ((struct Obj01540 *)p)->fF4);
    func_02049BDC(t, 0, 5, 0, 0, 256, ((struct Obj01540 *)p)->fF4);
    func_02049238(t);
    func_021D6E84(p);
    func_021D6EF4(p, n);
    ((struct Obj01540 *)p)->f100 = 1;
}
