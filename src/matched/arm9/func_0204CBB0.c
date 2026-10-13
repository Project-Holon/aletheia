/*
 * function: CLACT_SetupActorDraw
 * address:  0x0204CBB0
 * packet:   pkt_0204CB44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Publishes five bitfields of the element's flag word at +0x60 into the
 * render record: the two-bit mode at bits 18-19 through NNS_G2dSetRndCoreAffineOverwriteMode, the
 * two corner values through NNS_G2dSetRndCoreFlipMode when that mode is zero, then the
 * four-bit value at bits 8-11 into +0x84, bit 24 into +0x90, bits 22-23 into
 * +0x8c and bits 16-17 into +0x88.
 *
 * The +0x84 store is three instructions of arithmetic that computes nothing:
 * `(v | m) & ~(~m)` is `m`, and mwccarm folds every direct spelling of it
 * away.  The cast between the two complements, and the statement boundaries
 * that put the first `mvn` ahead of the `orr`, are what keep all five
 * instructions:
 * docs/idioms/a-cast-between-two-complements-is-what-keeps-both-mvns.md.
 *
 * Decompiled so that it becomes a `matched` witness for the call at
 * 0x0204CB44+0x3c (src/pending/CLACT_DrawActor.c).
 *
 * symbols:
 *   NNS_G2dSetRndCoreAffineOverwriteMode  0x02067AB8  arm
 *   CLACT_GetActorFlip  0x0204B658  arm
 *   NNS_G2dSetRndCoreFlipMode  0x02067B78  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetupActorDraw.c \
 *       --func CLACT_SetupActorDraw --addr 0x0204CBB0 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Elem {
    u8  pad_00[0x60];
    u32 pad_60_0  : 8;
    u32 f_08      : 4;   /* 0x60, bits 8-11  */
    u32 pad_60_1  : 4;
    u32 f_10      : 2;   /* 0x60, bits 16-17 */
    u32 f_12      : 2;   /* 0x60, bits 18-19 */
    u32 pad_60_2  : 2;
    u32 f_16      : 2;   /* 0x60, bits 22-23 */
    u32 f_18      : 1;   /* 0x60, bit 24     */
    u32 pad_60_3  : 7;
};

struct Rec {
    u8  pad_00[0x84];
    u32 unk_84;   /* 0x84 */
    u16 unk_88;   /* 0x88 */
    u16 pad_8a;
    u32 unk_8c;   /* 0x8c */
    u32 unk_90;   /* 0x90 */
};

struct Actor;
struct G2dOamState;
extern void NNS_G2dSetRndCoreAffineOverwriteMode(struct G2dOamState *p, u32 mode);
extern u32 CLACT_GetActorFlip(const struct Actor *actor, u32 which);
extern void NNS_G2dSetRndCoreFlipMode(struct G2dOamState *p, u32 h, u32 v);

void CLACT_SetupActorDraw(struct Elem *e, struct Rec *r)
{
    u32 a, b, v;
    int n;
    u8  m;

    NNS_G2dSetRndCoreAffineOverwriteMode((struct G2dOamState *)r, e->f_12);

    if (e->f_12 == 0) {
        a = CLACT_GetActorFlip((const struct Actor *)e, 0);
        b = CLACT_GetActorFlip((const struct Actor *)e, 1);
        NNS_G2dSetRndCoreFlipMode((struct G2dOamState *)r, b, a);
    }

    m = e->f_08;
    n = ~m;
    v = r->unk_84 | m;
    r->unk_84 = v & ~(u32)n;
    r->unk_90 = e->f_18;
    r->unk_8c = e->f_16;
    r->unk_88 = (u8)e->f_10;
}
