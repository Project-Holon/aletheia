/*
 * function: sub_02021B18
 * address:  0x02021B18
 * packet:   pkt_02021B18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * An unlabelled leaf (saves no lr, see docs/idioms/
 * unlabelled-leaf-functions-hide-in-word-runs.md).  Reads the 14-bit field
 * above the low two bits of the halfword at +0x118 and, when it is
 * non-zero, sets the byte at +0x11c to 1.
 *
 * The `lsls #0x10 / lsrs #0x12` pair is the unequal-shift narrowing form
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md):
 * a u16 truncation folded with a >> 2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02021B18.c \
 *       --func sub_02021B18 --addr 0x02021B18 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct Obj02021B18 {
    u8  pad0[0x118];
    u16 lo : 2;
    u16 hi : 14;
    u16 pad11a;
    u8  flag;       /* +0x11c */
};

void sub_02021B18(struct Obj02021B18 *o)
{
    if (o->hi)
        o->flag = 1;
}
