/*
 * function: CLACT_ResetOamManagers
 * address:  0x0204BD18
 * packet:   pkt_0204BCF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Blocked at MATCH: all 36 concrete bytes are correct, but the PC24 at
 * +0x0010 (the call to CLACT_ResetOamManager) has no witness of any class.  Its only
 * caller image wide is that call, and that file is itself capped on 0x02063640
 * (316 bytes, pkt_02063640, claimed by lane-C).  Chain capped for this pass.
 *
 * Run CLACT_ResetOamManager over both of a cell actor's 0x20-byte OAM sub-records.
 *
 * symbols:
 *   CLACT_ResetOamManager  0x0204BD7C  arm
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

extern void CLACT_ResetOamManager(struct Sub *s);

void CLACT_ResetOamManagers(struct Obj *o)
{
    int i;

    for (i = 0; i < 2; i++) {
        CLACT_ResetOamManager(&o->w[i]);
    }
}
