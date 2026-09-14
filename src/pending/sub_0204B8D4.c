/*
 * function: sub_0204B8D4
 * address:  0x0204B8D4
 * packet:   pkt_0204B454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *    sub_0204D4C4   0x0204D4C4  arm
 *   sub_0204D3C4   0x0204D3C4  arm
 *
 * Run sub_0204D4C4 over the sub-object embedded at +0x68 of the
 * 0x0204Bxxx object, then sub_0204D3C4 on it with 0x1000.  The address
 * is recomputed with a second `add r0, r4, #0x68` rather than kept in a
 * register across the call
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 *
 * Byte-correct, capped at MATCH: sub_0204D4C4 is called from this one
 * site and nowhere else in the image, so its PC24 has no outside witness.
 * sub_0204D3C4 resolves fine (label).  It unsticks when 0x0204D4C4 is
 * itself decompiled to EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204B8D4.c  *       --func sub_0204B8D4 --addr 0x0204B8D4 --cc 1.1p1 --arm
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

extern void sub_0204D4C4(struct Sub *s);
extern void sub_0204D3C4(struct Sub *s, u32 v);

void sub_0204B8D4(struct Obj *p)
{
    sub_0204D4C4(&p->unk_68);
    sub_0204D3C4(&p->unk_68, 0x1000);
}
