/*
 * function: CLACT_AddActorAnimFrame
 * address:  0x0204B8D4
 * packet:   pkt_0204B454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetAnimSpeed   0x0204D4C4  arm
 *   CLACT_AddAnimFrame   0x0204D3C4  arm
 *
 * Run CLACT_SetAnimSpeed over the sub-object embedded at +0x68 of the
 * 0x0204Bxxx object, then CLACT_AddAnimFrame on it with 0x1000.  The address
 * is recomputed with a second `add r0, r4, #0x68` rather than kept in a
 * register across the call
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 *
 * Was capped at MATCH: CLACT_SetAnimSpeed is called from this one site and
 * nowhere else in the image, so its PC24 had no outside witness, and
 * CLACT_AddAnimFrame resolved fine (label).  0x0204D4C4 is now the lead function
 * of src/matched/unit_0204D4C4.c and this site resolves `matched` against
 * it.  The C in this file is unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_AddActorAnimFrame.c  *       --func CLACT_AddActorAnimFrame --addr 0x0204B8D4 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub {
    u8 unk_00[1];
};

struct Obj {
    u8         pad_00[0x68];
    struct Sub unk_68;
};

extern void CLACT_SetAnimSpeed(struct Obj *o, u32 arg);
extern void *CLACT_AddAnimFrame(struct Obj *o, u32 arg);

void CLACT_AddActorAnimFrame(struct Obj *p, u32 arg)
{
    CLACT_SetAnimSpeed((struct Obj *)(&p->unk_68), arg);
    CLACT_AddAnimFrame((struct Obj *)(&p->unk_68), 0x1000);
}
