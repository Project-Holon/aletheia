/*
 * function: CLACT_InitOamManagers
 * address:  0x0204BC94
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Blocked at MATCH: all 68 concrete bytes are correct and the call to
 * NNS_G2dInitOamManagerModule resolves off the second call site in
 * src/matched/CLACT_ExitOamManagers.c, but the two PC24 sites at +0x0028 and +0x003C
 * (the calls to CLACT_InitOamManager) have no witness outside this range: those two
 * calls are the only branch references to 0x0204BD3C image wide.  No cut frees
 * them, and src/pending/CLACT_InitOamManager.c cannot supply a `matched` entry
 * because it is itself capped at MATCH by NNSi_G2dReserveOamManagerSpan, a fan-in-1 extern.
 *
 * symbols:
 *   NNS_G2dInitOamManagerModule  0x02063078  arm
 *   CLACT_InitOamManager  0x0204BD3C  arm
 *
 * Bind both of a cell actor's 0x20-byte OAM sub-records to their hardware
 * spans: flush first, then the low record with span (base, count) and
 * selector 0, then the high record with (base2, count2) and selector 1.
 *
 * The fifth parameter is a u8: it arrives on the caller's stack and is read
 * back with `ldrb r2, [sp, #0x18]` past the six-register push, while the
 * third parameter reaches the same argument slot as a plain `mov`.  Widening
 * it to u32 would drop the `ldrb` to an `ldr`.
 *
 * The second sub-record is reached with `add r0, r7, #0x20`, the constant
 * subscript &o->w[1], not a running cursor.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_InitOamManagers.c \
 *       --func CLACT_InitOamManagers --addr 0x0204BC94 --cc 1.1p1 --arm
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

extern void NNS_G2dInitOamManagerModule(void);
extern void CLACT_InitOamManager(char *p, int a, int b, int which);

void CLACT_InitOamManagers(struct Obj *o, u32 base, u32 count, u32 base2, u8 count2)
{
    NNS_G2dInitOamManagerModule();
    CLACT_InitOamManager((char *)(&o->w[0]), base, count, 0);
    CLACT_InitOamManager((char *)(&o->w[1]), base2, count2, 1);
}
