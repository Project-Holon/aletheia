/*
 * function: func_021C4B7C
 * address:  0x021C4B7C
 * packet:   pkt_021C4B7C
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

struct pair {
    u16 a;
    u16 b;
};

void func_021C4B7C(char *p, struct pair v)
{
    *(u16 *)(p + 4) = v.a;
    *(u16 *)(p + 6) = v.b;
}
