/*
 * function: func_0204BD64
 * address:  0x0204BD64
 * packet:   pkt_0204BD64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Blocked at MATCH: all 24 concrete bytes are correct, but the PC24 at +0x0010
 * (the call to func_0206343C) has no witness of any class.  0x0206343C has
 * exactly one branch reference image wide and it is that call, so no cut frees
 * it; the only unblock is a `matched` entry at 0x0206343C, which sits in the
 * 0x0205F7C8 unit, far outside this packet.
 *
 * symbols:
 *   func_0206343C  0x0206343C  arm
 *
 * Release one bound 0x20-byte OAM sub-record of a cell actor.  The "bound"
 * flag at +0x1c is the same one func_0204BD3C sets, and an unbound record is
 * an early return predicated onto the compare (`popeq`).
 *
 * The flag value is still in r1 at the call.  It is written here as a second
 * argument rather than a leftover because func_0204BD7C, the identical
 * function next door, hands the same pair to a different callee; if a later
 * decompilation of 0x0206343C shows a one-argument signature, the r1 read is
 * a leftover and this line loses its second argument without changing a byte.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204BD64.c \
 *       --func func_0204BD64 --addr 0x0204BD64 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub {
    u8  pad_00[0x1c];
    u32 bound;   /* 0x1c */
};

extern void func_0206343C(struct Sub *s, u32 bound);

void func_0204BD64(struct Sub *s)
{
    if (s->bound == 0) {
        return;
    }

    func_0206343C(s, s->bound);
}
