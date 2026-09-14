/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0201AA14
 * packet:   pkt_0201A5FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0201AA14, sub_0201AA18
 *
 * Two plain word getters, four bytes each: the object's first word and the
 * word at +4.  Both are called from sub_0201AA1C (0x0201AA1C, still open)
 * and sub_0201AA18 is also called from the unit at 0x0201AC2C, which is
 * where the concrete relocations against it are attested from.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AA14.c \
 *       --addr 0x0201AA14 --thumb
 */

typedef unsigned int u32;

u32 sub_0201AA14(void *p)
{
    return *(u32 *)p;
}

u32 sub_0201AA18(void *p)
{
    return *(u32 *)((char *)p + 4);
}
