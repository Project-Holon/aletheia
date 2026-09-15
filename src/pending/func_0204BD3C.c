/*
 * function: func_0204BD3C
 * address:  0x0204BD3C
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Blocked at MATCH: all 40 concrete bytes are correct, but the PC24 at +0x0018
 * (the call to func_02063138) has no witness of any class.  0x02063138 has
 * exactly one branch reference image wide and it is that call, so no cut frees
 * it; the only unblock is a `matched` entry at 0x02063138, which sits in the
 * 0x0205F7C8 unit, far outside this packet.
 *
 * symbols:
 *   func_02063138  0x02063138  arm
 *
 * Bind one 0x20-byte OAM sub-record of a cell actor to a span of the
 * hardware table, or release it when the span is empty.  The "bound" flag
 * lives at +0x1c of the sub-record.
 *
 * All four parameters are forwarded unchanged to func_02063138, which is
 * why only r0 is saved: r1, r2 and r3 are still live arguments at the call,
 * not leftovers
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md
 * is the opposite case).  func_02063138 reads r1/r2 as a halfword range and
 * r3 as an index into a 0x540-byte table, so all three are real.
 *
 * The empty-span arm is predicated onto the entry compare (`moveq`/`streq`/
 * `popeq`) because it is an early return whose only statement is the store.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204BD3C.c \
 *       --func func_0204BD3C --addr 0x0204BD3C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub {
    u8  pad_00[0x1c];
    u32 bound;   /* 0x1c */
};

extern void func_02063138(struct Sub *s, u32 base, u32 count, u32 which);

void func_0204BD3C(struct Sub *s, u32 base, u32 count, u32 which)
{
    if (count == 0) {
        s->bound = 0;
        return;
    }

    func_02063138(s, base, count, which);
    s->bound = 1;
}
