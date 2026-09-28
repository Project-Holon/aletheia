/*
 * function: func_021D77F8
 * address:  0x021D77F8
 * packet:   pkt_021D77F8
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

struct hdr {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    int f4;
};

void func_021D77F8(struct hdr *p, u8 a, u8 b, int c)
{
    p->f0 = p->f0 + 1;
    p->f4 = c;
    p->f1 = 0;
    p->f2 = a;
    p->f3 = b;
}
