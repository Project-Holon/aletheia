/*
 * function: func_021C4B90
 * address:  0x021C4B90
 * packet:   pkt_021C4B90
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

void func_021C4B90(char *p, struct pair v)
{
    *(u16 *)(p + 8) = v.a;
    *(u16 *)(p + 0xa) = v.b;
}
