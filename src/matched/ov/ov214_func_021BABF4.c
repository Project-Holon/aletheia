/*
 * function: func_021BABF4
 * address: 0x021BABF4
 * packet: pkt_ov214_021BABF4
 * region: ov214
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049238 0x02049238 arm
 */
#include "../include/Obj00182.h"

typedef unsigned short u16;

typedef unsigned int   u32;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short);
extern unsigned int func_02049740(void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short);
extern void func_02049238(void *);

void func_021BABF4(int unused, char *p)
{
    void *h = func_020490F4(188, ((struct Obj00182 *)p)->f0);
    func_02049B68(h, 0, 0, 0, 320, ((struct Obj00182 *)p)->f0);
    ((struct Obj00182 *)p)->f2C0 = func_02049740(h, 1, 2, 0, 0, ((struct Obj00182 *)p)->f0);
    func_02049238(h);
}
