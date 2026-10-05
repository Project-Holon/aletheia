/*
 * function: sub_02021EE4
 * address:  0x02021EE4
 * packet:   pkt_02021EE4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * EXACT*: the inferred extent ran to 0x02021F64 because the next function,
 * at 0x02021F08, saves no lr and so carries no label.  0x02021F08 is an
 * unlabelled follower and wants seeding into layout/function_starts.txt.
 *
 * An unlabelled leaf setter (saves no lr).  Writes the top bit of the
 * halfword at +0x11a from the low bit of the argument.  The pool words are
 * plain literals: 0x0000011A (the offset, past the Thumb ldrh immediate
 * reach of +62, see docs/idioms/thumb-immediate-reach-costs-an-adds.md) and
 * 0xFFFF7FFF (the clear mask), neither a relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02021EE4.c \
 *       --func sub_02021EE4 --addr 0x02021EE4 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct Obj02021EE4 {
    u8  pad0[0x11a];
    u16 lo  : 15;
    u16 top : 1;
};

void sub_02021EE4(struct Obj02021EE4 *o, int v)
{
    o->top = (u16)v;
}
