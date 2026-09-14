/*
 * unit:     no
 * function: sub_0202C760
 * address:  0x0202C760
 * packet:   pkt_0202C4CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0202C6B8  0x0202C6B8  thumb
 *
 * A dense switch over the window's state accessor
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md), mapping
 * states 0..3 to a parity flag and anything above 3 to 0. Not itself one
 * of the named callee list, but sub_0202C688's only call to it has no
 * other witness in the image, so it needs its own EXACT entry before
 * sub_0202C688 can resolve.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202C760.c \
 *       --func sub_0202C760 --addr 0x0202C760 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32 sub_0202C6B8(void *p);

u32 sub_0202C760(void *p)
{
    switch (sub_0202C6B8(p)) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 0;
    case 3:
        return 1;
    }
    return 0;
}
