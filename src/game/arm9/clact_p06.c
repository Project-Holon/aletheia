/*
 * file:     clact_p06.c
 * unit:     yes
 * function: sub_0204D048, sub_0204D0C4
 * address:  0x0204D048
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_0204CFDC  0x0204CFDC  arm
 *   sub_0204B59C  0x0204B59C  arm
 *   sub_0204B5D4  0x0204B5D4  arm
 *   sub_0204B5F4  0x0204B5F4  arm
 *   sub_0204B570  0x0204B570  arm
 *   gUnk_020A1394  0x020A1394  data
 *   sub_0204D134   0x0204D134  arm
 */
struct Actor;
struct Req;
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

struct Sub {
    u32 kind;
};

typedef signed int     s32;

extern struct Obj *sub_0204CFDC(void *owner, const struct Req *r, void *c, u32 space,
                                u16 e);
extern void sub_0204B59C(struct Obj *o, s16 value, u32 axis);
extern void sub_0204B5D4(struct Actor *actor, u32 value, u32 which);
extern void sub_0204B5F4(struct Actor *actor, u16 value);
extern void sub_0204B570(struct Actor *actor, u32 value);
extern s32 sub_0204D134(const struct Req *r);
struct Obj *sub_0204D048(void *owner, const struct Req *r, void *c, u32 space, u16 e);
void sub_0204D0C4(struct Sub *s, void *c, u32 e);


/*
 * Build the object with sub_0204CFDC, then apply the six remaining fields
 * of the request to it: two axes share sub_0204B59C and two more share
 * sub_0204B5D4, selected by a trailing 0/1 argument, and the last two are
 * plain halfwords.
 *
 * The fifth argument is forwarded untouched: `ldrh r4, [sp, #0x18]` reads
 * this function's own stack argument (six pushed registers above it) and
 * `str r4, [sp]` writes it straight back out as sub_0204CFDC's, with r0-r3
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
 *   python tools/match.py one --src src/matched/sub_0204D048.c \
 *       --func sub_0204D048 --addr 0x0204D048 --cc 1.1p1 --arm
 */
struct Obj *sub_0204D048(void *owner, const struct Req *r, void *c, u32 space, u16 e)
{
    struct Obj *o = sub_0204CFDC(owner, r, c, space, e);

    sub_0204B59C(o, r->unk_08, 0);
    sub_0204B59C(o, r->unk_08, 1);
    sub_0204B5D4((struct Actor *)o, r->unk_0c, 0);
    sub_0204B5D4((struct Actor *)o, r->unk_10, 1);
    sub_0204B5F4((struct Actor *)o, r->unk_14);
    sub_0204B570((struct Actor *)o, r->unk_16);
    return o;
}

extern void (*const gUnk_020A1394[][3])(struct Sub *s, void *c, u32 e);


/*
 * Constructor for the 0x7c-byte sub-object embedded at +0x68 of the
 * 0x0204Bxxx owner, and the counterpart of the destructor at 0x0204D104:
 * derive the kind tag from the request with sub_0204D134, stamp it into
 * word 0, then run row 6 of the handler table at 0x020A1394 with the object
 * and the two forwarded arguments.
 *
 * The kind stays in ip across the table load and is stored only just before
 * the `blx`, which is the ordinary effect of the store having no consumer:
 * the index is needed for the table load either way, so the store sinks to
 * the last position that still precedes the call.
 *
 * The table is row 6 of the one eight-by-three array based at 0x020A1394;
 * see src/matched/func_0204D324.c for the row map and why the base rather
 * than the row is the relocation's symbol.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D0C4.c \
 *       --func sub_0204D0C4 --addr 0x0204D0C4 --cc 1.1p1 --arm
 */
void sub_0204D0C4(struct Sub *s, void *c, u32 e)
{
    u32 kind = sub_0204D134(c);

    s->kind = kind;
    gUnk_020A1394[6][kind](s, c, e);
}
