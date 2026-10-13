/*
 * function: CLACT_ApplyOamManagers
 * address:  0x0204BCF4
 * packet:   pkt_0204BCF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Blocked at MATCH: all 36 concrete bytes are correct, but the PC24 at
 * +0x0010 (the call to CLACT_ApplyOamManager) has no witness of any class.  Its only
 * caller image wide is that call, so no cut frees it; the unblock is a
 * `matched` entry at 0x0204BD64, and that file is itself capped on 0x0206343C
 * (508 bytes, pkt_02063078, claimed by lane-C).  Chain capped for this pass.
 *
 * Run CLACT_ApplyOamManager over both of a cell actor's 0x20-byte OAM sub-records.
 * CLACT_ResetOamManagers next door is the same loop against CLACT_ResetOamManager.
 *
 * symbols:
 *   CLACT_ApplyOamManager  0x0204BD64  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub {
    u8  pad_00[0x1c];
    u32 bound;   /* 0x1c */
};

struct Obj {
    struct Sub w[2];
};

extern void CLACT_ApplyOamManager(struct Sub *s);

void CLACT_ApplyOamManagers(struct Obj *o)
{
    int i;

    for (i = 0; i < 2; i++) {
        CLACT_ApplyOamManager(&o->w[i]);
    }
}
