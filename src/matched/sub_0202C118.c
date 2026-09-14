/*
 * unit:     no
 * function: sub_0202C118
 * address:  0x0202C118
 * packet:   pkt_0202BDE8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A constructor-shaped clear: a word, a byte one past it, and two more
 * words. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C118.c \
 *       --func sub_0202C118 --addr 0x0202C118 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

void sub_0202C118(void *obj)
{
    *(u32 *)obj = 0;
    *(u8 *)((char *)obj + 4) = 0;
    *(u32 *)((char *)obj + 8) = 0;
    *(u32 *)((char *)obj + 0xc) = 0;
}
