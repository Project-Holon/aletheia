/*
 * function: func_0204B9A0
 * address:  0x0204B9A0
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Blocked at MATCH: all 36 concrete bytes are correct, but the PC24 at +0x001C
 * (the call to func_0204D510) has no witness of any class.  0x0204D510 has
 * exactly one branch reference image wide and it is that call, so no cut frees
 * it; the only unblock is a `matched` entry at 0x0204D510, which sits in
 * pkt_0204D4B0, outside this packet.
 *
 * symbols:
 *   func_0204D410  0x0204D410  arm
 *   func_0204D510  0x0204D510  arm
 *
 * func_0204B95C followed by a restart of the animation.  The actor pointer
 * has to survive the first call, so unlike func_0204B95C this one spends r4
 * and re-materialises `&a->ctl` for the second call.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204B9A0.c \
 *       --func func_0204B9A0 --addr 0x0204B9A0 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Anim {
    u8  pad_00[0x0c];
    u32 flag;   /* 0x0c */
};

struct Ctl {
    u8 pad_00[4];
};

struct Actor {
    u8         pad_00[0x68];
    struct Ctl ctl;   /* 0x68 */
};

extern struct Anim *func_0204D410(struct Ctl *c);
extern void         func_0204D510(struct Ctl *c);

void func_0204B9A0(struct Actor *a)
{
    func_0204D410(&a->ctl)->flag = 1;
    func_0204D510(&a->ctl);
}
