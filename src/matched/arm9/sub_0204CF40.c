/*
 * unit:     no
 * function: CLACT_ApplyActorResources
 * address:  0x0204CF40
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorImageProxy  0x0204B784  arm
 *   CLACT_SetActorPaletteProxy  0x0204B728  arm
 *
 * Apply a four-field request to the object: the two words at +4 and +8 go
 * through the setters at 0x0204B784 and 0x0204B728, the two halfwords at +0
 * and +2 are copied straight into the object's +0x5c/+0x5e pair.
 *
 * Both halfwords are loaded before either is stored, which is the ordinary
 * effect of the two loads having no dependence on the stores: reading them
 * one at a time would have interleaved `ldrh`/`strh`.
 *
 * Was capped at MATCH: the PC24 site at +0x1c names 0x0204B728 and this is
 * that address's only branch site anywhere in the image, so `label` has
 * nothing outside the compared range to point at, and the two functions are
 * not contiguous, so no unit can make the site `local` either.  0x0204B728
 * is now EXACT in src/matched/CLACT_SetActorPaletteProxy.c (the blocker there was one
 * `const` on the source pointer of its closing struct assignment, see
 * docs/idioms/const-source-pointer-schedules-the-block-load-first.md), and
 * the site resolves `matched` against it.  The C in this file is unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ApplyActorResources.c \
 *       --func CLACT_ApplyActorResources --addr 0x0204CF40 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Req {
    u16 unk_00;
    u16 unk_02;
    u32 unk_04;
    u32 unk_08;
};

struct Obj {
    u8  pad_00[0x5c];
    u16 unk_5c;
    u16 unk_5e;
};

struct Struct36;
struct Xform;
extern void CLACT_SetActorImageProxy(char *dst, const struct Struct36 *src);
extern void CLACT_SetActorPaletteProxy(struct Obj *o, const struct Xform *m);

void CLACT_ApplyActorResources(struct Obj *o, const struct Req *r)
{
    CLACT_SetActorImageProxy((char *)o, (const struct Struct36 *)r->unk_04);
    CLACT_SetActorPaletteProxy(o, (const struct Xform *)r->unk_08);
    o->unk_5c = r->unk_00;
    o->unk_5e = r->unk_02;
}
