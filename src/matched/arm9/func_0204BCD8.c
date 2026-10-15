/*
 * function: CLACT_ExitOamManagers
 * address:  0x0204BCD8
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CLACT_ResetOamManagers  0x0204BD18  arm
 *   CLACT_ApplyOamManagers  0x0204BCF4  arm
 *   NNS_G2dInitOamManagerModule  0x02063078  arm
 *
 * Release both of a cell actor's 0x20-byte OAM sub-records and then flush the
 * hardware tables.  The pair-wise loops live in CLACT_ResetOamManagers and
 * CLACT_ApplyOamManagers; this is only the ordering.
 *
 * The actor pointer is saved in r4 across the first call and restored for the
 * second; the third call takes no argument at all, so r0 still carries
 * CLACT_ApplyOamManagers's return value when it is made.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ExitOamManagers.c \
 *       --func CLACT_ExitOamManagers --addr 0x0204BCD8 --cc 1.1p1 --arm
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

extern void CLACT_ResetOamManagers(struct Obj *o);
extern void CLACT_ApplyOamManagers(struct Obj *o);
extern void NNS_G2dInitOamManagerModule(void);

void CLACT_ExitOamManagers(struct Obj *o)
{
    CLACT_ResetOamManagers(o);
    CLACT_ApplyOamManagers(o);
    NNS_G2dInitOamManagerModule();
}
