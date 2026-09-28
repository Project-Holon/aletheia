/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x020263D8
 * packet:   pkt_020263D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_020263D8, func_02026400, func_0202640C
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_020264F4  0x020264F4  thumb
 *   func_02026490  0x02026490  thumb
 *
 * game_comm.c, 0x020263D8..0x02026454: start a request, the unlabelled
 * forwarding leaf func_02026400 (func_0202640C(p, 0, 0) as a pool-word tail
 * call), and the request update.  The byte at +4 of the comm object and of
 * its 8-byte sub-object at +0xC is a set of one-bit flags; every clear is a
 * `bics` and every set an `orrs`, which only bitfield stores give
 * (docs/families/game_comm.h).  func_020263D8 clears bit 1 between its two
 * plain stores: f14, bit, f05 is the one order whose flag load lands after
 * the f14 store (the other two schedule the f05 store first).
 *
 * Integrator: seed 0x02026400 (unlabelled follower, member of this unit).
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub {
    u32 f00;
    u8  b0 : 1;
    u8  b1 : 1;
    u8  b2 : 1;
    u8  b3 : 5;
    u8  f05;      /* +0x05 */
    u8  f06;
    u8  f07;
};

struct Comm {
    u32 f00;
    u8  b0 : 1;   /* +0x04 */
    u8  b1 : 1;
    u8  b2 : 1;
    u8  b3 : 5;
    u8  f05;
    u8  f06;
    u8  f07;
    u32 f08;
    struct Sub sub;       /* +0x0C; its state byte is +0x10 */
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
};

extern void func_02082BCC(void *dst, int val, u32 n);
extern void func_020264F4(struct Comm *p);

void func_020263D8(struct Comm *p, u32 a1, u32 a2)
{
    p->f14 = a2;
    p->b1 = 0;
    p->f05 = a1;
    p->f20 = 0;
    p->f1c = 0;
    func_02082BCC(&p->sub, 0, 8);
    func_020264F4(p);
}

void func_0202640C(struct Comm *p, u32 a, u32 b);

void func_02026400(struct Comm *p)
{
    func_0202640C(p, 0, 0);
}

extern void func_02026490(struct Sub *s, u32 state);

void func_0202640C(struct Comm *p, u32 a, u32 b)
{
    if (*((u8 *)&p->sub + 4) == 2) {
        func_02026490(&p->sub, 3);
        p->f20 = a;
        p->f1c = b;
    } else if (*((u8 *)&p->sub + 4) < 2) {
        p->b0 = 1;
        p->f20 = a;
        p->f1c = b;
    } else {
        p->b1 = 1;
        if (p->f20 == 0) {
            p->f20 = a;
            p->f1c = b;
        }
    }
}
