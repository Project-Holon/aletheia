/*
 * function: func_0218A3F4
 * address:  0x0218A3F4
 * packet:   pkt_ov096_0218A3F4
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The apparent register-scheduling residue was a missing third argument:
 *   the image keeps `b` (r1) live and loads the halfword into r2, which is
 *   only possible if the callee takes (field, b, h).  func_02020F20 is
 *   declared with the extra `int` argument and the call passes `b`.
 *   EXACT* because the follower at 0x0218A41A is an unlabelled `movs r0,r0`
 *   pad.
 * symbols:
 *   func_02020F20  0x02020F20  thumb
 *   func_02021014  0x02021014  thumb
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj13672.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_02020F20(int, int, u16);
struct Rec;
extern u32 func_02021014(struct Rec *p, u32 sel);
extern u32 func_020307B0(void *p);

int func_0218A3F4(int a, int b, int c) {
    u16 h;
    int p;
    int q;
    h = ((struct Obj13672 *)a)->fA0;
    p = func_02020F20(((struct Obj13672 *)a)->fA8, b, h);
    q = func_02021014((struct Rec *)p, c);
    func_020307B0((void *)p);
    return q;
}
