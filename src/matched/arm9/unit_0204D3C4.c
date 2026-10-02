/*
 * unit:     yes
 * function: sub_0204D3C4
 * address:  0x0204D3C4
 * packet:   pkt_0204D3C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gUnk_020A1394  0x020A1394  data
 *   sub_02064364   0x02064364  arm
 *   sub_020649D4   0x020649D4  arm
 *   sub_0204D3C4   0x0204D3C4  arm
 *   sub_0204D3E0   0x0204D3E0  arm
 *   sub_0204D3F0   0x0204D3F0  arm
 *   sub_0204D400   0x0204D400  arm
 *
 * One more thunk of the family documented in src/matched/func_0204D324.c,
 * plus the three handlers it dispatches to.  The pool word here is
 * 0x020A140C, which func_0204D324.c's row map does not cover: it is
 * 0x020A1394 + 0x78, exactly ten twelve-byte rows past the base, so the
 * handler array runs to at least eleven rows and not the eight that were
 * visible when that file was written.  The stride is the evidence: a 0x78
 * displacement is a whole number of three-pointer rows, and every other thunk
 * in the family lands on one too.
 *
 * Declaring the array as gUnk_020A1394[][3] and writing the row index in the
 * C is what makes this file EXACT rather than MATCH.  The relocation then
 * names the base with a +0x78 addend, and the base is attested `literal` by
 * the pool word at 0x0204D490 (sub_0204D478, row 0), well outside this range.
 * Reading 0x020A140C as a table object in its own right would leave the
 * ABS32 with no witness at all, since that word appears in exactly one pool
 * image-wide, this function's own; see
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * Arity comes from the register pair: kind in r3 and base in r2 is the
 * two-parameter allocation, where the one-parameter spelling would use r2
 * then r1 (compare src/matched/unit_0204D410.c).
 *
 * The three row-10 handlers are tail calls through a pool word rather than
 * plain pointer adjustments, the same form as src/matched/unit_0204D494.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204D3C4.c \
 *       --addr 0x0204D3C4 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Obj {
    u32 kind;
    u8  pad_04[8];
    u8  unk_0c;
};

typedef void *(*DispatchFn)(struct Obj *o, u32 arg);

extern DispatchFn const gUnk_020A1394[][3];

extern void sub_02064364(void *p, s32 frames);
extern void sub_020649D4(void *p, s32 frames);

void *sub_0204D3C4(struct Obj *o, u32 arg)
{
    return gUnk_020A1394[10][o->kind](o, arg);
}

void sub_0204D3E0(struct Obj *o, s32 frames)
{
    sub_02064364(&o->unk_0c, frames);
}

void sub_0204D3F0(struct Obj *o, s32 frames)
{
    sub_02064364(&o->unk_0c, frames);
}

void sub_0204D400(struct Obj *o, s32 frames)
{
    sub_020649D4(&o->unk_0c, frames);
}
