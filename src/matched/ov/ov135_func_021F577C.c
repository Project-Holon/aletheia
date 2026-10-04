/*
 * function: func_021F577C
 * address: 0x021F577C
 * packet: pkt_ov135_021F577C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 */
#include "../include/Obj14160.h"
#include "../include/Obj14161.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
void func_021F577C(u8 *p)
{
    int i;
    u8 *q;
    func_0204B3B4((struct Obj *)(((struct Obj14160 *)p)->fBFC));
    for (i = 0; i < 2; i++) {
        func_0204B3B4((struct Obj *)(*(u32 *)(p + 0xd2c + i * 4)));
    }
    func_0204B3B4((struct Obj *)(((struct Obj14160 *)p)->fBF4));
    for (i = 0; i < 30; i++) {
        q = p + i * 4;
        func_0204B3B4((struct Obj *)(((struct Obj14161 *)q)->fC00));
        func_0204B3B4((struct Obj *)(((struct Obj14161 *)q)->fC78));
    }
    for (i = 0; i < 6; i++) {
        func_0204B3B4((struct Obj *)(*(u32 *)(p + 0xcf0 + i * 4)));
    }
}
