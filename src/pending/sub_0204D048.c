/*
 * unit:     no
 * function: sub_0204D048
 * address:  0x0204D048
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   sub_0204CFDC  0x0204CFDC  arm
 *   sub_0204B59C  0x0204B59C  arm
 *   sub_0204B5D4  0x0204B5D4  arm
 *   sub_0204B5F4  0x0204B5F4  arm
 *   sub_0204B570  0x0204B570  arm
 *
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
 * PARKED AT MATCH.  Every concrete byte is right.  0x0204B59C is reached
 * from exactly two `bl` sites image-wide, 0x0204D06C and 0x0204D080, and
 * both of them are the two call sites above, so no outside `label` witness
 * exists and no cut can create one: a split that removed this function
 * would remove both sites at once.  The other four callees all resolve.
 * It unsticks when 0x0204B59C is itself decompiled to EXACT and becomes a
 * `matched` witness, or when a second caller turns up in an overlay.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204D048.c \
 *       --func sub_0204D048 --addr 0x0204D048 --cc 1.1p1 --arm
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

extern struct Obj *sub_0204CFDC(void *owner, struct Req *r, void *c, void *d,
                                u16 e);
extern void sub_0204B59C(struct Obj *o, s16 value, u32 axis);
extern void sub_0204B5D4(struct Obj *o, u32 value, u32 axis);
extern void sub_0204B5F4(struct Obj *o, u16 value);
extern void sub_0204B570(struct Obj *o, u16 value);

struct Obj *sub_0204D048(void *owner, struct Req *r, void *c, void *d, u16 e)
{
    struct Obj *o = sub_0204CFDC(owner, r, c, d, e);

    sub_0204B59C(o, r->unk_08, 0);
    sub_0204B59C(o, r->unk_08, 1);
    sub_0204B5D4(o, r->unk_0c, 0);
    sub_0204B5D4(o, r->unk_10, 1);
    sub_0204B5F4(o, r->unk_14);
    sub_0204B570(o, r->unk_16);
    return o;
}
