/*
 * function: func_021D9BD4
 * address: 0x021D9BD4
 * packet: pkt_ov131_021D9BD4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DB7B8 0x021DB7B8 thumb ov131
 *   func_0204B3B4 0x0204B3B4 arm
 */
#include "../include/Obj05396.h"
typedef unsigned char u8;
extern void func_021DB7B8(void *, void *, u8 *);
struct Obj;
extern void func_0204B3B4(struct Obj *p);
void func_021D9BD4(void *a, u8 *p)
{
    u8 i;
    for (i = 0; i < p[0x2b]; i++)
        func_021DB7B8(a, p, p + 0xb0 + i * 24);
    func_0204B3B4(((struct Obj05396 *)p)->f90);
    func_0204B3B4(((struct Obj05396 *)p)->f94);
    func_0204B3B4(((struct Obj05396 *)p)->f98);
    func_0204B3B4(((struct Obj05396 *)p)->f9C);
    func_0204B3B4(((struct Obj05396 *)p)->fA0);
}
