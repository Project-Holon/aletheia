/*
 * function: func_021BAE58
 * address: 0x021BAE58
 * packet: pkt_ov172_021BAE58
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021BB65C 0x021BB65C thumb ov172
 *   func_021BE0B8 0x021BE0B8 thumb ov172
 *   func_021BB54C 0x021BB54C thumb ov172
 *   func_020061E4 0x020061E4 thumb
 */
#include "../include/Obj00024.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;
struct Obj;
extern u32 func_020362DC(void);
extern u32 func_0204B98C(struct Actor *);
extern u16 func_0204B898(struct Obj *);
extern void func_0204B878(struct Obj *, u16);
extern void func_021BB65C(void *ctx, u8 *p, int k);
extern void func_021BE0B8(void *);
extern void func_021BB54C(void *ctx, u8 *p);
extern void func_020061E4(u32 a);
void func_021BAE58(void *p, u8 *q)
{
    if ((func_020362DC() & 1024) && ((struct Obj00024 *)q)->f38 == 0) {
        if (func_0204B98C(*(struct Actor * *)&((struct Obj00024 *)q)->f6C) == 0 ||
            func_0204B898(*(struct Obj * *)&((struct Obj00024 *)q)->f6C) == 1) {
            *(u32 *)&((struct Obj00024 *)q)->f0 = 5;
            q[4] = 0;
            func_021BB65C(p, q, 1);
            func_0204B878(*(struct Obj * *)&((struct Obj00024 *)q)->f6C, 1);
            func_020061E4(1644);
        }
    } else if (func_020362DC() & 2) {
        *(u32 *)&((struct Obj00024 *)q)->f0 = 2;
        func_020061E4(1361);
    }
    if (func_020362DC() & 12) {
        func_021BE0B8(p);
        func_021BB54C(p, q);
        func_020061E4(1647);
    }
}
