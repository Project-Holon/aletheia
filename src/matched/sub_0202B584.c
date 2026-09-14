/*
 * unit:     no
 * function: sub_0202B584
 * address:  0x0202B584
 * packet:   pkt_0202B4BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A constructor-shaped clear on a small object: a leading halfword and ten
 * words, all zeroed in address order. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202B584.c \
 *       --func sub_0202B584 --addr 0x0202B584 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

void sub_0202B584(void *obj)
{
    *(u16 *)obj = 0;
    *(u32 *)((char *)obj + 4) = 0;
    *(u32 *)((char *)obj + 8) = 0;
    *(u32 *)((char *)obj + 0xc) = 0;
    *(u32 *)((char *)obj + 0x10) = 0;
    *(u32 *)((char *)obj + 0x14) = 0;
    *(u32 *)((char *)obj + 0x18) = 0;
    *(u32 *)((char *)obj + 0x1c) = 0;
    *(u32 *)((char *)obj + 0x20) = 0;
    *(u32 *)((char *)obj + 0x24) = 0;
}
