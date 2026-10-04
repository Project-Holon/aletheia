/*
 * function: func_021C03C4
 * address: 0x021C03C4
 * packet: pkt_ov208_021C03C4
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: 021C044E..021C0450 is two zero alignment bytes, not a follower.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204B084 0x0204B084 arm
 */
#include "../include/Obj02546.h"
typedef unsigned char u8;
struct Obj;
struct Bank;
extern void func_0204B3B4(struct Obj *);
extern void func_0204AFD8(unsigned);
extern void func_0204A8D4(unsigned);
extern void func_0204ADA4(unsigned);
extern void func_0204B1CC(struct Bank *);
extern void func_0204B084(void *);
void func_021C03C4(void *unused, char *p)
{
    u8 i;
    for (i = 0; i < 7; i++) func_0204B3B4(*(struct Obj **)(p + i * 4 + 0xbc));
    func_0204AFD8(((struct Obj02546 *)p)->fB8);
    func_0204A8D4(((struct Obj02546 *)p)->fB0);
    func_0204ADA4(((struct Obj02546 *)p)->fB4);
    func_0204AFD8(((struct Obj02546 *)p)->fAC);
    func_0204A8D4(((struct Obj02546 *)p)->fA4);
    func_0204ADA4(((struct Obj02546 *)p)->fA8);
    func_0204AFD8(((struct Obj02546 *)p)->fA0);
    func_0204A8D4(((struct Obj02546 *)p)->f98);
    func_0204ADA4(((struct Obj02546 *)p)->f9C);
    func_0204B1CC(*(struct Bank * *)&((struct Obj02546 *)p)->f1D0);
    func_0204B084(((struct Obj02546 *)p)->f1D4);
}
