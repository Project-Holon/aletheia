/*
 * unit:     no
 * function: sub_0202C710
 * address:  0x0202C710
 * packet:   pkt_0202C6C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0202C6C4   0x0202C6C4  thumb
 *   func_02005F24  0x02005F24  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *
 * The last of the four open trampoline targets of
 * src/pending/unit_0202C548.c (reached through sub_0202C588's
 * pool-word-and-bx tail call). It scales its second argument by the
 * 0..0x7F fraction sub_0202C6C4 computes and hands the result to
 * func_02005F24 together with the object's u16 at offset 8.
 *
 * What closed it: sub_0202C6C4 is called from exactly one place in the
 * image, the `bl` at 0x0202C716 inside this function, so no cut can give
 * that site an outside witness and the `label` class never had one. An
 * EXACT entry for the callee does, through the `matched` class
 * (docs/MATCHING.md, "The matched class"); src/matched/sub_0202C6C4.c is
 * that entry and this file resolves with no cut at all. Same shape as
 * sub_0202C688 needing src/matched/unit_0202C760.c first.
 *
 * Both this division and the two inside sub_0202C6C4 are signed, so the
 * scale factor is an `int` here rather than the `u32` the state accessor
 * family otherwise uses; written unsigned the relocation names
 * _u32_div_f and the branch lands four kilobytes away
 * (docs/idioms/runtime-helper-reloc.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C710.c \
 *       --func sub_0202C710 --addr 0x0202C710 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Obj0202C710 {
    u32 unk00;
    u16 unk04;
    u16 unk06;
    u16 unk08;
};

extern s32 sub_0202C6C4(struct Obj0202C710 *p);
extern void func_02005F24(u32 a0, u32 a1);

void sub_0202C710(struct Obj0202C710 *p, s32 n)
{
    func_02005F24(p->unk08, n * sub_0202C6C4(p) / 0x7F);
}
