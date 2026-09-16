/*
 * function: func_0204BD7C
 * address:  0x0204BD7C
 * packet:   pkt_0204BD64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Blocked at MATCH: all 24 concrete bytes are correct, but the PC24 at +0x0010
 * (the call to func_02063640) has no witness of any class.  0x02063640 has
 * exactly one branch reference image wide and it is that call, so no cut frees
 * it; the only unblock is a `matched` entry at 0x02063640, which sits in the
 * 0x0205F7C8 unit, far outside this packet.
 *
 * symbols:
 *   func_02063640  0x02063640  arm
 *
 * Release one bound 0x20-byte OAM sub-record of a cell actor.  The "bound"
 * flag at +0x1c is the same one func_0204BD3C sets, and an unbound record is
 * an early return predicated onto the compare (`popeq`).
 *
 * The flag value is still in r1 at the call, but it is a leftover, not an
 * argument: wave 24 read 0x02063640 (docs/notes/func_02063640.c.txt) and it
 * overwrites r1 at +0x1C with `ldrh r1, [r5, #8]` before any use, so the
 * callee takes one argument.  The second argument is gone from the call
 * below and the compiled bytes are unchanged, which is the check that the
 * r1 read really was dead.  func_0204BD64 next door hands the same pair to
 * func_0206343C, which has not been read, so that file keeps its two.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204BD7C.c \
 *       --func func_0204BD7C --addr 0x0204BD7C --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub {
    u8  pad_00[0x1c];
    u32 bound;   /* 0x1c */
};

extern void func_02063640(struct Sub *s);

void func_0204BD7C(struct Sub *s)
{
    if (s->bound == 0) {
        return;
    }

    func_02063640(s);
}
