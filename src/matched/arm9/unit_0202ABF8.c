/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202ABF8
 * packet:   pkt_0202A188
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0202ABF8, sub_0202ABFC
 *
 * A getter/setter pair on a word field at offset 8 of the same object, back
 * to back with no gap. Neither function has a relocation.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202ABF8.c \
 *       --addr 0x0202ABF8 --thumb
 */

typedef unsigned int u32;

u32 sub_0202ABF8(void *obj)
{
    return *(u32 *)((char *)obj + 8);
}

void sub_0202ABFC(void *obj, u32 value)
{
    *(u32 *)((char *)obj + 8) = value;
}
