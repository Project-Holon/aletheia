/*
 * function: func_02021F08
 * address:  0x02021F08
 * packet:   pkt_02021EE4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An unlabelled leaf (push {r3, r4} for alignment only, no lr save), newly
 * seeded as the follower of sub_02021EE4.  Arms the palette-animation
 * header at +0x118: sets the 2-bit mode field from the low bit of the
 * argument and then turns on all fourteen channel bits above it.
 *
 * The header halfword is the same `a_mode:2, a_big:14` pair func_02021A84
 * and func_02021D50 use.  The two pool words are plain literals, not
 * relocations: 0xFFFF0003 is the a_big clear mask and 0x0000FFFC the
 * all-ones a_big value written back, exactly the `<< 2` bitfield insert.
 *

 * EXACT*: 52 bytes compiled (44 of code plus the two pool words at
 * 0x02021F34/0x02021F38), against a 92-byte inferred extent that runs on
 * into the unlabelled `.word` run before func_02021F64.
 *
 * The `(v & 1)` is narrowed to u16 before the field store (`lsls #0x10 /
 * lsrs #0x10` at +0x10), which is what an `int` argument masked into a
 * 2-bit u16 bitfield produces; a u16 parameter loses the pair.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021F08.c \
 *       --func func_02021F08 --addr 0x02021F08 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct Obj02021F08 {
    u8  pad0[0x118];
    u16 a_mode : 2;
    u16 a_big  : 14;
};

void func_02021F08(struct Obj02021F08 *o, int v)
{
    o->a_mode = (u16)(v & 1);
    o->a_big = 0x3FFF;
}
