/*
 * function: CLACT_ResetOamManager
 * address:  0x0204BD7C
 * packet:   pkt_0204BCF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Blocked at MATCH: all 24 concrete bytes are correct, but the PC24 at +0x0010
 * (the call to func_02063640) has no witness of any class.  0x02063640 has
 * exactly one branch reference image wide and it is that call; the only unblock
 * is a `matched` entry at 0x02063640, a 316-byte function in pkt_02063640,
 * claimed by lane-C.
 *
 * Release one bound 0x20-byte OAM sub-record of a cell actor.  The "bound"
 * flag at +0x1c is the same one CLACT_InitOamManager sets, and an unbound record is
 * an early return predicated onto the compare (`popeq`).  The r1 read at the
 * call is a leftover, not an argument: 0x02063640 overwrites r1 at +0x1C with
 * `ldrh r1, [r5, #8]` before any use (docs/notes/func_02063640.c.txt).
 *
 * symbols:
 *   func_02063640  0x02063640  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub {
    u8  pad_00[0x1c];
    u32 bound;   /* 0x1c */
};

struct NNSG2dOamManagerInstance;
extern void func_02063640(struct NNSG2dOamManagerInstance *pMan);

void CLACT_ResetOamManager(struct Sub *s)
{
    if (s->bound == 0) {
        return;
    }

    func_02063640((struct NNSG2dOamManagerInstance *)s);
}
