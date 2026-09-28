/*
 * unit:     no
 * function: sub_0202C240
 * address:  0x0202C240
 * packet:   pkt_0202BDE8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A plain byte getter at offset 4. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C240.c \
 *       --func sub_0202C240 --addr 0x0202C240 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

u32 sub_0202C240(void *obj)
{
    return *(u8 *)((char *)obj + 4);
}
