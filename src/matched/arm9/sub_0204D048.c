/*
 * unit:     no
 * function: CLACT_CreateActorFull
 * address:  0x0204D048
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CLACT_CreateActorCore  0x0204CFDC  arm
 *   CLACT_SetActorAffineOriginAxis  0x0204B59C  arm
 *   CLACT_SetActorScaleAxis  0x0204B5D4  arm
 *   CLACT_SetActorRotation  0x0204B5F4  arm
 *   CLACT_SetActorAffineMode  0x0204B570  arm
 *
 * Build the object with CLACT_CreateActorCore, then apply the six remaining fields
 * of the request to it: two axes share CLACT_SetActorAffineOriginAxis and two more share
 * CLACT_SetActorScaleAxis, selected by a trailing 0/1 argument, and the last two are
 * plain halfwords.
 *
 * The fifth argument is forwarded untouched: `ldrh r4, [sp, #0x18]` reads
 * this function's own stack argument (six pushed registers above it) and
 * `str r4, [sp]` writes it straight back out as CLACT_CreateActorCore's, with r0-r3
 * never disturbed in between.
 *
 * The literals 0 and 1 are each materialised once, into r5 and r4, and
 * reused across four call sites rather than rematerialised per call
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md,
 * the "an argument shares it" case).  The `s16` field at +8 is loaded twice
 * with `ldrsh`, once per call, because the intervening call could have
 * written it.
 *
 * Was parked at MATCH.  0x0204B59C is reached from exactly two `bl` sites
 * image-wide, 0x0204D06C and 0x0204D080, and both of them are the two call
 * sites above, so no outside `label` witness exists and no cut can create
 * one: a split that removed this function would remove both sites at once.
 * The route taken instead was to decompile 0x0204B59C itself, which is the
 * first of three unlabelled leaf accessors now covered by
 * src/matched/unit_0204B59C.c; both sites here resolve `matched` against
 * that entry.  The C in this file is unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_CreateActorFull.c \
 *       --func CLACT_CreateActorFull --addr 0x0204D048 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Obj {
    u8 unk_00[1];
};

struct Req {
    u8   pad_00[8];
    s16  unk_08;
    u8   pad_0a[2];
    u32  unk_0c;
    u32  unk_10;
    u16  unk_14;
    u16  unk_16;
};

extern struct Obj *CLACT_CreateActorCore(void *owner, const struct Req *r, void *c, u32 space,
                                u16 e);
extern void CLACT_SetActorAffineOriginAxis(struct Obj *o, s16 value, u32 axis);
struct Actor;
extern void CLACT_SetActorScaleAxis(struct Actor *actor, u32 value, u32 which);
extern void CLACT_SetActorRotation(struct Actor *actor, u16 value);
struct Actor;
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);

struct Obj *CLACT_CreateActorFull(void *owner, const struct Req *r, void *c, u32 space, u16 e)
{
    struct Obj *o = CLACT_CreateActorCore(owner, r, c, space, e);

    CLACT_SetActorAffineOriginAxis(o, r->unk_08, 0);
    CLACT_SetActorAffineOriginAxis(o, r->unk_08, 1);
    CLACT_SetActorScaleAxis((struct Actor *)o, r->unk_0c, 0);
    CLACT_SetActorScaleAxis((struct Actor *)o, r->unk_10, 1);
    CLACT_SetActorRotation((struct Actor *)o, r->unk_14);
    CLACT_SetActorAffineMode((struct Actor *)o, r->unk_16);
    return o;
}
