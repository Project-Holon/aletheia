/*
 * function: func_0204BD64
 * address:  0x0204BD64
 * packet:   pkt_0204BCF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Blocked at MATCH: all 24 concrete bytes are correct, but the PC24 at +0x0010
 * (the call to func_0206343C) has no witness of any class.  0x0206343C has
 * exactly one branch reference image wide and it is that call, so no cut frees
 * it; the only unblock is a `matched` entry at 0x0206343C, a 508-byte function
 * in pkt_02063078, claimed by lane-C and far outside this lane.
 *
 * Release one bound 0x20-byte OAM sub-record of a cell actor.  The "bound"
 * flag at +0x1c is the same one func_0204BD3C sets, and an unbound record is
 * an early return predicated onto the compare (`popeq`).
 *
 * symbols:
 *   func_0206343C  0x0206343C  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub {
    u8  pad_00[0x1c];
    u32 bound;   /* 0x1c */
};

struct NNSG2dOamManagerInstance;
extern void func_0206343C(struct NNSG2dOamManagerInstance *pMan, u32 bound);

void func_0204BD64(struct Sub *s)
{
    if (s->bound == 0) {
        return;
    }

    func_0206343C((struct NNSG2dOamManagerInstance *)s, s->bound);
}
