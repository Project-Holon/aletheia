/*
 * unit:     no
 * function: sub_0202AF30
 * address:  0x0202AF30
 * packet:   pkt_0202AC60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A plain halfword getter at offset 0. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202AF30.c \
 *       --func sub_0202AF30 --addr 0x0202AF30 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

u32 sub_0202AF30(void *obj)
{
    return *(u16 *)obj;
}
