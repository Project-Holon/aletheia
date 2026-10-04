/*
 * function: func_021BFBA0
 * address:  0x021BFBA0
 * packet:   pkt_021BFBA0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045C04  0x02045C04  arm
 *
 * Addresses are Black-image addresses.
 */

struct Rec;
extern void func_02045C04(struct Rec *rec);

void func_021BFBA0(int *p)
{
    int i;
    for (i = 0; i < 3; i++)
        func_02045C04((struct Rec *)p[i + 3]);
}
