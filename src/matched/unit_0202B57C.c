/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202B57C
 * packet:   pkt_0202B4BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0202B57C, sub_0202B580
 *
 * Two word getters, at offsets 0x24 and 0x18, packed into a single 8-byte
 * pair with no gap. Neither has a relocation.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202B57C.c \
 *       --addr 0x0202B57C --thumb
 */

typedef unsigned int u32;

u32 sub_0202B57C(void *obj)
{
    return *(u32 *)((char *)obj + 0x24);
}

u32 sub_0202B580(void *obj)
{
    return *(u32 *)((char *)obj + 0x18);
}
