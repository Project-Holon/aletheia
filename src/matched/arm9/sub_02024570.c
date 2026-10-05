/*
 * function: sub_02024570
 * address:  0x02024570
 * packet:   pkt_02024344
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * A plain 4-halfword struct copy.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02024570.c \
 *       --func sub_02024570 --addr 0x02024570 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;

struct Rec8 {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
};

void sub_02024570(struct Rec8 *dst, const struct Rec8 *src)
{
    *dst = *src;
}
