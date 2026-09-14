/*
 * unit:     no
 * function: sub_0202AEB8
 * address:  0x0202AEB8
 * packet:   pkt_0202AC60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A plain word setter at offset 0xc. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202AEB8.c \
 *       --func sub_0202AEB8 --addr 0x0202AEB8 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

void sub_0202AEB8(void *obj, u32 value)
{
    *(u32 *)((char *)obj + 0xc) = value;
}
